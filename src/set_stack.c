/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakagaw <anakagaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:04:24 by nakagawashi       #+#    #+#             */
/*   Updated: 2024/07/19 15:55:19 by anakagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	*argv_to_i(int argc, char **argv, int *arg_size)
{
	char	**split;	
	int		*temp;
	int		i;

	if (argc == 2)
		split = ft_split(argv[1], ' ');
	else
		split = ++argv;
	if (!split)
		return (0);
	while (split[*arg_size])
		*arg_size += 1;
	temp = malloc(sizeof(int) * (*arg_size));
	if (!temp)
		ft_free(split, "Error");
	i = 0;
	while (split[i])
	{
		temp[i] = ft_atoi(split[i]);
		i++;
	}
	if (argc == 2)
		ft_free(split, NULL);
	return (temp);
}

t_dlst	*init_stcak_a(int argc, char **argv, t_dlst *stack_a, int *arg_size)
{
	int		*num;
	int		i;

	*arg_size = 0;
	if (1 > argc)
		return (0);
	num = argv_to_i(argc, argv, arg_size);
	if (!num)
		return (NULL);
	i = *arg_size;
	while (i)
	{
		stack_a = addt_dlst(num[i - 1], stack_a);
		if (!stack_a)
		{
			free(num);
			return (0);
		}
		i--;
	}
	free(num);
	return (stack_a);
}

void	initialize(t_dlst **stack_a, t_dlst **stack_b)
{
	t_dlst	*newt_dlst;

	newt_dlst = malloc(sizeof(t_dlst));
	if (!newt_dlst)
		ft_free_and_error(*stack_a, *stack_b, "Error");
	*stack_a = newt_dlst;
	(*stack_a)->next = *stack_a;
	(*stack_a)->prev = *stack_a;
	newt_dlst = malloc(sizeof(t_dlst));
	if (!newt_dlst)
		ft_free_and_error(*stack_a, *stack_b, "Error");
	*stack_b = newt_dlst;
	(*stack_b)->next = *stack_b;
	(*stack_b)->prev = *stack_b;
}

t_dlst	*addt_dlst(int value, t_dlst *sentinel)
{
	t_dlst	*newnodde;

	newnodde = malloc(sizeof(t_dlst));
	if (!newnodde)
	{
		free_stack(sentinel);
		return (0);
	}
	newnodde -> value = value;
	newnodde -> next = sentinel -> next;
	sentinel -> next -> prev = newnodde;
	sentinel -> next = newnodde;
	newnodde -> prev = sentinel;
	return (sentinel);
}

int	stack_size_check(t_dlst *stack)
{
	t_dlst	*temp;
	int		i;

	i = 0;
	temp = stack ->next;
	while (temp != stack)
	{
		i++;
		temp = temp -> next;
	}
	return (i);
}
