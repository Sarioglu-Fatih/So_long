/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:39:53 by fsariogl          #+#    #+#             */
/*   Updated: 2022/03/24 18:45:18 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/so_long_bonus.h"

char	*ft_freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

int	ft_howmany_lines(char *av)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	fd = open(av, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	free(str);
	close(fd);
	return (i);
}

char	**ft_form(char **tab, int c)
{
	int	i;
	int	s;

	i = 0;
	s = 1;
	while (tab[0][i])
		i++;
	c = i;
	i = 0;
	while (tab[s])
	{
		while (tab[s][i])
			i++;
		if (i != c)
		{
			ft_freetab(tab);
			ft_putstrerr("Error\nLa carte doit être rectangulaire\n");
			exit(EXIT_FAILURE);
		}
		i = 0;
		s++;
	}
	return (tab);
}

char	**ft_contour(char **tab, int i, int s, t_vars *vars)
{
	if (tab[s][i] != '1')
	{
		ft_freetab(tab);
		ft_putstrerr("Error\nLes bordures doivent être des obstacles (1)\n");
		exit(EXIT_FAILURE);
	}
	while (tab[s][i + 2] != '\0' && tab[s][i] == '1')
		i++;
	vars->col = i;
	while (tab[s + 1] && tab[s][i] == '1')
		s++;
	vars->line = s;
	while (i > 0 && tab[s][i] == '1')
		i--;
	while (s > 0 && tab[s][i] == '1')
		s--;
	if (s != 0 || i != 0)
	{
		ft_freetab(tab);
		ft_putstrerr("Error\nLes bordures doivent être des obstacles (1)\n");
		exit(EXIT_FAILURE);
	}
	return (tab);
}

char	**ft_content(char **tab, int i, int s)
{
	while (tab[s])
	{
		i = 0;
		while (tab[s][i + 1] != '\0')
		{
			if (tab[s][i] != '0' && tab[s][i] != '1' && tab[s][i] != 'C'
					&& tab[s][i] != 'E' && tab[s][i] != 'P' && tab[s][i] != 'H')
			{
				ft_freetab(tab);
				ft_putstrerr
					("Error\nVeuille mettre uniquement des 0, 1, P, C, E et H\n");
				exit(EXIT_FAILURE);
			}
			i++;
		}
		s++;
	}
	return (tab);
}
