/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:14:42 by linhnguy          #+#    #+#             */
/*   Updated: 2024/03/27 17:33:51 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool free_array_error(char **array)
{
	int i;
	
	i = 0;
	while(array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (false);
}

void free_array(char **array)
{
	int i;
	
	i = 0;
	while(array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
bool free_bool(char *freeing, char *message)
{
	int i;
	i = 0;

	free(freeing);
	ft_printf(message);
	return (false);
}