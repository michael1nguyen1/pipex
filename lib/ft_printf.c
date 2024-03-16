/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:46:58 by linhnguy          #+#    #+#             */
/*   Updated: 2024/01/05 12:08:48 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checker(va_list *arg, const char *s)
{
	int		i;
	int		prtlen;
	int		check;

	i = 0;
	prtlen = 0;
	check = 0;
	while (s[i])
	{
		while (s[i] && s[i] != '%')
		{
			if (write(1, &s[i++], 1) == -1)
				return (-1);
			prtlen++;
		}
		if (s[i] && s[i++] == '%')
		{
			if (s[i] != '\0')
				check = ft_speci(arg, s[i++]);
			if (check == -1)
				return (-1);
			prtlen += check;
		}
	}
	return (prtlen);
}

int	ft_printf(const char *s, ...)
{
	int		prtlen;
	va_list	arg;

	va_start(arg, s);
	prtlen = ft_checker(&arg, s);
	va_end(arg);
	return (prtlen);
}
// int main()
// {
// 	char *s = "yes";
// 	ft_printf("%s", s);
// }