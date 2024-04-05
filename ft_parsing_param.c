/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_param.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:00:07 by fsariogl          #+#    #+#             */
/*   Updated: 2022/03/25 14:27:27 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	ft_parsing_param(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac >= 2)
	{
		while (av[1][i + 1])
		{
			i++;
		}
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
