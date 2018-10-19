# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egiyani <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/23 13:55:33 by egiyani           #+#    #+#              #
#    Updated: 2018/09/05 11:04:06 by egiyani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TAG 	= gcc
NAME 	= libft.a
FLAG	= -Wall -Werror -Wextra
SRC		= ft_atoi.c\
		ft_memccpy.c\
		ft_putchar.c\
		ft_strncmp.c\
		ft_bzero.c\
		ft_memchr.c\
		ft_putstr.c\
		ft_strrchr.c\
		ft_isalnum.c\
		ft_memcmp.c\
		ft_strchr.c\
		ft_strstr.c\
		ft_isalpha.c\
		ft_memcpy.c\
		ft_strcmp.c\
		ft_tolower.c\
		ft_isascii.c\
		ft_memmove.c\
		ft_strcpy.c\
		ft_toupper.c\
		ft_isdigit.c\
		ft_memset.c\
		ft_strlen.c\
		ft_strnstr.c\
		ft_putchar_if.c\
		ft_strchr_last.c\
		ft_putendl_exit.c\
		ft_strcat.c\
		ft_strncat.c\
		ft_isprint.c\
		ft_strlcat.c\
		ft_strdup.c\
		ft_strncpy.c\
		ft_strnew.c\
		ft_memalloc.c\
		ft_list_clear.c\
		ft_list_remove_if.c\
		ft_list_remove_node.c\
		ft_list_reverse.c\
		ft_list_size.c\
		ft_list_sort.c\
		ft_ptrswp.c\
		ft_memdel.c\
		ft_strdel.c\
		ft_strclr.c\
		ft_striter.c\
		ft_list_size.c\
		ft_striteri.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_putendl.c\
		ft_putnbr.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_strsplit.c\
		ft_itoa.c\
		ft_isupper.c\
		ft_islower.c\
		ft_capitalize.c\
		ft_putnstr.c\
		ft_strnchr.c\
		ft_lstadd.c\
		ft_lstdelone.c\
		ft_lstmap.c\
		ft_lstnew.c\
		ft_lstdel.c\
		ft_lstiter.c\
		ft_itoa_large.c\
		ft_itoa_ularge.c\
		ft_list_push_back.c\
		ft_list_push_front.c\
		ft_putnbr_justify_right.c\
		ft_putstr_justify_left.c\
		ft_putstr_justify_right.c\
		ft_abs.c\
		ft_count_digits.c\
		ft_list_create_elem.c\
		ft_list_find_end.c\
		ft_count_digits_umax.c\
		ft_ptrequ.c

all : $(NAME)

$(NAME) :
		$(TAG) $(FLAG) -c $(SRC)
		ar rc $(NAME) *.o
		ranlib $(NAME)
clean:
		rm -f *.o

fclean: clean
		rm -f libft.a

re:		fclean all
