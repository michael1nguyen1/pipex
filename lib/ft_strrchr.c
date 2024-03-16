/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:04:22 by linhnguy          #+#    #+#             */
/*   Updated: 2023/11/17 18:38:31 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	c2;

	c2 = c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c2)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	return (NULL);
}
