/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hostile_next_move_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:53:50 by fsariogl          #+#    #+#             */
/*   Updated: 2022/03/24 18:45:11 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/so_long_bonus.h"

int	ft_random_nb(void)
{
	int		fd;
	int		nb;
	char	*str;

	fd = open("/dev/urandom", O_RDONLY);
	str = get_next_line(fd);
	nb = str[0] % 3 + 3;
	close(fd);
	free(str);
	return (nb);
}

void	ft_hostile_move(t_vars *vars)
{
	int			random;
	int			move;
	static int	deplacement = 0;

	if (!vars->speed)
		vars->speed = 30;
	if (deplacement == vars->speed)
	{
		random = ft_random_nb();
		move = ft_find_c(vars, "0WASD", random);
		if (random == 4 && move == 1)
			ft_hget_up(vars);
		else if (random == 1 && move == 1)
			ft_hget_down(vars);
		else if (random == 2 && move == 1)
			ft_hget_left(vars);
		else if (random == RIGHT && move == 1)
			ft_hget_right(vars);
		ft_put_all_img(vars);
		deplacement = 0;
	}
	deplacement++;
}
