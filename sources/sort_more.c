/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:02:28 by leaugust          #+#    #+#             */
/*   Updated: 2024/10/24 20:11:24 by leaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	index_void(t_node **stack)
{
	t_node	*current;

	current = *stack;
	while (current)
	{
		current->index = 0;
		current = current->next;
	}
}

void	index_init(t_node **stack, int len)
{
	int		i;
	int		min;
	t_node	*current;
	t_node	*checkpoint;

	index_void(stack);
	i = 1;
	while (len > 0)
	{
		min = INT_MAX;
		current = *stack;
		while (current)
		{
			if (current->nbr < min && current->index == 0)
			{
				min = current->nbr;
				checkpoint = current;
			}
			current = current->next;
		}
		checkpoint->index = i;
		i++;
		len--;
	}
}

void	sort_next(t_node **a, t_node **b)
{
	int		half;
	t_node	*checkpoint;

	checkpoint = NULL;
	while (*b)
	{
		checkpoint = find_max(b);
		half = first_half_check(b, checkpoint->nbr, (stacklen(b) / 2));
		while ((*b)->nbr != checkpoint->nbr)
		{
			if (half == 1)
				rb(b);
			else
				rrb(b);
		}
		pa(a, b);
	}
}

void	sort_more(t_node **a, t_node **b, int *start, int *end)
{
	index_init(a, stacklen(a));
	while (*a)
	{
		if ((*a)->index <= (*start))
		{
			pb(a, b);
			rb(b);
			(*start)++;
			(*end)++;
		}
		else if ((*a)->index > (*start) && (*a)->index < (*end))
		{
			pb(a, b);
			(*start)++;
			(*end)++;
		}
		else if ((*a)->index >= (*end))
			ra(a);
	}
	sort_next(a, b);
}
