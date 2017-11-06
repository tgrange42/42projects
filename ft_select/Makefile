# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/02 13:26:57 by tgrange           #+#    #+#              #
#    Updated: 2017/11/06 15:42:16 by tgrange          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			ft_select

SRCS =			ft_select.c \
				error.c \
				lst_tools.c \
				mainloop.c \


SRCSD =			$(addprefix srcs/, $(SRCS))

CFLAGS =		-Wall -Wextra -Werror

LIBFTFLAGS =	-L Libft -lft

OBJS =			$(addprefix objs/, $(notdir $(SRCSD:.c=.o)))

all:			$(NAME)

$(NAME):		objs $(OBJS) get_libft
	@gcc $(CFLAGS) /usr/lib/libtermcap.dylib -o $(NAME) $(OBJS) $(MLXFLAGS) $(LIBFTFLAGS)
	@echo $(NAME) done !

get_libft:
	@make -C Libft

objs/%.o:		srcs/%.c
	@gcc -o $@ -c $< $(CFLAGS)
	@echo $@ done !

clean:
	@rm -rf objs
	@make clean -C Libft
	@echo cleaned !

objs:
	@mkdir objs

fclean:			clean
	@rm -rf $(NAME)
	@make fclean -C Libft
	@echo executable deleted

re:				fclean all

.PHONY:			re fclean clean
