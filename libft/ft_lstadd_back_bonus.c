/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:00:48 by linhnguy          #+#    #+#             */
/*   Updated: 2024/01/05 14:26:15 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_b_list **lst, t_b_list *new)
{
	t_b_list	*last;

	if (!new)
		return ;
	if (*lst == 0)
	{
		*lst = new;
	}
	else
	{
		last = (ft_lstlast (*lst));
		last -> next = new;
	}
}
