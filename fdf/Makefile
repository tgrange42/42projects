	# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/11 18:21:24 by tgrange           #+#    #+#              #
#    Updated: 2017/09/26 11:41:56 by tgrange          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			fdf

SRCS =			fdf.c \
				get_map.c \
				draw_map.c \
				tools_draw.c \
				tools_draw2.c \
				tools_draw3.c \
				tools.c \
				tools2.c \
				

SRCSD =			$(addprefix srcs/, $(SRCS))

CFLAGS =		-Wall -Wextra -Werror

MLXFLAGS =		-L minilibx -lmlx -framework OPENGL -framework AppKit

LIBFTFLAGS =	-L Libft -lft

OBJS =			$(addprefix objs/, $(notdir $(SRCSD:.c=.o)))

all:			$(NAME)

$(NAME):		objs $(OBJS) get_libft get_mlx
	@gcc $(CFLAGS) -o $(NAME) $(OBJS) $(MLXFLAGS) $(LIBFTFLAGS)
	@echo $(NAME) done !

get_libft:
	@make -C Libft

get_mlx:
	@make -C minilibx

objs/%.o:		srcs/%.c
	@gcc -o $@ -c $< $(CFLAGS)
	@echo $@ done !

clean:
	@rm -rf objs
	@make clean -C Libft
	@make clean -C minilibx
	@echo cleaned !

objs:
	@mkdir objs

fclean:			clean
	@rm -rf $(NAME)
	@make fclean -C Libft
	@make clean -C minilibx
	@echo executable deleted

re:				fclean all

.PHONY:			re fclean clean
