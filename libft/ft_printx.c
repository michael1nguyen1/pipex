/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:45:37 by linhnguy          #+#    #+#             */
/*   Updated: 2024/04/07 18:02:54 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printx(int fd, unsigned long n, char s, int *c)
{
	char	*hexlow;
	char	*hexup;

	hexlow = "0123456789abcdef";
	hexup = "0123456789ABCDEF";
	if (n > 15)
	{
		if (printx(fd, n / 16, s, c) == -1)
			return (-1);
	}
	if (s == 'x' || s == 'p')
	{
		(*c)++;
		if (write (fd, &hexlow[n % 16], 1) == -1)
			return (-1);
	}
	if (s == 'X')
	{
		(*c)++;
		if (write (fd, &hexup[n % 16], 1) == -1)
			return (-1);
	}
	return (*c);
}
