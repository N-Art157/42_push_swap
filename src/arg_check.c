/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakagaw <anakagaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:13:42 by nakagawashi       #+#    #+#             */
/*   Updated: 2024/07/19 16:07:32 by anakagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	ft_issorted(t_dlst *stack)
{
	t_dlst	*temp;

	temp = stack -> next;
	while (temp -> next != stack)
	{
		if (temp -> value > temp -> next -> value)
			return (1);
		temp = temp -> next;
	}
	return (0);
}

static char	**set_args(int argc, char **argv)
{
	char	**split;
	int		i;

	if (argc == 2)
		split = ft_split(argv[1], ' ');
	else
	{
		argv++;
		split = argv;
	}
	i = 0;
	while (split[i])
	{
		if (split[i][0] == '\0')
		{
			if (argc == 2)
				ft_free(split, "Error");
			else
				ft_free_and_error(NULL, NULL, "Error");
		}
		i++;
	}
	return (split);
}

static int	ft_isnum(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '-')
		i = 1;
	if (s[i] == '0' && s[i + 1] != '\0')
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	if (s[0] == '-' && i == 1)
		return (0);
	return (1);
}

static int	ft_isduplicated(char **argv, int arg, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atol(argv[i]) == arg)
			return (0);
		i++;
	}
	return (1);
}

void	arg_check(int argc, char **argv)
{
	char	**args;
	int		i;
	long	temp;

	i = 0;
	args = set_args(argc, argv);
	while (args[i])
		i++;
	if (i == 0)
		ft_free(args, "Error");
	i = 0;
	while (args[i])
	{
		temp = ft_atol(args[i]);
		if (!ft_isnum(args[i]))
			ft_free_and_error(NULL, NULL, "Error");
		if (temp > INT_MAX || INT_MIN > temp)
			ft_free_and_error(NULL, NULL, "Error");
		if (!ft_isduplicated(args, temp, i))
			ft_free_and_error(NULL, NULL, "Error");
		i++;
	}
	if (argc == 2)
		ft_free(args, NULL);
}
