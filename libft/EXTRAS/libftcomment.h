/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 23:06:34 by lbaumeis          #+#    #+#             */
/*   Updated: 2023/09/13 16:30:30 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
/* 
 * checks if the macro LIBFT_H is not defined
 * if not yet defined, the code underneath should be included
 * if already defined, the code should be skipped
 * the second line does the work
*/

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <string.h>
# include <ctype.h>
# include <aio.h>

/*
 * NO OUTPUTS/ THE FUNCTIONS DO NOT PRINT ANYTHING
 * ONLY RETURN VALUES
 *
 * guidelines & technical information:
 * - it is forbidden to declare global variables
 * - if helper functions are needed to split a complex function
 *   define as static to limit scope to specific file only
 * - all files must be placed at root of repository
 *   + libft.a has to be created at root of repository
 * - no turning in of unused files
 * - .c-files must compile with -Wall -Wextra -Werror flags
 * - must use ar command to create library (no libtool!)
*/

/*
 * ===============°°°BASIC CHECKS°°°===============
 * IF NOT OTHER SPECIFIED THE RETURN VALUE IS ALWAYS THE SAME:
 * 0 = FALSE AND ANY OTHER NONZERO INTEGER = TRUE
*/

int		ft_isascii(int n);
/*
 * checks if input is valid 7 bit ASCII character
 * meaning if it fits into the ascii table or
 * if it can be represented using the ascii table
*/

int		ft_isprint(int n);
/*
 * is it printable?
 * (can you see it when typing it in?)
*/

int		ft_isalpha(int n);
/*
 * checks if the input given is in the alphabet
 * no special characters (eg. ä, ö, ü, ß) included
*/

int		ft_isdigit(int n);
/*
 * checks if input is in the range of 0 to 9
*/

int		ft_isalnum(int n);
/*
 * checks if input is alphanumeric
 * combination of ft_isalpha and ft_isdigit
 * if input fits in either one of those two -> true
*/

/*
 * ===============°°°ACTIONS°°°===============
*/

int		ft_tolower(int n);
/*
 * converts a capital letter into it's corresponding small version
 * (only if possible!, if not returns input (=n)
 * can have undefined behaviour if n != EOF or unsigned char
*/

int		ft_toupper(int n);
/*
 * same as ft_tolower, just the other way around
*/

int		ft_atoi(const char *str);
/*
 * takes string and "deletes" all whitespace characters
 * also decides if + or - (whichever one is in the input, only one!)
 * only returns the integer value
 * ignores everything after the digits in the string (if there is smth)
*/

/*
 * ===============°°°STRING°°°===============
*/

size_t	ft_strlen(const char *str);
/*
 * counts the characters in a string and returns the number counted
 * does not include '\0'
*/

size_t	ft_strlcpy(char *dest, const char *src, size_t n);
/*
 * copies first n bytes from the src-string to the dest-string
 * always terminates with the NULL-terminator
 */

char	*ft_strnstr(const char *macro, const char *nano, size_t n);
/*
 * finds substring inside mainstring (if existend)
 * only if complete str found
 * ->both strings need a NULL terminator
*/

char	*ft_strchr(const char *s, int c);
/*
 * if character c is inside string
 * returns pointer to first time it encounters it
*/

char	*ft_strrchr(const char *s, int c);
/*
 * same as strchr above, but starting at end
*/

int		ft_strncmp(const char *s1, const char *s2, size_t n);
/*
 * compares string 1 to string 2 up to n bytes
*/

size_t	ft_strlcat(char *dest, const char *src, size_t n);
/*
 * puts src-string after string of dest up until n bytes
 * NULL terminates it if possible
*/

/*
 * ===============°°°MEMORY°°°===============
*/

void	*ft_memset(void *s, int c, size_t n);
/*
 * sets the first n bytes in given memory (s) to c
 * c needs to be in the range of anscii bc its int
*/

void	*ft_bzero(void *s, size_t n);
/*
 * (like memset but c is always 0)
 * should set the first n bytes of the given memory to zero
 * in this one it sets the whole memory to zero, not minding n
 * (but normal bzero does the same for me, so its okay)
 * ADDITION: figuered it out: in main -> if you want to have
 * the output of the whole string minus the part you deleted:
 * you need to put "s + n" so it starts printing from after that
 * otherwise it stops at the null terminator!
 * it actually does what it should do!!
 * (just did not show it before..)
*/

void	*ft_memcpy(void *dest, const void *src, size_t n);
/*
 * copies the first n bytes of src to dest
 * takes any kind of memeory
 * overwrites it!
*/

void	*ft_memmove(void *dest, const void *src, size_t n);
/*
 * copies first n bytes of src to dest like memcpy
 * BUT doesnt overwrite src!
*/

void	*ft_memchr(const void *s, int c, size_t n);
/*
 * fill up n bytes (starting at str[0]) with c (given in int)
*/

int		ft_memcmp(const void *s1, const void *s2, size_t n);
/*
 * compares for example two strings with each other
 * TAKES ANY INPUT
 * only compares up until n bytes
 * typecasting important!
*/

/*
 * ===============°°°MALLOC°°°===============
*/

void	*ft_calloc(size_t x, size_t size);
/*
 * needs malloc, allocates space for x characters(or anything but void!), each being 'size' long
 * mind the space it takes up -> if its too big its going to be a NULL pointer
*/

char	*ft_strdup(const char *d);
/*
 * duplicates the given string d
 * creates sace with malloc and then fills it with the string
*/

#endif
