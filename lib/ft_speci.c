/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_speci.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:47:17 by linhnguy          #+#    #+#             */
/*   Updated: 2024/01/05 12:09:23 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_speci(va_list *arg, char s)
{
	int	count;

	count = 0;
	if (s == 'c')
		return (printc(va_arg(*arg, int)));
	else if (s == 's')
		return (prints(va_arg(*arg, char *)));
	else if (s == 'x' || s == 'X')
		return (printx(va_arg(*arg, unsigned int), s, &count));
	else if (s == 'i' || s == 'd')
		return (printnbr(va_arg(*arg, int), &count));
	else if (s == 'u')
		return (printnbr(va_arg(*arg, unsigned int), &count));
	else if (s == 'p')
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		if (printx(va_arg(*arg, unsigned long), s, &count) == -1)
			return (-1);
		return (count + 2);
	}
	else if (s == '%')
		return (write(1, "%", 1));
	return (0);
}
