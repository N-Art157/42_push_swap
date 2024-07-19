/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakagaw <anakagaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 06:30:39 by nakagawashi       #+#    #+#             */
/*   Updated: 2024/07/19 16:08:18 by anakagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	perform_sort(t_infos *infos, int arg_size)
{
	if (infos->stack_a && !ft_issorted(infos->stack_a))
		ft_free_and_error(infos->stack_a, infos->stack_b, NULL);
	infos->ans = malloc(sizeof(t_ans_list));
	infos->ans->next = NULL;
	ft_strlcpy(infos->ans->ans_char, "", ft_strlen(""));
	if (infos->stack_a && arg_size <= 3)
		short_sort(infos->stack_a, arg_size, 0, &infos->ans);
	else if (infos->stack_a && arg_size <= 6)
		medium_sort(infos->stack_a, infos->stack_b, arg_size, &infos->ans);
	else if (infos->stack_a)
	{
		compress(infos->stack_a);
		quick_sort(infos, arg_size);
	}
}

int	main(int argc, char **argv)
{
	int			arg_size;
	t_dlst		*stack_a;
	t_dlst		*stack_b;
	t_ans_list	*ans;
	t_infos		infos;

	ans = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (0);
	arg_check(argc, argv);
	initialize(&stack_a, &stack_b);
	stack_a = init_stcak_a(argc, argv, stack_a, &arg_size);
	infos.ans = ans;
	infos.stack_a = stack_a;
	infos.stack_b = stack_b;
	perform_sort(&infos, arg_size);
	print_rules(infos.ans);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
