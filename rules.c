/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakagaw <anakagaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:31:50 by nakagawashi       #+#    #+#             */
/*   Updated: 2024/07/06 17:55:07 by anakagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	swap(t_dlst *stack, int type, t_ans_list **ans)
{
	t_dlst	*head;
	t_dlst	*second;
	int		size;

	size = stack_size_check(stack);
	if (!ans)
		return (0);
	head = stack -> next;
	second = head -> next;
	head -> prev = second;
	head -> next = second -> next;
	second -> next -> prev = head;
	second -> next = head;
	second -> prev = stack;
	if (size == 2)
		stack -> prev = stack -> next;
	stack -> next = second;
	if (type == 0)
		add_rule(ans, "sa");
	else if (type == 1)
		add_rule(ans, "sb");
	if (!ans)
		return (0);
	return (1);
}

int	rotate(t_dlst *stack, int type, t_ans_list **ans)
{
	t_dlst	*head;
	t_dlst	*last;

	if (!ans)
		return (0);
	head = stack -> next;
	last = stack -> prev;
	stack -> next = head -> next;
	stack -> prev = head;
	head -> next = stack;
	head -> prev = last;
	last -> next = head;
	stack -> next -> prev = stack;
	if (type == 0)
		add_rule(ans, "ra");
	else if (type == 1)
		add_rule(ans, "rb");
	if (!ans)
		return (0);
	return (1);
}

int	reverse_rotate(t_dlst *stack, int type, t_ans_list **ans)
{
	t_dlst	*head;
	t_dlst	*last;

	if (!ans)
		return (0);
	head = stack -> next;
	last = stack -> prev;
	stack -> next = last;
	stack -> prev = last -> prev;
	last -> prev -> next = stack;
	head -> prev = last;
	last -> prev = stack;
	last -> next = head;
	if (type == 0)
		add_rule(ans, "rra");
	else if (type == 1)
		add_rule(ans, "rrb");
	if (!ans)
		return (0);
	return (1);
}

int	push(t_dlst *stack_from, t_dlst *stack_to, int type, t_ans_list **ans)
{
	t_dlst	*temp;
	t_dlst	*temp2;

	if (!ans)
		return (0);
	temp = stack_from -> next;
	temp2 = temp -> next;
	stack_from -> next = temp -> next;
	temp2 -> prev = stack_from;
	temp -> next = stack_to -> next;
	stack_to -> next -> prev = temp;
	stack_to -> next = temp;
	temp -> prev = stack_to;
	if (type == 0)
		add_rule(ans, "pa");
	else if (type == 1)
		add_rule(ans, "pb");
	if (!ans)
		return (0);
	return (1);
}

long	ft_atol(char	*str)
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
	return (n * negative);
}
