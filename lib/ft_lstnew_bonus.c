/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:39:30 by linhnguy          #+#    #+#             */
/*   Updated: 2024/01/05 14:26:15 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_b_list	*ft_lstnew(void *content)
{
	t_b_list	*new;

	new = malloc (sizeof(t_b_list));
	if (!new)
		return (NULL);
	new -> content = content;
	new -> next = (NULL);
	return (new);
}
