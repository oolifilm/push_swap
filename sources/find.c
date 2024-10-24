/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:05:27 by leaugust          #+#    #+#             */
/*   Updated: 2024/10/24 20:05:51 by leaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*find_max(t_node **stack)
{
	int		max;
	t_node	*max_nbr;
	t_node	*current;

	max = INT_MIN;
	max_nbr = NULL;
	current = *stack;
	while (current != NULL)
	{
		if (current->nbr > max)
		{
			max_nbr = current;
			max = current->nbr;
		}
		current = current->next;
	}
	return (max_nbr);
}

t_node	*find_min(t_node **stack)
{
	int		min;
	t_node	*min_nbr;
	t_node	*current;

	min = INT_MAX;
	min_nbr = NULL;
	current = *stack;
	while (current != NULL)
	{
		if (current->nbr < min)
		{
			min_nbr = current;
			min = current->nbr;
		}
		current = current->next;
	}
	return (min_nbr);
}
