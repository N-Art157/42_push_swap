/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakagaw <anakagaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:36:47 by nakagawashi       #+#    #+#             */
/*   Updated: 2023/07/28 15:41:41 by anakagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlcpy(char *restrict dst, const char *restrict src, int dstsize)
{
	const char	*s;
	int			n;

	s = src;
	n = dstsize;
	if (n != 0)
	{
		while (n-- > 1)
		{
			*dst++ = *s++;
			if (*(s - 1) == '\0')
				break ;
		}
	}
	if (n == 0)
	{
		if (dstsize != 0)
			*dst = '\0';
		while (*s++)
			;
	}
	return (s - src - 1);
}
