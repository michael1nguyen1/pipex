/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:50:51 by linhnguy          #+#    #+#             */
/*   Updated: 2024/01/07 18:37:06 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_allstrs(char const **s, char c)
{
	int			i;
	char		*out;
	const char	*tmp;
	int			substrlen;

	substrlen = 0;
	i = 0;
	tmp = *s;
	while (*tmp)
	{
		if (*tmp == c)
			break ;
		substrlen++;
		tmp++;
	}
	out = ft_substr(*s, 0, substrlen);
	if (!out)
		return (NULL);
	while (c && *tmp == c)
		tmp++;
	*s = tmp;
	return (out);
}

static int	ft_numberofstrs(const char *s, char c)
{
	size_t	i;
	int		numberofstrs;

	if (!s[0])
		return (0);
	if (c == 0)
		return (1);
	i = 1;
	numberofstrs = 0;
	while (s[i])
	{
		if (s[i] == c && s[i] != s[i - 1])
		{
			numberofstrs++;
			while (s[i] == c)
				i++;
		}
		else
			i++;
	}
	if (s[i - 1] != c)
		numberofstrs++;
	return (numberofstrs);
}

static char	**cleararray(char **array, int i)
{
	while (i >= 0)
		free(array[i--]);
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		strings;
	char	**array;

	i = 0;
	if (!s)
		return (NULL);
	strings = ft_numberofstrs(s, c);
	array = malloc ((strings + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (*s == c)
		s++;
	while (i < strings)
	{
		array [i] = ft_allstrs(&s, c);
		if (!array[i])
			return (cleararray(array, i - 1));
		i++;
	}
	array[i] = NULL;
	return (array);
}
