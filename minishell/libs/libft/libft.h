/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 19:48:06 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/05/27 18:17:18 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/uio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/*Replic of atoi*/
/*Converts a string to an intenger*/
int		ft_atoi(const char *str);

/*Replica of bzero*/
/*Set N bytes of a string to 0*/
void	ft_bzero(void *str, size_t n);

/*Replica of isalnum*/
/*Checks if the arg is alphanumeric*/
int		ft_isalnum(int arg);

/*Replica of isalpha*/
/*Checks if the arg is a letter*/
int		ft_isalpha(int arg);

/*Replica of isascii*/
/*Checks if the arg is an ascii char*/
int		ft_isascii(int arg);

/*Replica of isdigit*/
/*Checks if the arg is an int*/
int		ft_isdigit(int arg);

/*Replica of isprint*/
/*Checks if the arg is a printable char*/
int		ft_isprint(int arg);

void	*ft_memcpy(void *dest, const void *src, size_t count);

void	*ft_memchr(const void *str, int c, size_t counter);

int		ft_memcmp(const void *s1, const void *s2, size_t counter);

void	*ft_memcpy(void *dest, const void *src, size_t count);

void	*ft_memmove(void *dest, const void *src, size_t counter);

void	*ft_memset(void *str, int c, size_t count);

size_t	ft_strlcat(char *dest, const char *src, size_t n);

char	*ft_strchr(const char *str, int c);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

size_t	ft_strlcpy(char *dest, const char *src, size_t size);

char	*ft_strdup(const char *str);

/*Returns the str lenght*/
size_t	ft_strlen(const char *str);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char	*ft_strrchr(const char *str, int c);

int		ft_tolower(int arg);

int		ft_toupper(int arg);

void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char const *str, int fd);

void	ft_putendl_fd(char const *str, int fd);

void	ft_putnbr_fd(int n, int fd);

void	ft_putnbr_base(long long int nbr, char *base);

int		ft_n_base_counter(long long int nbr, char *base);

int		ft_n_pointer(unsigned long int nbr, char *base);

void	*ft_memalloc(size_t size);

void	ft_striter(char *s, void (*f)(char *));

void	ft_striteri(char *s, void (*f)(unsigned int, char *s));

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strtrim(char const *s, char const *set);

char	**ft_split(char const *s, char c);

char	**ft_split_minishell(char const *s, char c);

void	*ft_calloc(size_t n, size_t size);

char	*ft_itoa(int n);

t_list	*ft_lstnew(void *content);

void	ft_lstadd_front(t_list **lst, t_list *n);

int		ft_lstsize(t_list *lst);

t_list	*ft_lstlast(t_list *lst);

void	ft_lstadd_back(t_list **lst, t_list *n);

void	ft_lstdelone(t_list *lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *));

void	ft_lstiter(t_list *lst, void (*f)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

char	*get_next_line(int fd);

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		ft_printf(const char *format, ...);

void	*ft_func_select(char c);

int		ft_printf_c(char c);

int		ft_printf_s(char *str);

int		ft_printf_p(unsigned long int nbr);

int		ft_printf_d(int nbr);

int		ft_printf_u(unsigned int nbr);

int		ft_printf_x(unsigned int nbr);

int		ft_printf_xx(unsigned int nbr);

#endif
