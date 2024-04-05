/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:21:51 by fsariogl          #+#    #+#             */
/*   Updated: 2022/03/14 16:40:40 by fsariogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	parsing(t_vars *vars, char *str)
{
	int		l;
	char	**tab;

	l = ft_howmany_lines(str);
	if (l <= 2)
	{
		ft_putstrerr("Error\nVotre carte doit être plus grande");
		exit(EXIT_FAILURE);
	}
	tab = ft_gettab(l, vars, str);
	l = 0;
	vars->line_max = vars->line;
	vars->col_max = vars->col;
	if (tab)
		vars->tab = tab;
	else
		exit(EXIT_FAILURE);
}

void	ft_open_close_window(t_vars *vars, int nb)
{
	if (nb == 1)
	{
		vars->mlx = mlx_init();
		vars->mlx_win = mlx_new_window(vars->mlx, vars->col * 100 + 100,
				vars->line * 100 + 100, "so_long");
	}
	else
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		ft_freetab(vars->tab);
		exit(EXIT_SUCCESS);
	}
}	

int	ft_command(int keycode, t_vars *vars)
{
	vars = ft_pos_player(vars);
	if (keycode == 53)
		ft_open_close_window(vars, 0);
	else if (keycode == 13 && vars->tab[vars->line - 1][vars->col] != '1')
		vars = ft_get_up(vars);
	else if (keycode == 0 && vars->tab[vars->line][vars->col - 1] != '1')
		vars = ft_get_left(vars);
	else if (keycode == 1 && vars->tab[vars->line + 1][vars->col] != '1')
		vars = ft_get_down(vars);
	else if (keycode == 2 && vars->tab[vars->line][vars->col + 1] != '1')
		vars = ft_get_right(vars);
	ft_put_all_img(vars);
	return (0);
}

void	ft_put_all_img(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j <= vars->line_max && i <= vars->col_max)
	{
		while (i <= vars->col_max)
		{
			ft_putimg(vars, vars->tab[j][i], i, j);
			i++;
		}
		i = 0;
		j++;
	}
}

int	ft_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	ft_freetab(vars->tab);
	exit(EXIT_SUCCESS);
}
