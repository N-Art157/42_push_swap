/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakagawashinta <nakagawashinta@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:14:49 by anakagaw          #+#    #+#             */
/*   Updated: 2023/11/19 10:12:50 by nakagawashi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char	*s, int fd)
{
	if (s && fd)
	{
		write(fd, s, ft_strlen (s));
		write(fd, "\n", 1);
	}
}
