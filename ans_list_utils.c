/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ans_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakagaw <anakagaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 08:02:07 by nakagawashi       #+#    #+#             */
/*   Updated: 2024/07/07 12:05:24 by anakagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	free_rules(t_ans_list **ans)
{
	t_ans_list	*temp;

	while (*ans)
	{
		temp = *ans;
		*ans = (*ans)->next;
		free(temp);
	}
}

int	add_rule(t_ans_list **ans, const char *rule)
{
	t_ans_list	*new_node;
	t_ans_list	*temp;

	new_node = malloc(sizeof(t_ans_list));
	if (!new_node)
	{
		free_rules(ans);
		*ans = NULL;
		return (0);
	}
	ft_strlcpy(new_node->ans_char, rule, sizeof(new_node->ans_char));
	new_node->next = NULL;
	if (!(*ans))
		*ans = new_node;
	else
	{
		temp = *ans;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
	return (1);
}

void	print_rules(t_ans_list *ans)
{
	t_ans_list	*temp;

	if (!ans)
	{
		ft_putendl_fd("Error", 1);
		return ;
	}
	temp = ans->next;
	free(ans);
	ans = temp;
	ans = optimize_rules(ans);
	temp = ans;
	while (temp)
	{
		ft_putendl_fd(temp->ans_char, 1);
		temp = temp->next;
	}
	free_rules(&ans);
}

static int	optimize_pair(t_ans_list **optimized, t_ans_list **current)
{
	const char	*a;
	const char	*b;

	a = (*current)->ans_char;
	b = (*current)->next->ans_char;

	if ((ft_strncmp(a, "sa", 2) == 0 && ft_strncmp(b, "sb", 2) == 0)
		|| (ft_strncmp(a, "sb", 2) == 0 && ft_strncmp(b, "sa", 2) == 0))
		return (add_rule(optimized, "ss"), 1);
	if ((ft_strncmp(a, "ra", 2) == 0 && ft_strncmp(b, "rb", 2) == 0)
		|| (ft_strncmp(a, "rb", 2) == 0 && ft_strncmp(b, "ra", 2) == 0))
		return (add_rule(optimized, "rr"), 1);
	if ((ft_strncmp(a, "rra", 3) == 0 && ft_strncmp(b, "rrb", 3) == 0)
		|| (ft_strncmp(a, "rrb", 3) == 0 && ft_strncmp(b, "rra", 3) == 0))
		return (add_rule(optimized, "rrr"), 1);
	if ((ft_strncmp(a, "pa", 2) == 0 && ft_strncmp(b, "pb", 2) == 0)
		|| (ft_strncmp(a, "pb", 2) == 0 && ft_strncmp(b, "pa", 2) == 0))
		return (1);
	return (0);
}

t_ans_list	*optimize_rules(t_ans_list *ans)
{
	t_ans_list	*optimized;
	t_ans_list	*current;

	optimized = NULL;
	current = ans;
	while (current && current->next)
	{
		if (optimize_pair(&optimized, &current))
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

