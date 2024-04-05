/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:52:25 by fsariogl          #+#    #+#             */
/*   Updated: 2022/03/24 18:45:34 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/so_long_bonus.h"

t_vars	*ft_pos_player(t_vars *vars)
{
	int		l;
	int		c;

	l = 0;
	while (vars->tab[l])
	{
		c = 0;
		while (ft_find_next_c(vars, "WASDP", l, c) == 0 && vars->tab[l][c + 1]
				!= '\n')
		{
			c++;
			if (ft_find_next_c(vars, "WASDP", l, c) == 1)
			{
				vars->col = c;
				vars->line = l;
				return (vars);
			}
		}
		l++;
	}
	return (vars);
}

t_vars	*ft_get_up_next(t_vars *vars)
{
	if (vars->tab[vars->line - 1][vars->col] == 'E')
	{
		ft_check_consumable(vars);
		vars->exit = 1;
		vars->tab[vars->line - 1][vars->col] = 'W';
	}
	else
		vars->tab[vars->line - 1][vars->col] = 'W';
	return (vars);
}

t_vars	*ft_get_up(t_vars *vars)
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
		if (ft_find_next_c(vars, "TFGH", vars->line - 1, vars->col) == 1)
		{
			vars->tab[vars->line - 1][vars->col] = 'Z';
			ft_put_all_img(vars);
			vars->over = 1;
		}
		else
			ft_get_up_next(vars);
	}
	return (vars);
}

t_vars	*ft_get_down_next(t_vars *vars)
{
	if (vars->tab[vars->line + 1][vars->col] == 'E')
	{
		ft_check_consumable(vars);
		vars->exit = 1;
		vars->tab[vars->line + 1][vars->col] = 'S';
	}
	else
		vars->tab[vars->line + 1][vars->col] = 'S';
	return (vars);
}

t_vars	*ft_get_down(t_vars *vars)
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
		if (ft_find_next_c(vars, "TFGH", vars->line + 1, vars->col) == 1)
		{
			vars->tab[vars->line + 1][vars->col] = 'Z';
			ft_put_all_img(vars);
			vars->over = 1;
		}
		else
			ft_get_down_next(vars);
	}
	return (vars);
}
