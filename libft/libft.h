/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:53:55 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/02 20:28:20 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <ctype.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// Classification functions
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isalpha_extend(int n);
int					ft_isprint_extend(int n);
int					ft_isascii_extend(int n);
int					ft_skipwhite(const char *s);
bool				ft_onlywhite(char *line);
bool				ft_iswhite(int c);

// Memory functions
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_calloc(size_t xnmemb, size_t size);
void				*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void				ft_free_double(char **smth);
char				**ft_realloc_2d(char **in, int add);

// String (+Array) functions
// modification
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strcpy(char *src, int start);
char				*ft_strcat(char *dst, char *src);
char				*ft_strncpy(char *dest, char *src, int n);
char				*ft_strjoin_free(char *strA, char *strB, const char to_free);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strappend(char **s1, const char *s2);

// creation
char				*ft_strdup(const char *s);
char				*ft_substr(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// information
size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
bool				ft_strcmp_bool(const char *s1, const char *s2);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
bool				ft_strnstr_bool(const char *big, const char *lil, int start,
						int len);
size_t				ft_strspn(const char *s, const char *accept);
int					ft_arrlen(char **s);

// Conversion functions
int					ft_atoi(const char *nptr);
long				ft_atoi_long(const char *nptr);
double				ft_atof(char *s);
char				*ft_itoa(int n);
char				*ft_itoa_long(long n);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strtoupper(char *s);
char				*ft_strtolower(char *s);

// Linked list functions
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *add);
void				ft_lstadd_back(t_list **lst, t_list *add);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

// Printf functions
int					ft_printf(const char *format, ...);
int					ft_printchar(int c);
int					ft_printstr(char *s);
int					ft_printnbr(char specifier, long int nbr, int base);
int					ft_printptr(void *ptr);
int					ft_decideformat(va_list args, const char *format, int i);

// output functions
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int c, int fd);
void				ft_print_array(char **arr);
void				ft_print_array_fd(char **arr, int fd);

// gnl
char				*get_next_line(int fd);

#endif