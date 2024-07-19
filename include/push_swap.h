/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakagaw <anakagaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 06:31:56 by nakagawashi       #+#    #+#             */
/*   Updated: 2024/07/19 20:11:42 by anakagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdbool.h>

# define BUFFER_SIZE 512

typedef struct t_dlst{
	long			value;
	long			index;
	struct t_dlst	*prev;
	struct t_dlst	*next;
}t_dlst;

typedef struct s_ans_list
{
	char				ans_char[4];
	struct s_ans_list	*next;
}t_ans_list;

typedef struct s_infos{
	t_dlst		*stack_a;
	t_dlst		*stack_b;
	t_ans_list	*ans;
}t_infos;

int			ft_issorted(t_dlst *stack);
void		arg_check(int argc, char **argv);
void		free_stack(t_dlst *stack);
void		ft_free(char **args, char *s, int argc);
void		ft_free_and_error(t_dlst *stack_a, t_dlst *stack_b, char *s);
int			medium_sort(t_dlst *a, t_dlst *b, int size, t_ans_list **ans);
int			swap(t_dlst *stack, int type, t_ans_list **ans);
int			rotate(t_dlst *stack, int type, t_ans_list **ans);
int			reverse_rotate(t_dlst *stack, int type, t_ans_list **ans);
int			push(t_dlst *from, t_dlst *to, int type, t_ans_list **ans);
long		ft_atol(char	*str, bool	*flag);
int			*argv_to_i(int argc, char **argv, int *arg_size);
t_dlst		*init_stcak_a(int argc, char **argv, t_dlst *a, int *arg_size);
void		initialize(t_dlst **stack_a, t_dlst **stack_b);
t_dlst		*addt_dlst(int value, t_dlst *sentinel);
int			stack_size_check(t_dlst *stack);
t_dlst		*addt_dlst(int value, t_dlst *sentinel);
int			sort_3(t_dlst *stack_a, int type, t_ans_list **ans);
void		sort_half(t_infos *infos, int b_size);
int			quick_sort(t_infos *infos, int arg_size);
int			short_sort(t_dlst	*stack, int size, int type, t_ans_list **ans);
void		compress(t_dlst *stack);
int			median_partition(t_infos *infos, int arg_size);
void		return_to_a(t_dlst *b, t_dlst *a, int size, t_ans_list **ans);
int			add_rule(t_ans_list **ans, const char *rule);
void		print_rules(t_ans_list *ans);
long		get_median(t_dlst *stack, int arg_size);
long		get_min_id(t_dlst *stack);
t_ans_list	*optimize_rules(t_ans_list *ans);
void		free_rules(t_ans_list **ans);
#endif