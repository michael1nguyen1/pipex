/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:44:09 by linhnguy          #+#    #+#             */
/*   Updated: 2024/01/05 12:09:14 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printnbr(long n, int *c)
{
	char	b;

	if (n < 0)
	{
		(*c)++;
		if (write(1, "-", 1) == -1)
			return (-1);
		n = -n;
	}
	if (n > 9)
	{
		if (printnbr(n / 10, c) == -1)
			return (-1);
	}
	b = n % 10 + '0';
	(*c)++;
	if (write(1, &b, 1) == -1)
		return (-1);
	return (*c);
}
