/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakagaw <anakagaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:13:46 by nakagawashi       #+#    #+#             */
/*   Updated: 2024/07/06 17:29:45 by anakagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlst	*get_min(t_dlst *stack)
{
	t_dlst	*min;
	t_dlst	*temp;

	min = stack -> next;
	temp = min -> next;
	while (temp != stack)
	{
		if (min -> value > temp -> value)
		{
			min = temp;
			temp = temp -> next;
		}
		else
			temp = temp -> next;
	}
	return (min);
}

static void	perform_rotation(t_dlst *stack_a, int i, int size, t_ans_list **ans)
{
	if (i >= size - i)
	{
		i = size - i;
		while (i--)
			reverse_rotate(stack_a, 0, ans);
	}
	else if (i > 0)
	{
		while (i--)
			rotate(stack_a, 0, ans);
	}
}

static int	caluculate_rotate_count(t_dlst *stack_a, t_dlst *min)
{
	t_dlst	*temp;
	int		count;

	count = 0;
	temp = stack_a -> next;
	while (temp != min)
	{
		temp = temp -> next;
		count++;
	}
	return (count);
}

int	medium_sort(t_dlst *stack_a, t_dlst *stack_b, int size, t_ans_list **ans)
{
	t_dlst	*min;
	int		rotate_count;
	int		size_cp;

	rotate_count = 0;
	size_cp = size - 3;
	while (3 < size)
	{
		min = get_min(stack_a);
		rotate_count = caluculate_rotate_count(stack_a, min);
		perform_rotation(stack_a, rotate_count, size, ans);
		push(stack_a, stack_b, 1, ans);
		size--;
	}
	if (ft_issorted(stack_a) == 1)
		sort_3(stack_a, 0, ans);
	while (size_cp)
	{
		push(stack_b, stack_a, 0, ans);
		size_cp--;
	}
	return (0);
}
