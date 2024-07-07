/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ans_list_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakagaw <anakagaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:46:39 by nakagawashi       #+#    #+#             */
/*   Updated: 2024/07/07 11:31:34 by anakagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ans_list	*optimize_ss(t_ans_list *ans)
{
	t_ans_list	*optimized;
	t_ans_list	*current;

	optimized = NULL;
	current = ans;
	while (current && current->next)
	{
		if ((!ft_strncmp(current->ans_char, "sa", 2)
				&& !ft_strncmp(current->next->ans_char, "sb", 2))
			|| (!ft_strncmp(current->ans_char, "sb", 2)
				&& !ft_strncmp(current->next->ans_char, "sa", 2)))
		{
			add_rule(&optimized, "ss");
			current = current->next->next;
		}
		else
		{
			add_rule(&optimized, current->ans_char);
			current = current->next;
		}
	}
	if (current)
		add_rule(&optimized, current->ans_char);
	free_rules(&ans);
	return (optimized);
}

t_ans_list	*optimize_rr(t_ans_list *ans)
{
	t_ans_list	*optimized;
	t_ans_list	*current;

	optimized = NULL;
	current = ans;
	while (current && current->next)
	{
		if ((!ft_strncmp(current->ans_char, "ra", 2)
				&& !ft_strncmp(current->next->ans_char, "rb", 2))
			|| (!ft_strncmp(current->ans_char, "rb", 2)
				&& !ft_strncmp(current->next->ans_char, "ra", 2)))
		{
			add_rule(&optimized, "rr");
			current = current->next->next;
		}
		else
		{
			add_rule(&optimized, current->ans_char);
			current = current->next;
		}
	}
	if (current)
		add_rule(&optimized, current->ans_char);
	free_rules(&ans);
	return (optimized);
}

t_ans_list	*optimize_rrr(t_ans_list *ans)
{
	t_ans_list	*optimized;
	t_ans_list	*current;

	optimized = NULL;
	current = ans;
	while (current && current->next)
	{
		if ((!ft_strncmp(current->ans_char, "rra", 3)
				&& !ft_strncmp(current->next->ans_char, "rrb", 3))
			|| (!ft_strncmp(current->ans_char, "rrb", 3)
				&& !ft_strncmp(current->next->ans_char, "rra", 3)))
		{
			add_rule(&optimized, "rrr");
			current = current->next->next;
		}
		else
		{
			add_rule(&optimized, current->ans_char);
			current = current->next;
		}
	}
	if (current)
		add_rule(&optimized, current->ans_char);
	free_rules(&ans);
	return (optimized);
}

t_ans_list	*optimize_pp(t_ans_list *ans)
{
	t_ans_list	*optimized;
	t_ans_list	*current;

	optimized = NULL;
	current = ans;
	while (current && current->next)
	{
		if ((!ft_strncmp(current->ans_char, "pa", 2)
				&& !ft_strncmp(current->next->ans_char, "pb", 2))
			|| (!ft_strncmp(current->ans_char, "pb", 2)
				&& !ft_strncmp(current->next->ans_char, "pa", 2)))
			current = current->next->next;
		else
		{
			add_rule(&optimized, current->ans_char);
			current = current->next;
		}
	}
	if (current)
		add_rule(&optimized, current->ans_char);
	free_rules(&ans);
	return (optimized);
}
