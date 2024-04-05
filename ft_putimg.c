/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putimg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:33:34 by fsariogl          #+#    #+#             */
/*   Updated: 2022/03/11 17:29:59 by fsariogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	ft_putimg(t_vars *vars, char c, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->pceg[3],
		vars->img_width * i, vars->img_height * j);
	if (c == 'P')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->pceg[0],
			vars->img_width * i, vars->img_height * j);
	else if (c == 'C')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->pceg[1],
			vars->img_width * i, vars->img_height * j);
	else if (c == 'E')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->pceg[2],
			vars->img_width * i, vars->img_height * j);
	else if (c == '1')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->obs,
			vars->img_width * i, vars->img_height * j);
	else if (c == 'X')
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->pceg[2],
			vars->img_width * i, vars->img_height * j);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->pceg[0],
			vars->img_width * i, vars->img_height * j);
	}
}

void	ft_asset_next(t_vars *vars)
{
	vars->pceg[0] = mlx_xpm_file_to_image(vars->mlx, vars->pcega[0],
			&vars->img_width, &vars->img_height);
	vars->pceg[1] = mlx_xpm_file_to_image(vars->mlx, vars->pcega[1],
			&vars->img_width, &vars->img_height);
	vars->pceg[2] = mlx_xpm_file_to_image(vars->mlx, vars->pcega[2],
			&vars->img_width, &vars->img_height);
	vars->pceg[3] = mlx_xpm_file_to_image(vars->mlx, vars->pcega[3],
			&vars->img_width, &vars->img_height);
	vars->obs = mlx_xpm_file_to_image(vars->mlx, vars->obsa,
			&vars->img_width, &vars->img_height);
}

void	ft_asset(t_vars *vars)
{
	vars->pcega[0] = "assets/player.xpm";
	vars->pcega[1] = "assets/consumable.xpm";
	vars->pcega[2] = "assets/exit.xpm";
	vars->pcega[3] = "assets/grass.xpm";
	vars->obsa = "assets/obs0.xpm";
	ft_asset_next(vars);
}
