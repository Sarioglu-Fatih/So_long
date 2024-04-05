/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:52:25 by fsariogl          #+#    #+#             */
/*   Updated: 2022/03/25 14:36:43 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

t_vars	*ft_pos_player(t_vars *vars)
{
	int	l;
	int	c;

	l = 0;
	c = 0;
	while (vars->tab[l][c] != 'P' && vars->tab[l][c] != 'X')
	{
		c = 0;
		while ((vars->tab[l][c] != 'P' && vars->tab[l][c] != 'X')
				&& vars->tab[l][c])
			c++;
		if (vars->tab[l][c] == 'P' || vars->tab[l][c] == 'X')
		{
			vars->col = c;
			vars->line = l;
			return (vars);
		}
		l++;
	}
	return (vars);
}

t_vars	*ft_get_up(t_vars *vars)
{
	vars->move++;
	ft_putnbr(vars->move);
	ft_putchar('\n');
	if (vars->tab[vars->line][vars->col] == 'X')
	{
		vars->tab[vars->line][vars->col] = 'E';
		if (vars->tab[vars->line - 1][vars->col] == 'E')
			vars->tab[vars->line - 1][vars->col] = 'X';
		else
			vars->tab[vars->line - 1][vars->col] = 'P';
		return (vars);
	}
	if (vars->tab[vars->line - 1][vars->col] == 'E')
	{
		if (ft_check_consumable(vars) == 0)
			ft_open_close_window(vars, 0);
		vars->tab[vars->line - 1][vars->col] = 'X';
	}
	else
		vars->tab[vars->line - 1][vars->col] = 'P';
	vars->tab[vars->line][vars->col] = '0';
	return (vars);
}

t_vars	*ft_get_left(t_vars *vars)
{
	vars->move++;
	ft_putnbr(vars->move);
	ft_putchar('\n');
	if (vars->tab[vars->line][vars->col] == 'X')
	{
		vars->tab[vars->line][vars->col] = 'E';
		if (vars->tab[vars->line][vars->col - 1] == 'E')
			vars->tab[vars->line][vars->col - 1] = 'X';
		else
			vars->tab[vars->line][vars->col - 1] = 'P';
		return (vars);
	}
	if (vars->tab[vars->line][vars->col - 1] == 'E')
	{
		if (ft_check_consumable(vars) == 0)
			ft_open_close_window(vars, 0);
		vars->tab[vars->line][vars->col - 1] = 'X';
	}
	else
		vars->tab[vars->line][vars->col - 1] = 'P';
	vars->tab[vars->line][vars->col] = '0';
	return (vars);
}

t_vars	*ft_get_down(t_vars *vars)
{
	vars->move++;
	ft_putnbr(vars->move);
	ft_putchar('\n');
	if (vars->tab[vars->line][vars->col] == 'X')
	{
		vars->tab[vars->line][vars->col] = 'E';
		if (vars->tab[vars->line + 1][vars->col] == 'E')
			vars->tab[vars->line + 1][vars->col] = 'X';
		else
			vars->tab[vars->line + 1][vars->col] = 'P';
		return (vars);
	}
	if (vars->tab[vars->line + 1][vars->col] == 'E')
	{
		if (ft_check_consumable(vars) == 0)
			ft_open_close_window(vars, 0);
		vars->tab[vars->line + 1][vars->col] = 'X';
	}
	else
		vars->tab[vars->line + 1][vars->col] = 'P';
	vars->tab[vars->line][vars->col] = '0';
	return (vars);
}

t_vars	*ft_get_right(t_vars *vars)
{
	vars->move++;
	ft_putnbr(vars->move);
	ft_putchar('\n');
	if (vars->tab[vars->line][vars->col] == 'X')
	{
		vars->tab[vars->line][vars->col] = 'E';
		if (vars->tab[vars->line][vars->col + 1] == 'E')
			vars->tab[vars->line][vars->col + 1] = 'X';
		else
			vars->tab[vars->line][vars->col + 1] = 'P';
		return (vars);
	}
	if (vars->tab[vars->line][vars->col + 1] == 'E')
	{
		if (ft_check_consumable(vars) == 0)
			ft_open_close_window(vars, 0);
		vars->tab[vars->line][vars->col + 1] = 'X';
	}
	else
		vars->tab[vars->line][vars->col + 1] = 'P';
	vars->tab[vars->line][vars->col] = '0';
	return (vars);
}
