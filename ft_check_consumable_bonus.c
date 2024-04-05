/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_consumable_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:51:47 by fsariogl          #+#    #+#             */
/*   Updated: 2022/03/24 18:42:43 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/so_long_bonus.h"

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
	if (c == 0)
		ft_close(vars);
	return (c);
}
