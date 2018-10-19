/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:08:41 by egiyani           #+#    #+#             */
/*   Updated: 2018/09/13 14:13:46 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

typedef struct		s_intarr
{
	int				**data;
	int				height;
	int				width;
}					t_intarr;

typedef struct		s_list
{
	struct s_list	*next;
	size_t			content_size;
	void			*content;
	void			*data;
}					t_list;

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
void				*ft_memcpy(void *str1, const void *str2, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
void				ft_putstr(char const *str);
char				*ft_strchr(const char *str, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *s1, const char *s2);
size_t				ft_strlen(const char *str);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
char				*ft_strnstr(const char *h, const char *n, size_t len);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
int					ft_isprint(int c);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
char				*ft_strdup(const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strnew(size_t size);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_capitalize(char *s);
int					ft_islower(int c);
int					ft_isupper(int c);
void				ft_putnstr(char *str, int n);
char				*ft_strnchr(char *s, char c, int offset);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
char				*ft_itoa_large(intmax_t number);
char				*ft_itoa_ularge(unsigned long long number);
void				ft_list_push_back(t_list **begin_list, void *data);
void				ft_list_push_front(t_list **begin_list, void *data);
void				ft_putnbr_justify_right(int number,
					size_t total, char fill);
void				ft_putstr_justify_left(char *string,
					size_t total, char fill);
void				ft_putstr_justify_right(char *string,
					size_t total, char fill);
int					ft_abs(int num);
int					ft_count_digits(int number);
t_list				*ft_list_create_elem(void *data);
t_list				*ft_list_find_end(t_list *list);
int					ft_count_digits_umax(uintmax_t number);
int					ft_ptrequ(const void *first, const void *second);
size_t				ft_list_size(t_list *begin_list);
void				ft_list_clear(t_list **begin_list, void (*free_inside)());
void				ft_list_remove_if(t_list **begin_list,
					void *data_ref, int (*cmp)());
void				ft_list_remove_node(t_list **original, t_list *to_remove,
					void (*free_inside)(void*));
void				ft_list_reverse(t_list **begin_list);
size_t				ft_list_size(t_list *begin_list);
void				ft_list_sort(t_list **first, int (*compare)(void*, void*));
void				ft_ptrswp(void **first, void **second);
void				ft_putchar_if(int boolean, char yes, char no);
char				*ft_strchr_last(const char *haystack, int needle);
void				ft_putendl_exit(char const *source, int exit_code);

#endif
