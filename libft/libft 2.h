/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakagawashinta <nakagawashinta@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 22:10:37 by anakagaw          #+#    #+#             */
/*   Updated: 2023/10/26 03:54:26 by nakagawashi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int	ft_atoi(char *str);
void    ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t	count, size_t	size);
int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);
void	*ft_memchr(const void	*s, int c, size_t	n);
int	ft_memcmp(const void	*s1, const void	*s2, size_t n);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void    *ft_memset(void *b, int c, int len);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcat(char *restrict dest, const char *restrict src, size_t size);
int	ft_strlcpy(char *restrict dst, const char *restrict src, int dstsize);
int	ft_strlen(const char *s);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char	*haystack, const char	*needle, size_t len);
char	*ft_strrchr(const char	*s, int c);
char	*ft_substr(char const	*s, unsigned int start, size_t	len);
int	ft_tolower(int c);
int ft_toupper(int c);
char	*ft_strjoin(char	const *s1, char	const *s2);
char	*ft_strtrim(char	const *s1, char	const *set);
void	ft_putendl_fd(char	*s, int fd);
void	ft_putstr_fd(char	*s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_itoa(int	n);
void	ft_putnbr_fd(int nb, int fd);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strdup(const char *src);
char	**ft_split(char	const *s, char c);
void	ft_striteri(char	*s, void (*f)(unsigned int, char*));
#endif