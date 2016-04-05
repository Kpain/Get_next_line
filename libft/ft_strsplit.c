/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpain <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 11:03:42 by kpain             #+#    #+#             */
/*   Updated: 2015/12/08 14:43:58 by kpain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		n_word(char const *s, char c)
{
	size_t i;
	size_t is_word;

	i = 0;
	is_word = 0;
	while (s != NULL && s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != '\0')
			is_word++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (is_word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**table;
	int		i;
	int		j;
	int		k;
	int		word;

	k = 0;
	i = 0;
	word = n_word(s, c);
	if (!(table = (char **)malloc(sizeof(char *) * (word + 1))))
		return (NULL);
	table[word] = NULL;
	while (k < word)
	{
		j = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			j++;
		}
		table[k++] = ft_strsub(s, (i - j), j);
	}
	return (table);
}
