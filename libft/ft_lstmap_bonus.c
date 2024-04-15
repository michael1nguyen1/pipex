/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:39:09 by linhnguy          #+#    #+#             */
/*   Updated: 2024/04/15 22:13:12 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_b_list	*ft_lstmap(t_b_list *lst, void *(*f)(void *), void (*del)(void *))

{
	t_b_list	*first;
	t_b_list	*new;
	void		*tmp;

	if (!f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		tmp = (*f)((lst -> content));
		new = (ft_lstnew(tmp));
		if (!new)
		{
			ft_lstclear(&first, del);
			del(tmp);
			return (NULL);
		}
		ft_lstadd_back(&first, new);
		lst = lst -> next;
	}
	return (first);
}
