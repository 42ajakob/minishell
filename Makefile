# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 19:42:46 by rdragan           #+#    #+#              #
#    Updated: 2023/09/27 03:43:49 by rdragan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
SRC			=	src/main.c \
				src/exec_command.c \
				src/exec_utils.c \
				src/copy_env.c \
				src/builtins/cd.c \
				src/builtins/env.c \
				src/builtins/export.c \
				src/builtins/echo.c \
				src/builtins/pwd.c \
				src/builtins/unset.c \
				src/builtins/exit.c \
				src/signal_handling.c \
				src/mini_split.c \
				src/env_var.c \
				src/here_doc.c \
				src/create_lst.c \
				src/del_lst.c \
				src/traverse_files.c \
				src/executer.c \
				src/count_total_pipes.c \
				src/expander.c \
				src/check_error.c \
				src/sort_split.c \
				src/rm_quotes.c \
				src/create_node.c \
				src/expand_var.c \
				src/builtin_utils.c \
				src/init_main.c \
				src/get_tmp_envp.c \
				src/executer_utils.c \
				src/set_fds.c
OBJ			=	$(SRC:.c=.o)
CFLAGS		=	-Wall -Werror -Wextra -g
LIBFT_LIB	=	libft/libft.a
LINK_FLAGS	=	-lreadline
CC			=	cc
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make -C libft
	$(CC) $^ $(LINK_FLAGS) $(LIBFT_LIB) -o $(NAME)

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re