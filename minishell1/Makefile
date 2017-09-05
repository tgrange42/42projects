# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/29 17:21:19 by tgrange           #+#    #+#              #
#    Updated: 2017/07/25 13:21:18 by tgrange          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		minishell

SRCS =		minishell.c \
			cd.c \
			mini_core.c \
			env.c \
			env_list.c \
			env_list2.c \
			tools.c \
			tools2.c \
			env_functions.c \
			echo.c \
			pwd.c \
			exit_ms.c \
			exec_bin.c \
			tilde.c \

SRCSD =		$(addprefix srcs/, $(notdir $(SRCS)))

CFLAGS =	-Wall -Wextra -Werror

OBJS =		$(addprefix objs/, $(notdir $(SRCSD:.c=.o)))

all:		$(NAME)

$(NAME):	objs $(OBJS) get_libft
			@gcc $(CFLAGS) -o $(NAME) $(OBJS) -L Libft -lft
			@echo $(NAME) done !

get_libft:
			@make -C Libft

objs/%.o:	srcs/%.c
			@gcc -o $@ -c $< $(CFLAGS)
			@echo $@ done !
clean:
			@rm -rf objs
			@make clean -C Libft

objs:
			@mkdir objs

fclean:		clean
			@rm -rf $(NAME)
			@make fclean -C Libft

re:			fclean all

.PHONY:		re fclean clean
