/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_consumable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:51:47 by fsariogl          #+#    #+#             */
/*   Updated: 2022/03/24 18:45:00 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	ft_check_consumable(t_vars *vars)
{
	int	c;
	int	col;
	int	line;

	c = 0;
	line = 0;
	while (vars->tab[line])
	{
		col = 0;
		while (vars->tab[line][col])
		{
			if (vars->tab[line][col] == 'C')
				c++;
			col++;
		}
		line++;
	}
	return (c);
}
