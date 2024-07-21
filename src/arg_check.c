/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakagawashinta <nakagawashinta@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:13:42 by nakagawashi       #+#    #+#             */
/*   Updated: 2024/07/20 00:48:26 by nakagawashi      ###   ########.fr       */
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
	{
		split = ft_split(argv[1], ' ');
		if (!split)
			ft_free(NULL, "Error", 0);
	}
	else
	{
		argv++;
		split = argv;
	}
	i = 0;
	while (split[i])
	{
		if (split[i][0] == '\0')
			ft_free(split, "Error", argc);
		i++;
	}
	return (split);
}

static int	ft_isnum(char *s)
{
	int		i;
	
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
	bool	flag;

	flag = true;
	i++;
	while (argv[i])
	{
		if (ft_atol(argv[i], &flag) == arg)
			return (0);
		if (flag == false)
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
	bool	flag;

	i = 0;
	flag = true;
	args = set_args(argc, argv);
	if (args[i] == NULL)
		ft_free(args, "Error", argc);
	while (args[i])
	{
		temp = ft_atol(args[i], &flag);
		if (flag == false)
			ft_free(args, "Error", argc);
		if (!ft_isnum(args[i]))
			ft_free(args, "Error", argc);
		if (temp > INT_MAX || INT_MIN > temp)
			ft_free(args, "Error", argc);
		if (!ft_isduplicated(args, temp, i))
			ft_free(args, "Error", argc);
		i++;
	}
	ft_free(args, NULL, argc);
}
