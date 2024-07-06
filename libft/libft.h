/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakagaw <anakagaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 22:10:37 by anakagaw          #+#    #+#             */
/*   Updated: 2024/07/06 18:48:59 by anakagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		ft_strlen(const char *s);
int		ft_strlcpy(char *restrict dst, const char *restrict src, int dstsize);
char	*ft_strdup(const char *src);
void	ft_putendl_fd(char	*s, int fd);
char	**ft_split(char	const *s, char c);
int		ft_isdigit(int c);
int		ft_atoi(char	*str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t	count, size_t	size);
void	ft_bzero(void *s, size_t n);

#endif