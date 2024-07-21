/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakagawashinta <nakagawashinta@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 22:16:40 by anakagaw          #+#    #+#             */
/*   Updated: 2023/10/26 00:15:10 by nakagawashi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	array_count(char const	*s, char c)
{
	int	i;
	int	flag;
	int	count;

	i = 0;
	count = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (s[i] == c)
			flag = 0;
		i++;
	}
	return (count);
}

char	*dst_dup(char const *s, int *i, int start, char c)
{
	char	*dst;
	int		n;

	dst = malloc(sizeof(char) * (*i + 1));
	if (!dst)
		return (NULL);
	n = 0;
	while (s[start] != c && s[start])
	{
		dst[n] = s[start];
		start++;
		n++;
	}
	dst[n] = '\0';
	*i = 0;
	return (dst);
}

void	malloc_free(char **dst, int j)
{
	while(j-- > 0)
		free(dst[j]);
}

char	**split_word(char const	*s, char c, char **dst, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (n < (ft_strlen (s) + 1))
	{
		if (s[n] != c && s[n])
			i++;
		else if ((!s[n] && s[n - 1] != c) || (s[n] == c && s[n - 1] != c))
		{
			dst[j] = dst_dup(s, &i, n - i, c);
			if (!dst[j])
			{
				malloc_free(dst, j);
				return (NULL);
			}
			j++;
		}
		n++;
	}
	dst[j] = 0;
	return (dst);
}

char	**ft_split(char	const *s, char c)
{
	char	**dst;
	int		n;

	if (*s == '\0')
		return (ft_calloc(sizeof(char *), 1));
	n = 0;
	dst = malloc(sizeof(char *) * (array_count(s, c) + 1));
	if (!dst)
		return (NULL);
	while (s[n] == c)
		n++;
	dst = split_word(s, c, dst, n);
	if (!dst)
	{
		free(dst);
		return (NULL);
	}
	return (dst);
}
