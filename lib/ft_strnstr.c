/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:09:52 by linhnguy          #+#    #+#             */
/*   Updated: 2023/11/18 20:05:07 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)

{
	size_t	needlelen;

	if (*n == 0)
		return ((char *)h);
	if (len == 0)
		return (NULL);
	needlelen = ft_strlen(n);
	while (*h && len >= needlelen)
	{
		if (*h == *n)
		{
			if (ft_strncmp(h, n, needlelen) == 0)
				return ((char *)h);
		}
		h++;
		len--;
	}
	return (NULL);
}
