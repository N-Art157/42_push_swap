/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakagawashinta <nakagawashinta@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:36:10 by nakagawashi       #+#    #+#             */
/*   Updated: 2024/07/19 23:37:17 by nakagawashi      ###   ########.fr       */
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

void	ft_free(char **args, char *s, int argc)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (args[i])
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
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
