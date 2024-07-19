/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakagaw <anakagaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:50:51 by nakagawashi       #+#    #+#             */
/*   Updated: 2024/07/06 16:56:58 by anakagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		partition_b(t_infos *infos, int arg_size, int *j);
long	get_min(t_dlst *stack);

int	return_to_b(t_infos *infos, int m)
{
	t_dlst	*stack_a;

	stack_a = infos->stack_a;
	if (infos->stack_a->prev->index + 1 == infos->stack_a->next->index)
	{
		rotate(infos->stack_a, 0, &infos->ans);
		m++;
	}
	else if (stack_a->prev->index + 1 == stack_a->next->next->index)
	{
		swap(infos->stack_a, 0, &infos->ans);
		rotate(infos->stack_a, 0, &infos->ans);
		m++;
	}
	else
		push(infos->stack_a, infos->stack_b, 1, &infos->ans);
	return (m);
}

void	sort_half(t_infos *infos, int b_size)
{
	int	i;
	int	j;
	int	n;
	int	m;

	if (b_size <= 3)
	{
		short_sort(infos->stack_b, b_size, 1, &infos->ans);
		return_to_a(infos->stack_b, infos->stack_a, b_size, &infos->ans);
		return ;
	}
	else
	{
		i = partition_b(infos, b_size, &j);
		sort_half(infos, b_size - i);
	}
	n = j;
	m = 0;
	while (j)
	{
		m = return_to_b(infos, m);
		j--;
	}
	sort_half(infos, n - m);
}

int	quick_sort(t_infos *infos, int arg_size)
{
	int	a_size;
	int	b_size;
	int	temp;

	b_size = median_partition(infos, arg_size);
	sort_half(infos, b_size);
	a_size = arg_size - b_size;
	temp = a_size;
	while (temp)
	{
		push(infos->stack_a, infos->stack_b, 1, &infos->ans);
		temp--;
	}
	sort_half(infos, a_size);
	return (0);
}

static int	do_pr(t_infos *infos, long *min_id, int n)
{
	push(infos->stack_b, infos->stack_a, 0, &infos->ans);
	rotate(infos->stack_a, 0, &infos->ans);
	*min_id += 1;
	n++;
	return (n);
}

int	partition_b(t_infos *infos, int arg_size, int *j)
{
	long	min_id;
	long	median;
	int		n;

	n = 0;
	*j = 0;
	min_id = get_min_id(infos->stack_b);
	median = get_median(infos->stack_b, arg_size);
	while (arg_size)
	{
		if (infos->stack_b->next->index == min_id)
		{
			n = do_pr(infos, &min_id, n);
		}
		else if (infos->stack_b -> next -> index > median)
		{
			push(infos->stack_b, infos->stack_a, 0, &infos->ans);
			*j += 1;
			n++;
		}
		else
			rotate(infos->stack_b, 1, &infos->ans);
		arg_size--;
	}
	return (n);
}
