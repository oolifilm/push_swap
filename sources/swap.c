/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:02:39 by leaugust          #+#    #+#             */
/*   Updated: 2024/10/24 20:11:17 by leaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_node **a)
{
	ft_printf("sa\n");
	swap(a);
}

void	sb(t_node **b)
{
	ft_printf("sb\n");
	swap(b);
}

void	ss(t_node **a, t_node **b)
{
	ft_printf("ss\n");
	swap(a);
	swap(b);
}
