/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:45:35 by leaugust          #+#    #+#             */
/*   Updated: 2024/10/24 22:42:05 by leaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		string;
	char	**arguments;

	a = NULL;
	b = NULL;
	string = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		if (!argv[1][0] || !only_space(argv[1]))
			error(&a, &b, argv, string);
		arguments = ft_split(argv[1], ' ');
		string = 1;
		if (!arguments || !string_check(argv[1]))
			return (free_all(&a, &b, arguments, string), 0);
	}
	else
		arguments = &argv[1];
	init_stack_a(&a, &b, arguments, string);
	if (!stack_sorted(&a))
		sort_stack(&a, &b);
	return (free_all(&a, &b, arguments, string), 0);
}
