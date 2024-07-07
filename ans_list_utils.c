/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ans_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakagaw <anakagaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 08:02:07 by nakagawashi       #+#    #+#             */
/*   Updated: 2024/07/07 11:31:49 by anakagaw         ###   ########.fr       */
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

t_ans_list	*optimize_rules(t_ans_list *ans)
{
	ans = optimize_ss(ans);
	ans = optimize_rr(ans);
	ans = optimize_rrr(ans);
	ans = optimize_pp(ans);
	return (ans);
}
