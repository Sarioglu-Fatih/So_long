# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsariogl <fsariogl@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 13:31:18 by fsariogl          #+#    #+#              #
#    Updated: 2022/03/25 16:21:18 by fsariogl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	so_long

SRC =	main.c\
		ft_so_long.c\
		get_next_line.c\
		ft_parsing.c\
		ft_parsing_utils.c\
		ft_putimg.c\
		ft_putnbr.c\
		ft_pos_player.c\
		ft_check_consumable.c\
		ft_parsing_param.c\

OBJ = $(SRC:.c=.o)
INCDIR = includes

NAME_BONUS =	so_long_bonus

SRC_BONUS =	main_bonus.c\
		ft_so_long_bonus.c\
		get_next_line_bonus.c\
		ft_parsing_bonus.c\
		ft_parsing_utils_bonus.c\
		ft_putimg_bonus.c\
		ft_putnbr_bonus.c\
		ft_pos_player_bonus.c\
		ft_check_consumable_bonus.c\
		ft_parsing_param_bonus.c\
		ft_pos_hostile_bonus.c\
		ft_pos_player_next_bonus.c\
		ft_find_bonus.c\
		ft_hostile_next_move_bonus.c\
		ft_itoa_bonus.c\

MLX = mlx/

OBJ_BONUS = $(SRC_BONUS:.c=.o)
INCDIR_BONUS = includes_bonus

CFLAGS = -Wall -Wextra -Werror
LINKS = mlx/libmlx.a -framework OpenGL -framework AppKit


all: $(NAME)

$(NAME): $(OBJ) $(INCDIR)
	make -S -C $(MLX) all 2>/dev/null
	$(CC) $(CFLAGS) $(OBJ) $(LINKS) -o $(NAME)

$(OBJ): $(SRC) $(INCDIR) Makefile
	$(CC) $(CFLAGS) -c $(SRC)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(INCDIR_BONUS)
	make -S -C $(MLX) all 2>/dev/null
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LINKS) -o $(NAME_BONUS)

$(OBJ_BONUS): $(SRC) $(INCDIR_BONUS) Makefile
	$(CC) $(CFLAGS) -c $(SRC_BONUS)

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)
	make -S -C $(MLX) clean

re: fclean all

.PHONY:	all clean fclean re
