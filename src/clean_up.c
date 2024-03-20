/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:14:42 by linhnguy          #+#    #+#             */
/*   Updated: 2024/03/20 16:17:26 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int free_array_error(char **array)
{
	int i;
	
	i = 0;
	while(array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (-1);
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