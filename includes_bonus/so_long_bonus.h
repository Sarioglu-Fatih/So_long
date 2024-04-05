/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:15:45 by fsariogl          #+#    #+#             */
/*   Updated: 2022/03/25 14:51:53 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../mlx/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# define RIGHT 5
# define LEFT 2
# define UP 4
# define DOWN 1

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
	char	*pcega[13];
	void	*pceg[13];
	int		col;
	int		line;
	int		col_max;
	int		line_max;
	char	**tab;
	int		img_width;
	int		img_height;
	int		move;
	int		exit;
	int		over;
	int		speed;
	char	*res;
}				t_vars;

char	*ft_itoa(int n);
char	*get_next_line(int fd);
void	ft_putstrerr(char *str);
int		ft_howmany_lines(char *av);
char	*ft_freetab(char **tab);
char	**ft_form(char **tab, int c);
char	**ft_contour(char **tab, int i, int s, t_vars *vars);
char	**ft_content(char **tab, int i, int s);
char	**ft_gettab(int nb, t_vars *vars, char *av);
int		ft_command(int keycode, t_vars *vars);
void	ft_asset(t_vars *vars);
void	ft_putimg(t_vars *vars, char c, int i, int j);
void	parsing(t_vars *vars, char *str);
t_vars	*ft_pos_player(t_vars *vars);
t_vars	*ft_get_up(t_vars *vars);
t_vars	*ft_get_left(t_vars *vars);
t_vars	*ft_get_down(t_vars *vars);
t_vars	*ft_get_right(t_vars *vars);
t_vars	*ft_get_up_next(t_vars *vars);
t_vars	*ft_get_down_next(t_vars *vars);
t_vars	*ft_get_left_next(t_vars *vars);
t_vars	*ft_get_right_next(t_vars *vars);
t_vars	*ft_hget_up(t_vars *vars);
t_vars	*ft_hget_down(t_vars *vars);
t_vars	*ft_hget_left(t_vars *vars);
t_vars	*ft_hget_right(t_vars *vars);
int		ft_pos_hostile(t_vars *vars);
void	ft_hostile_move(t_vars *vars);
void	ft_put_all_img(t_vars *vars);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
int		ft_check_consumable(t_vars *vars);
void	ft_open_close_window(t_vars *vars, int nb);
void	ft_parsing_param(int ac, char **av, t_vars *vars);
int		ft_close(t_vars *vars);
void	ft_putstr(char *str);
int		ft_find_c(t_vars *vars, char *str, int random);
int		ft_find_next_c(t_vars *vars, char *str, int l, int c);

#endif
