/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putimg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:33:34 by fsariogl          #+#    #+#             */
/*   Updated: 2022/03/24 18:30:56 by fsariogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/so_long_bonus.h"

void	ft_putimg3(t_vars *vars, char c, int i, int j)
{
	int	co;
	int	l;

	co = (vars->col_max / 2 - 1) * 100 + 50;
	l = (vars->line_max / 2) * 100;
	vars->img_width = 100;
	vars->img_height = 100;
	if (c == 'Z')
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->pceg[3],
			vars->img_width * i, vars->img_height * j);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->pceg[0],
			vars->img_width * i, vars->img_height * j);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->pceg[8],
			vars->img_width * i, vars->img_height * j);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->pceg[12],
			co, l);
		vars->exit = 1;
	}
}

void	ft_putimg2(t_vars *vars, char c, int i, int j)
{
	if (vars->over == 0)
	{
		if (c == '1')
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->pceg[4],
				vars->img_width * i, vars->img_height * j);
		else if (c == 'H')
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->pceg[11],
				vars->img_width * i, vars->img_height * j);
		else if (c == 'G')
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->pceg[10],
				vars->img_width * i, vars->img_height * j);
		else if (c == 'F')
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->pceg[9],
				vars->img_width * i, vars->img_height * j);
		else if (c == 'T')
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->pceg[8],
				vars->img_width * i, vars->img_height * j);
		else if (c == 'E')
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->pceg[2],
				vars->img_width * i, vars->img_height * j);
	}
	ft_putimg3(vars, c, i, j);
}

void	ft_putimg(t_vars *vars, char c, int i, int j)
{
	if (vars->over == 0)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->pceg[3],
			vars->img_width * i, vars->img_height * j);
		if ((c == 'S' || c == 'W' || c == 'A' || c == 'D') && vars->exit == 1)
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->pceg[2],
				vars->img_width * i, vars->img_height * j);
		if (c == 'S' || c == 'P')
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->pceg[0],
				vars->img_width * i, vars->img_height * j);
		else if (c == 'W')
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->pceg[5],
				vars->img_width * i, vars->img_height * j);
		else if (c == 'A')
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->pceg[6],
				vars->img_width * i, vars->img_height * j);
		else if (c == 'D')
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->pceg[7],
				vars->img_width * i, vars->img_height * j);
		else if (c == 'C')
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->pceg[1],
				vars->img_width * i, vars->img_height * j);
	}
	ft_putimg2(vars, c, i, j);
}

void	ft_asset_next(t_vars *vars)
{
	vars->pceg[11] = mlx_xpm_file_to_image(vars->mlx, "assets_bonus/hright.xpm",
			&vars->img_width, &vars->img_height);
	vars->pceg[12] = mlx_xpm_file_to_image(vars->mlx,
			"assets_bonus/gameover.xpm", &vars->img_width, &vars->img_height);
}

void	ft_asset(t_vars *vars)
{
	vars->pceg[0] = mlx_xpm_file_to_image(vars->mlx, "assets_bonus/down.xpm",
			&vars->img_width, &vars->img_height);
	vars->pceg[1] = mlx_xpm_file_to_image(vars->mlx,
			"assets_bonus/consumable.xpm", &vars->img_width, &vars->img_height);
	vars->pceg[2] = mlx_xpm_file_to_image(vars->mlx, "assets_bonus/exit.xpm",
			&vars->img_width, &vars->img_height);
	vars->pceg[3] = mlx_xpm_file_to_image(vars->mlx, "assets_bonus/grass.xpm",
			&vars->img_width, &vars->img_height);
	vars->pceg[4] = mlx_xpm_file_to_image(vars->mlx, "assets_bonus/obs0.xpm",
			&vars->img_width, &vars->img_height);
	vars->pceg[5] = mlx_xpm_file_to_image(vars->mlx, "assets_bonus/up.xpm",
			&vars->img_width, &vars->img_height);
	vars->pceg[6] = mlx_xpm_file_to_image(vars->mlx, "assets_bonus/left.xpm",
			&vars->img_width, &vars->img_height);
	vars->pceg[7] = mlx_xpm_file_to_image(vars->mlx, "assets_bonus/right.xpm",
			&vars->img_width, &vars->img_height);
	vars->pceg[8] = mlx_xpm_file_to_image(vars->mlx, "assets_bonus/hup.xpm",
			&vars->img_width, &vars->img_height);
	vars->pceg[9] = mlx_xpm_file_to_image(vars->mlx, "assets_bonus/hleft.xpm",
			&vars->img_width, &vars->img_height);
	vars->pceg[10] = mlx_xpm_file_to_image(vars->mlx, "assets_bonus/hdown.xpm",
			&vars->img_width, &vars->img_height);
	ft_asset_next(vars);
}
