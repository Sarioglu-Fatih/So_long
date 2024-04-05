/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:41:05 by fsariogl          #+#    #+#             */
/*   Updated: 2022/03/11 14:41:38 by fsariogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int ac, char *av[])
{
	t_vars	vars;

	vars.line = 0;
	vars.col = 0;
	vars.move = 0;
	ft_parsing_param(ac, av);
	parsing(&vars, av[1]);
	ft_open_close_window(&vars, 1);
	ft_asset(&vars);
	ft_put_all_img(&vars);
	mlx_key_hook(vars.mlx_win, ft_command, &vars);
	mlx_hook(vars.mlx_win, 17, 0, ft_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
