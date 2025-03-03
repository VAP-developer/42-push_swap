/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:19:00 by vicalons          #+#    #+#             */
/*   Updated: 2025/03/03 02:43:50 by vicalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
// TEST LIBRARY
// --------------------------------
// Group 1 library
# include <ctype.h>
// Group 2 library
# include <bsd/string.h>
// Group 6 library
# include <stdio.h>
// Printf
# include <stdarg.h>

# define HEX_UPP "0123456789ABCDEF"
# define HEX_LOW "0123456789abcdef"
# define DECIMAL "0123456789"

// STRUCT
// --------------------------------
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// group 1 -- OK
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
// group 2 -- CODE
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
// group 3 -- CODE
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
// group 4 -- CODE
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
// FUNCIONES ADICIONALES
// group 5 -- CODE
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
// group 6 -- CODE
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
// group 7 -- CODE
void	ft_lstadd_front(t_list **lst, t_list *new_lst);
void	ft_lstadd_back(t_list **lst, t_list *new_lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);

// FT_PRINTF
int		ft_printf(const char *str, ...);
size_t	ft_printspecial(const char c, va_list va);
size_t	ft_printchar(const int c);
size_t	ft_printstr(const char *str);
size_t	ft_printnbr(int nbr, const char *base, int len_base);
size_t	ft_printunsgn(unsigned long long nbr, const char *base, int len_base);
size_t	ft_printptr(void *ptr);

// MILESTONE 2
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isfloat(char *str);
double	ft_atof(char *str);
#endif
