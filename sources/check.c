/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:02:46 by leaugust          #+#    #+#             */
/*   Updated: 2024/10/24 20:11:05 by leaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	string_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			while (str[i + 1] == ' ')
				i++;
			if (str[i + 1] != '\0')
				return (1);
			else
				return (0);
		}
		i++;
	}
	return (0);
}

int	only_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	first_half_check(t_node **b, int nbr, int half_len)
{
	t_node	*current;

	current = *b;
	while (half_len > 0 && current)
	{
		if (current->nbr == nbr)
		{
			return (1);
		}
		current = current->next;
		half_len--;
	}
	return (0);
}

int	stacklen(t_node **stack)
{
	t_node	*current;
	int		i;

	i = 1;
	current = *stack;
	if (!stack || !(*stack))
		return (0);
	while (current->next != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}

int	double_check(t_node *a, int nbr)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
