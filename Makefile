# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egiyani <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/03 13:15:50 by egiyani           #+#    #+#              #
#    Updated: 2018/09/10 09:17:33 by egiyani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			ft_ls

CC =			gcc
FLAGS =			-Wall -Werror -Wextra -g
SRCS =			srcs/
INCLUDES =		includes/
LIBFT =			libft/

COMPILED =		file_permissions.o \
				ft_ls_handler.o \
				handle_dir.o \
				main.o \
				print_entries.o \
				read_link.o \
				dir_failing.o \
				block_size.o \
				file_type_char.o \
				ft_pfo.o \
				handle_directories.o \
				make_entry.o \
				print_entry.o \
				s_print_entry.o \
				file_options.o \
				free_entry.o \
				ft_read_dir.o \
				lstat_if_sym.o \
				modified_time.o \
				print_folder.o \
				sort_list.o
all: $(NAME)

$(NAME): $(COMPILED)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME) -L $(LIBFT) -lft $(COMPILED)
	@echo "made" $(NAME)

$(COMPILED): %.o: $(SRCS)/%.c
	@$(CC) -c $(FLAGS) -I $(INCLUDES) -I $(LIBFT) $< -o $@

clean:
	@make -C $(LIBFT) clean
	@-/bin/rm -f $(COMPILED)
	@echo "cleaned" $(NAME)

fclean: clean
	@make -C $(LIBFT) fclean
	@-/bin/rm -f $(NAME)
	@echo "fcleaned" $(NAME)

re: fclean all
