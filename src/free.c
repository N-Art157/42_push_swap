/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakagaw <anakagaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:51:13 by nakagawashi       #+#    #+#             */
/*   Updated: 2024/07/07 11:32:27 by anakagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	free_stack(t_dlst *stack)
{
	t_dlst	*temp;
	t_dlst	*next;

	if (stack)
	{
		if (stack != stack -> next)
		{
			temp = stack->next;
			while (temp != stack)
			{	
				next = temp->next;
				free(temp);
				temp = next;
			}
		}
		free(stack);
	}
}

void	ft_free(char **args, char *s)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
	if (s)
	{
		ft_putendl_fd(s, 2);
		exit(1);
	}
}

void	ft_free_and_error(t_dlst *stack_a, t_dlst *stack_b, char *s)
{
	if (stack_a != NULL)
		free_stack(stack_a);
	if (stack_b != NULL)
		free_stack(stack_b);
	if (s != NULL)
		ft_putendl_fd(s, 2);
	if (!s)
		exit(0);
	exit(1);
}
