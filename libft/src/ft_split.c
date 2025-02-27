/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:16:56 by leaugust          #+#    #+#             */
/*   Updated: 2024/10/23 13:16:16 by leaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**bigfree(char **bigtab)
{
	int	i;

	i = 0;
	while (bigtab[i])
	{
		free(bigtab[i]);
		i++;
	}
	free(bigtab);
	return (NULL);
}

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	if (s[i] != '\0')
		count++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static char	*ft_split_process(char const *s, char c, int *start)
{
	int	len;
	int	i;

	len = 0;
	while (s[*start] && s[*start] == c)
		(*start)++;
	i = *start;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	i = *start;
	*start += len;
	return (ft_substr(s, i, len));
}

char	**ft_split(char const *s, char c)
{
	char	**bigtab;
	int		count_words;
	int		i;
	int		start;

	if (!s)
		return (NULL);
	start = 0;
	count_words = ft_count_words(s, c);
	bigtab = malloc(sizeof(char *) * (count_words + 1));
	if (!bigtab)
		return (NULL);
	i = 0;
	while (i < count_words)
	{
		bigtab[i] = ft_split_process(s, c, &start);
		if (bigtab[i] == NULL)
			return (bigfree(bigtab));
		i++;
	}
	bigtab[i] = 0;
	return (bigtab);
}
