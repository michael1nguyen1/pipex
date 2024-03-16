/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:06:27 by linhnguy          #+#    #+#             */
/*   Updated: 2023/11/17 18:37:15 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	char		t;
	size_t		len;

	i = 0;
	t = c;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == t)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	return (NULL);
}
