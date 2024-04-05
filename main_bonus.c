/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:37:43 by fsariogl          #+#    #+#             */
/*   Updated: 2022/03/24 18:46:01 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/so_long_bonus.h"

int	main(int ac, char *av[])
{
	t_vars	vars;

	vars.line = 0;
	vars.col = 0;
	vars.move = 0;
	vars.exit = 0;
	vars.over = 0;
	ft_parsing_param(ac, av, &vars);
	parsing(&vars, av[1]);
	ft_open_close_window(&vars, 1);
	ft_asset(&vars);
	ft_put_all_img(&vars);
	mlx_loop_hook(vars.mlx, ft_pos_hostile, &vars);
	mlx_key_hook(vars.mlx_win, ft_command, &vars);
	mlx_hook(vars.mlx_win, 17, 0, ft_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
