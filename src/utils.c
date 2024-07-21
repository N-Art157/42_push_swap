/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakagawashinta <nakagawashinta@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:42:27 by nakagawashi       #+#    #+#             */
/*   Updated: 2024/07/20 02:51:19 by nakagawashi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static long	rank_of_value(t_dlst *stack, t_dlst *node)
{
	t_dlst	*temp;
	long	i;

	i = 1;
	temp = stack -> next;
	while (temp != stack)
	{
		if (node -> value > temp -> value)
			i++;
		temp = temp -> next;
	}
	return (i);
}

void	compress(t_dlst *stack)
{
	t_dlst	*temp;
	long	i;

	temp = stack -> next;
	i = 0;
	while (temp != stack)
	{
		i = rank_of_value(stack, temp);
		temp -> index = i;
		temp = temp -> next;
	}
}

long	get_median(t_dlst *stack, int arg_size)
{
	t_dlst	*temp;
	long	median;	
	int		arg_half;
	long	i;

	temp = stack -> next;
	arg_half = arg_size / 2 + 1;
	i = rank_of_value(stack, temp);
	while (arg_half != i)
	{
		temp = temp -> next;
		i = rank_of_value(stack, temp);
	}
	median = temp -> index;
	return (median);
}

int	median_partition(t_infos *infos, int arg_size)
{
	long	median;
	int		n;

	n = 0;
	median = get_median(infos->stack_a, arg_size);
	while (arg_size)
	{
		if (infos->stack_a->next->index < median)
		{
			push(infos->stack_a, infos->stack_b, 1, &infos->ans);
			n++;
		}
		else
			rotate(infos->stack_a, 0, &infos->ans);
		arg_size--;
	}
	return (n);
}

void	return_to_a(t_dlst *b, t_dlst *a, int size, t_ans_list **ans)
{
	while (size)
	{
		push(b, a, 0, ans);
		rotate(a, 0, ans);
		size--;
	}
}
