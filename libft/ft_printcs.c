/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:18:42 by linhnguy          #+#    #+#             */
/*   Updated: 2024/04/07 18:01:48 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printc(int fd, char s)
{
	return (write(fd, &s, 1));
}

int	prints(int fd, char *s)
{
	if (!s)
		return (prints(fd, "(null)"));
	return (write(fd, s, ft_strlen(s)));
}
