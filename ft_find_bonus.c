/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:01:45 by fsariogl          #+#    #+#             */
/*   Updated: 2022/03/24 18:44:47 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/so_long_bonus.h"

int	ft_find_next_c(t_vars *vars, char *str, int l, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == vars->tab[l][c])
			return (1);
		i++;
	}
	return (0);
}

int	ft_find_letter(t_vars *vars, char *str, int l, int c)
{
	int	index;

	index = -1;
	while (str[++index])
	{
		if (vars->tab[vars->line + l][vars->col + c] == str[index])
			return (1);
	}
	return (0);
}

int	ft_find_c(t_vars *vars, char *str, int random)
{
	int	i;
	int	l;
	int	c;
	int	poss;

	poss = -1;
	i = 0;
	c = vars->col;
	l = vars->line;
	if (random == RIGHT)
		if (ft_find_letter(vars, str, 0, 1) == 1)
			return (1);
	if (random == LEFT)
		if (ft_find_letter(vars, str, 0, -1) == 1)
			return (1);
	if (random == UP)
		if (ft_find_letter(vars, str, -1, 0) == 1)
			return (1);
	if (random == DOWN)
		if (ft_find_letter(vars, str, 1, 0) == 1)
			return (1);
	return (0);
}
