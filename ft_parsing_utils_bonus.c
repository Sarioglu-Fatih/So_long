/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:41:02 by fsariogl          #+#    #+#             */
/*   Updated: 2022/03/25 15:37:24 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/so_long_bonus.h"

void	ft_putstrerr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

char	**ft_check_duplicates(char **tab, int player, int col, int line)
{
	while (tab[line])
	{
		col = 0;
		while (tab[line][col])
		{
			if (tab[line][col] == 'P' && player > 0)
				tab[line][col] = '0';
			if (tab[line][col] == 'P')
				player++;
			col++;
		}
		line++;
	}
	return (tab);
}

char	**ft_contentpce(char **tab, int *pce, int i, int s)
{
	while (tab[s])
	{
		i = 0;
		while (tab[s][i] != '\0')
		{
			if (tab[s][i] == 'P')
				pce[0]++;
			if (tab[s][i] == 'C')
				pce[1]++;
			if (tab[s][i] == 'E')
				pce[2]++;
			i++;
		}
		s++;
	}
	if (pce[0] < 1 || pce[1] < 1 || pce[2] < 1)
	{
		ft_freetab(tab);
		ft_putstrerr("Error\nVeuillez mettre au moins un P, un C et un E\n");
		exit(EXIT_FAILURE);
	}
	return (ft_check_duplicates(tab, 0, 0, 0));
}

char	**ft_checkmap(char **tab, t_vars *vars)
{
	int	pce[3];

	pce[0] = 0;
	pce[1] = 0;
	pce[2] = 0;
	if (!ft_form(tab, 0))
		return (NULL);
	if (!ft_contour(tab, 0, 0, vars))
		return (NULL);
	if (!ft_content(tab, 0, 0))
		return (NULL);
	if (!ft_contentpce(tab, pce, 0, 0))
		return (NULL);
	return (tab);
}

char	**ft_gettab(int nb, t_vars *vars, char *av)
{
	int		i;
	int		fd;
	int		col;
	char	**tab;

	i = 0;
	col = 0;
	tab = (char **)malloc(sizeof(char *) * (nb + 1));
	if (!tab)
		return (NULL);
	fd = open(av, O_RDONLY);
	tab[0] = get_next_line(fd);
	while (tab[i] != NULL)
		tab[++i] = get_next_line(fd);
	tab[i] = NULL;
	while (tab[i - 1][col])
		col++;
	if (col <= 3)
	{
		ft_freetab(tab);
		ft_putstrerr("Error\nVotre carte doit être plus grande\n");
		ft_putstrerr("et ne doit pas contenir de retourn à la ligne inutile");
		exit(EXIT_FAILURE);
	}
	return (ft_checkmap(tab, vars));
}
