/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakagaw <anakagaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:56:32 by nakagawashi       #+#    #+#             */
/*   Updated: 2024/07/06 17:56:34 by anakagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_3(t_dlst *stack, int type, t_ans_list **ans)
{
	t_dlst	*head;

	if (ft_issorted(stack) == 0)
		return (0);
	head = stack -> next;
	if (head -> value < (*head).next -> value)
	{
		if (head -> value < (*stack).prev -> value)
		{
			swap(stack, type, ans);
			rotate(stack, type, ans);
		}
		else
			reverse_rotate(stack, type, ans);
	}
	else if (head -> value < (*stack).prev -> value)
		swap(stack, type, ans);
	else if ((*head).next -> value < (*stack).prev -> value)
		rotate(stack, type, ans);
	else
	{
		swap(stack, type, ans);
		reverse_rotate(stack, type, ans);
	}
	return (0);
}

int	short_sort(t_dlst	*stack, int size, int type, t_ans_list **ans)
{
	t_dlst	*head;
	int		i;

	i = 0;
	head = stack -> next;
	if (size == 2)
	{
		if (head -> value > head -> next -> value)
			i = swap(stack, type, ans);
		if (!i)
			return (0);
	}
	else if (size != 1)
		sort_3(stack, type, ans);
	return (1);
}

long	get_min_id(t_dlst *stack)
{
	t_dlst	*temp;
	t_dlst	*temp2;

	temp = stack->next;
	temp2 = temp->next;
	while (temp2 != stack)
	{
		if (temp->index > temp2->index)
			temp = temp2;
		temp2 = temp2->next;
	}
	return (temp->index);
}
