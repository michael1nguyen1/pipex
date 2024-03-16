/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:18:12 by linhnguy          #+#    #+#             */
/*   Updated: 2023/11/17 18:35:37 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*d;

	d = s;
	i = 0;
	while (i < n)
	{
		if (d[i] == (unsigned char) c)
			return ((void *) &s[i]);
		i++;
	}
	return (NULL);
}
