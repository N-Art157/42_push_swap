/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakagaw <anakagaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 22:00:43 by anakagaw          #+#    #+#             */
/*   Updated: 2024/07/08 15:54:33 by anakagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char	*str)
{
	long	n;
	int		negative;

	n = 0;
	negative = 1;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		if ((n > LONG_MAX / 10 || (n == LONG_MAX / 10
					&& (*str - '0') > 7)) && negative == 1)
			return (-1);
		else if ((n > LONG_MAX / 10 || (n == LONG_MAX / 10
					&& (*str - '0') > 8)) && negative == -1)
			return (0);
		n = n * 10 + (*str++ - 48);
	}
	return ((int)n * negative);
}
