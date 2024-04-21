/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:14:42 by linhnguy          #+#    #+#             */
/*   Updated: 2024/04/18 17:51:50 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	free_array_error(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (false);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

bool	full_clean(char *s, t_pipex *data)
{
	int	i;

	i = 0;
	if (s)
		ft_printf(2, "%s\n", s);
	if (data->command_path1)
		free(data->command_path1);
	if (data->command_path2)
		free(data->command_path2);
	if (data->new_argv)
	{
		while (data->new_argv[i])
			free(data->new_argv[i++]);
		free(data->new_argv);
	}
	if (data->fd[0] >= 0)
		close(data->fd[0]);
	if (data->fd[1] >= 0)
		close(data->fd[1]);
	return (false);
}
