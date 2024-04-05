/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_hostile_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:00:35 by fsariogl          #+#    #+#             */
/*   Updated: 2022/03/24 18:45:31 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/so_long_bonus.h"

int	ft_pos_hostile(t_vars *vars)
{
	int		l;
	int		c;

	l = 0;
	c = 0;
	while (vars->tab[l] != NULL)
	{
		c = 0;
		while (vars->tab[l][c] != '\0')
		{
			if (ft_find_next_c(vars, "TFGH", l, c) == 1)
			{
				vars->col = c;
				vars->line = l;
				ft_hostile_move(vars);
			}
			c++;
		}
		l++;
	}
	ft_put_all_img(vars);
	return (1);
}

t_vars	*ft_hget_up(t_vars *vars)
{
	if (vars->over == 0)
	{
		vars->tab[vars->line][vars->col] = '0';
		if (vars->tab[vars->line - 1][vars->col] != '0')
		{
			vars->tab[vars->line - 1][vars->col] = 'Z';
			ft_put_all_img(vars);
			vars->over = 1;
		}
		else
		{
			vars->tab[vars->line - 1][vars->col] = 'T';
			ft_put_all_img(vars);
		}
	}
	return (vars);
}

t_vars	*ft_hget_down(t_vars *vars)
{
	if (vars->over == 0)
	{
		vars->tab[vars->line][vars->col] = '0';
		if (vars->tab[vars->line + 1][vars->col] != '0')
		{
			vars->tab[vars->line + 1][vars->col] = 'Z';
			ft_put_all_img(vars);
			vars->over = 1;
		}
		else
		{
			vars->tab[vars->line + 1][vars->col] = 'G';
			ft_put_all_img(vars);
		}
	}
	return (vars);
}

t_vars	*ft_hget_left(t_vars *vars)
{
	if (vars->over == 0)
	{
		vars->tab[vars->line][vars->col] = '0';
		if (vars->tab[vars->line][vars->col - 1] != '0')
		{
			vars->tab[vars->line][vars->col - 1] = 'Z';
			ft_put_all_img(vars);
			vars->over = 1;
		}
		else
		{
			vars->tab[vars->line][vars->col - 1] = 'F';
			ft_put_all_img(vars);
		}
	}
	return (vars);
}

t_vars	*ft_hget_right(t_vars *vars)
{
	if (vars->over == 0)
	{
		vars->tab[vars->line][vars->col] = '0';
		if (vars->tab[vars->line][vars->col + 1] != '0')
		{
			vars->tab[vars->line][vars->col + 1] = 'Z';
			ft_put_all_img(vars);
			vars->over = 1;
		}
		else
		{
			vars->tab[vars->line][vars->col + 1] = 'H';
			ft_put_all_img(vars);
		}
	}
	return (vars);
}
