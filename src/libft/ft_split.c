/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 11:18:54 by hfadyl            #+#    #+#             */
/*   Updated: 2019/10/30 23:09:08 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordscount(char const *s, char c)
{
	int i;
	int count;

	if (s == 0)
		return (0);
	i = -1;
	count = 0;
	while (++i < (int)ft_strlen(s))
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			count++;
	}
	if (s[0] != c && s[0])
		count++;
	return (count);
}

static char	**fill(char **p, char const *s, int words, char c)
{
	int j;
	int i;
	int lenword;

	j = -1;
	while (++j < words && *s)
	{
		while (*s == c)
			s++;
		i = 0;
		while (s[i] != c && s[i])
			i++;
		if (!(p[j] = (char *)malloc(i * sizeof(char) + 1)))
		{
			while (j--)
				free(p[j]);
			free(p);
		}
		lenword = -1;
		while (++lenword < i)
			p[j][lenword] = *s++;
		p[j][lenword] = '\0';
	}
	p[j] = NULL;
	return (p);
}

char		**ft_split(char const *s, char c)
{
	char	**p;
	int		words;

	words = wordscount(s, c);
	p = (char**)malloc((words + 1) * sizeof(char*));
	if (p == 0)
		return (0);
	return (fill(p, s, words, c));
}
