/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:18:42 by linhnguy          #+#    #+#             */
/*   Updated: 2024/01/05 12:08:45 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printc(char s)
{
	return (write(1, &s, 1));
}

int	prints(char *s)
{
	if (!s)
		return (prints("(null)"));
	return (write(1, s, ft_strlen(s)));
}
