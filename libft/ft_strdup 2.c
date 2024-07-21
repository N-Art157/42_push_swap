/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakagawashinta <nakagawashinta@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:40:34 by anakagaw          #+#    #+#             */
/*   Updated: 2023/08/15 16:11:05 by nakagawashi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	i = ft_strlen(src);
	dest = malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (0);
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (dest - i);
}

