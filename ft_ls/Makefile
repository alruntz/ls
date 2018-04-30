# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alruntz <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 17:44:41 by alruntz           #+#    #+#              #
#    Updated: 2018/03/17 16:59:35 by alruntz     ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRCS = $(addsuffix .c,find_system print test ft_strlen2d print_col ft_memalloc ft_strnew ft_strjoin ft_strsub ft_itoa ft_strlen ft_memset ft_bzero ft_memcpy ft_strcmp lib_list/get_if lib_list/new_lst_content lib_list/swap_lst_content lib_list/tri lib_list/lst_remove lib_list/push_back lib_list/to_array lib_list/new_list lib_list/push_front lib_list/to_list)


CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -I . -I lib_list/

fclean:
	rm -rf $(NAME)

re: fclean all
