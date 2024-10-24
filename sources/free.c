/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:04:30 by leaugust          #+#    #+#             */
/*   Updated: 2024/10/24 20:38:53 by leaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_all(t_node **a, t_node **b, char **argv, int string)
{
	free_stack(a);
	free_stack(b);
	if (string == 1)
	{
		free_split(argv);
		argv = NULL;
	}
}

void	free_split(char **bigtab)
{
	int	i;

	i = 0;
	if (bigtab == NULL || !(*bigtab))
		return ;
	while (bigtab[i])
	{
		free(bigtab[i]);
		i++;
	}
	free(bigtab);
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current != NULL)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
