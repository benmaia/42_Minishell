/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 19:48:06 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/05/29 18:32:27 by bmiguel-         ###   ########.fr       */
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

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/*----------||| MEM FUNCTION |||------------*/

/*Replica of bzero*/
/*Set N bytes of a string to 0*/
void	ft_bzero(void *str, size_t n);

/*Replica of memcpy*/
/*Copy N bytes of SRC to DEST*/
void	*ft_memcpy(void *dest, const void *src, size_t count);

/*Replica of memchr*/
/*Searches for the first occurrence of the CHAR c in */
/*the first N bytes of the STR pointed to, by the */
/*argument STR*/
void	*ft_memchr(const void *str, int c, size_t counter);

/*Replica of memcmp*/
/*Compare N bytes from S1 and S2*/
int		ft_memcmp(const void *s1, const void *s2, size_t counter);

/*Replica of memcpy*/
/*Copy N bytes from SRC to DEST*/
void	*ft_memcpy(void *dest, const void *src, size_t count);

/*Replica of memmove*/
/*Copies N bytes from S1 to S2*/
void	*ft_memmove(void *dest, const void *src, size_t counter);

/*Replica of memset*/
/*Set N bytes of S to C*/
void	*ft_memset(void *str, int c, size_t count);

/*Replica of calloc*/
/*Allocate NMEMB elements of SIZE bytes each, all initialized to 0.*/
void	*ft_calloc(size_t n, size_t size);

/*----------||| STR FUNCTION |||------------*/

/*Replic of atoi*/
/*Converts a string to an intenger*/
int		ft_atoi(const char *str);

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

/*Replica of tolower*/
/*Switches every Upper case chars to Lower case in a STR*/
int		ft_tolower(int arg);

/*Replica of toupper*/
/*Switches every Lower case chars to Upper case in a STR*/
int		ft_toupper(int arg);

/*Replica of strlcat*/
/*Appends the NUL-terminated string SRC to the end of DEST.*/
/*It will append at most size - strlen(DEST) - 1 bytes, NUL*/
/*terminating the result.*/
size_t	ft_strlcat(char *dest, const char *src, size_t n);

/*Replica of strchr*/
/*Returns the position of C in the STR*/
char	*ft_strchr(const char *str, int c);

/*Replica of strncmp*/
/*Compares N characters form S1 and S2*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*Replica of strlcpy*/
/*Copies up to size - 1 characters from the NUL-terminated*/
/*string SRC to DEST, NUL-terminating the result.*/
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

/*Replica of strdup*/
/*Duplicate STR, returning a identical malloc'd STR*/
char	*ft_strdup(const char *str);

/*Replica of strlen*/
/*Return the lenght of S*/
size_t	ft_strlen(const char *str);

/*Replica of strnstr*/
/*Locates the	first occurrence of the	null-terminated string little*/
/*in the string big, where not more than	len characters are searched.*/
/*Characters that appear after a `\0'	character are not searched.*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/*Replica of strrchr*/
/*Searches for the last occurrence of the CHAR in the STR pointed to*/
/*by the argument STR.*/
char	*ft_strrchr(const char *str, int c);

/*Applies the function ’f’ on each character of*/
/*the string passed as argument, passing its index*/
/*as first argument. Each character is passed by*/
/*address to ’f’ to be modified if necessary.*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *s));

/*Applies the function ’f’ to each character of the*/
/*string ’s’, and passing its index as first argument*/
/*to create a new string (with malloc(3)) resulting*/
/*from successive applications of ’f’.*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*Allocates (with malloc(3)) and returns a substring*/
/*from the string ’s’.*/
/*The substring begins at index ’start’ and is of*/
/*maximum size ’len’.*/
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*Allocates (with malloc(3)) and returns a new*/
/*string, which is the result of the concatenation*/
/*of ’s1’ and ’s2’.*/
char	*ft_strjoin(char const *s1, char const *s2);

/*Allocates (with malloc(3)) and returns a copy of*/
/*’s1’ with the characters specified in ’set’ removed*/
/*from the beginning and the end of the string.*/
char	*ft_strtrim(char const *s, char const *set);

/*Allocates (with malloc(3)) and returns an array*/
/*of strings obtained by splitting ’s’ using the*/
/*character ’c’ as a delimiter. The array must end*/
/*with a NULL pointer.*/
char	**ft_split(char const *s, char c);

/*Replica of putchar*/
/*Prints a CHAR on the selected FD*/
void	ft_putchar_fd(char c, int fd);

/*Replica of putstr*/
/*Prints a STR on the selected FD*/
void	ft_putstr_fd(char const *str, int fd);

/*Replica of putendl*/
/*Inserts an '\n' in the end of the STR*/
void	ft_putendl_fd(char const *str, int fd);

/*----------||| INT FUNCTION |||------------*/

/*Replica of putnbr*/
/*Prints an INT in the selected FD*/
void	ft_putnbr_fd(int n, int fd);

/*Replica of putnbr_base*/
/*Prints an INT in the selected base to the selected FD*/
void	ft_putnbr_base(long long int nbr, char *base);

/*Allocates (with malloc(3)) and returns a string*/
/*representing the integer received as an argument.*/
/*Negative numbers must be handled.*/
char	*ft_itoa(int n);

/*---------||| LIST FUNCTION |||------------*/

/*Allocates (with malloc(3)) and returns a new node.*/
/*The member variable ’content’ is initialized with*/
/*the value of the parameter ’content’. The variable*/
/*’next’ is initialized to NULL.*/
t_list	*ft_lstnew(void *content);

/*Adds the node ’new’ at the beginning of the list.*/
void	ft_lstadd_front(t_list **lst, t_list *neww);

/*Counts the number of nodes in a list.*/
int		ft_lstsize(t_list *lst);

/*Returns the last node of the list.*/
t_list	*ft_lstlast(t_list *lst);

/*Adds the node ’new’ at the end of the list.*/
void	ft_lstadd_back(t_list **lst, t_list *neww);

/*Takes as a parameter a node and frees the memory of*/
/*the node’s content using the function ’del’ given*/
/*as a parameter and free the node. The memory of*/
/*’next’ must not be freed.*/
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/*Deletes and frees the given node and every*/
/*successor of that node, using the function ’del’*/
/*and free(3).*/
/*Finally, the pointer to the list must be set to*/
/*NULL.*/
void	ft_lstclear(t_list **lst, void (*del)(void *));

/*Iterates the list ’lst’ and applies the function*/
/*’f’ on the content of each node.*/
void	ft_lstiter(t_list *lst, void (*f)(void *));

/*Iterates the list ’lst’ and applies the function*/
/*’f’ on the content of each node. Creates a new*/
/*list resulting of the successive applications of*/
/*the function ’f’. The ’del’ function is used to*/
/*delete the content of a node if needed.*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*-------------||| PRINTF |||---------------*/

/*A function that will mimic the original printf()*/
int		ft_printf(const char *format, ...);

void	*ft_func_select(char c);

int		ft_printf_c(char c);

int		ft_printf_s(char *str);

int		ft_printf_p(unsigned long int nbr);

int		ft_printf_d(int nbr);

int		ft_printf_u(unsigned int nbr);

int		ft_printf_x(unsigned int nbr);

int		ft_printf_xx(unsigned int nbr);

int		ft_n_base_counter(long long int nbr, char *base);

int		ft_n_pointer(unsigned long int nbr, char *base);

/*---------||| GET NEXT LINE |||------------*/

/*Returns a line read from a*/
/*file descriptor*/
char	*get_next_line(int fd);

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#endif
