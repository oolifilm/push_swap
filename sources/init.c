/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:01:54 by leaugust          #+#    #+#             */
/*   Updated: 2024/10/24 22:20:12 by leaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	syntax_error(char *argument)
{
	int	i;

	i = 0;
	if (argument[i] == '+' || argument[i] == '-')
	{
		if (!(argument[i + 1] >= '0' && argument[i + 1] <= '9'))
			return (0);
		i++;
	}
	while (argument[i])
	{
		if (!(argument[i] >= '0' && argument[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	error(t_node **a, t_node **b, char **argv, int string)
{
	write(2, "Error\n", 6);
	free_all(a, b, argv, string);
	exit(1);
}

long	ft_atol(const char *nptr)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (nptr[i] == 32 || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb * sign);
}

void	make_node(t_node **stack, int n)
{
	t_node	*node;
	t_node	*current;

	if (!stack)
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (*stack == NULL)
	{
		*stack = node;
	}
	else
	{
		current = *stack;
		while (current->next != NULL)
			current = current->next;
		current->next = node;
	}
}

void	init_stack_a(t_node **a, t_node **b, char **argv, int string)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (!syntax_error(argv[i]))
			error(a, b, argv, string);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			error(a, b, argv, string);
		if (double_check(*a, (int)n) == 1)
			error(a, b, argv, string);
		make_node(a, (int)n);
		i++;
	}
}
