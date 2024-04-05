/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_player_next_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:05:15 by fsariogl          #+#    #+#             */
/*   Updated: 2022/03/24 18:45:36 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/so_long_bonus.h"

t_vars	*ft_get_left_next(t_vars *vars)
{
	if (vars->tab[vars->line][vars->col - 1] == 'E')
	{
		ft_check_consumable(vars);
		vars->exit = 1;
		vars->tab[vars->line][vars->col - 1] = 'A';
	}
	else
		vars->tab[vars->line][vars->col - 1] = 'A';
	return (vars);
}

t_vars	*ft_get_left(t_vars *vars)
{
	if (vars->over == 0)
	{
		vars->move++;
		if (vars->exit == 1)
		{
			vars->exit = 0;
			vars->tab[vars->line][vars->col] = 'E';
		}
		else
			vars->tab[vars->line][vars->col] = '0';
		if (ft_find_next_c(vars, "TFGH", vars->line, vars->col - 1) == 1)
		{
			vars->tab[vars->line][vars->col - 1] = 'Z';
			ft_put_all_img(vars);
			vars->over = 1;
		}
		else
			ft_get_left_next(vars);
	}
	return (vars);
}

t_vars	*ft_get_right_next(t_vars *vars)
{
	if (vars->tab[vars->line][vars->col + 1] == 'E')
	{
		ft_check_consumable(vars);
		vars->exit = 1;
		vars->tab[vars->line][vars->col + 1] = 'D';
	}
	else
		vars->tab[vars->line][vars->col + 1] = 'D';
	return (vars);
}

t_vars	*ft_get_right(t_vars *vars)
{
	if (vars->over == 0)
	{
		vars->move++;
		if (vars->exit == 1)
		{
			vars->exit = 0;
			vars->tab[vars->line][vars->col] = 'E';
		}
		else
			vars->tab[vars->line][vars->col] = '0';
		if (ft_find_next_c(vars, "TFGH", vars->line, vars->col + 1) == 1)
		{
			vars->tab[vars->line][vars->col + 1] = 'Z';
			ft_put_all_img(vars);
			vars->over = 1;
		}
		else
			ft_get_right_next(vars);
	}
	return (vars);
}
