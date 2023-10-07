/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_x.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 23:29:31 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/09/26 16:00:48 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_X_H
# define LIBFT_X_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define MAX_FD 256

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// Char
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_is_whitespace(char c);

// Memory
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);

// Strings
int		ft_atoi(const char *nptr);
double	ft_atod(const char *str);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strndup(const char *str, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_clear_strarr(char **arr);

// Strings Comparison
int		ft_str_isalnum(char const *str);
int		ft_str_isalpha(char const *str);
int		ft_str_isascii(char const *str);
int		ft_str_isdigit(char const *str);
int		ft_str_isprint(char const *str);
int		ft_str_isdouble(char const *str);

// Output
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

// Lists
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
t_list	*ft_lstget(t_list *lst, int index);
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

// GNL
char	*get_next_line(int fd);

// ft_printf
int		ft_printf(const char *str, ...);

// ft_printf Utils
int		print_chr(char c);
int		print_str(char *str);
int		print_ptr(void *ptr);
int		print_int(int nbr);
int		print_uint(unsigned int nbr);
int		print_hex(unsigned long h, int upper);
char	*ft_ltoa(long int n);
char	*nbr2hex(unsigned long nbr, int upper);
char	*b_appchr(char *str, char chr);
char	*e_appchr(char *str, char chr);
int		b_print_hex(unsigned long h, int upper, char flag_chr, int width);
int		b_print_int(int nbr, char flag_chr, int width);
int		b_print_uint(unsigned int nbr, char flag_chr, int width);
int		b_print_ptr(void *ptr, char flag_chr, int width);
int		b_print_str(char *str, int width);
int		b_print_chr(char c, int width);
int		put_width_chr(int width, int len, char chr);

#endif
