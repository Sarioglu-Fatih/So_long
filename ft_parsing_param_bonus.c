/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_param_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:00:07 by fsariogl          #+#    #+#             */
/*   Updated: 2022/03/25 14:27:40 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/so_long_bonus.h"

int	ft_atoi(char *str)
{
	int		i;
	char	*s;
	int		signe;
	int		nb;

	i = 0;
	signe = 1;
	s = (char *)str;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '-')
		signe = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	nb = 0;
	while (s[i] != '\0' && s[i] >= '0' && s[i] <= '9')
	{
		nb = ((nb * 10) + s[i]) - '0';
		i++;
	}
	return (nb * signe);
}

void	ft_parsing_param(int ac, char **av, t_vars *vars)
{
	int	i;

	i = 0;
	if (ac >= 2)
	{
		while (av[1][i + 1])
		{
			i++;
		}
		if (ac >= 3)
			vars->speed = ft_atoi(av[2]);
		if (i >= 3)
		{
			if (av[1][i - 3] == '.' && av[1][i - 2] == 'b'
					&& av[1][i - 1] == 'e' && av[1][i] == 'r')
				return ;
		}
		ft_putstrerr("Error\nLe nom de la carte doit finir par .ber");
	}
	else
		ft_putstrerr("Error\nVeuillez mettre le nom d'une carte .ber");
	exit(EXIT_FAILURE);
}
