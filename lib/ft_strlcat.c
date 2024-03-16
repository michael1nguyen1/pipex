/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:37:31 by linhnguy          #+#    #+#             */
/*   Updated: 2023/11/17 15:41:27 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (dsize == 0)
	{
		return (ft_strlen(src));
	}
	j = ft_strlen(dst);
	while (src[i] && j < (dsize - 1))
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	if (dsize > (j - i))
		dst[j] = '\0';
	if (dsize < j - i)
	{
		return (ft_strlen(src) + dsize);
	}
	return (ft_strlen(src) + (j - i));
}
