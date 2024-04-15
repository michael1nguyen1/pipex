/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:20:11 by linhnguy          #+#    #+#             */
/*   Updated: 2024/04/15 22:39:29 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_path(t_pipex *data, char **argv)
{
	if (!data->command_path1 && !data->command_path2)
	{
		ft_printf(2,
			"pipex: command not found: %s\npipex: command not found: %s\n",
			argv[2], argv[3]);
		full_clean(NULL, data);
		exit(EXIT_FAILURE);
	}
	else if (!data->command_path1)
	{
		ft_printf(2, "pipex: command not found: %s\n", argv[2]);
		full_clean(NULL, data);
		exit(EXIT_FAILURE);
	}
	else if (!data->command_path2)
	{
		ft_printf(2, "pipex: command not found: %s\n", argv[3]);
		full_clean(NULL, data);
		exit(EXIT_FAILURE);
	}
}

void	check_access(char *path, char **path_array, t_pipex *data, int *count)
{
	int		j;
	char	*tmp;

	j = 0;
	while (path_array[j] != NULL)
	{
		tmp = make_whole_path(path_array[j], path);
		if (!tmp)
		{
			full_clean("make_whole_path failed", data);
			exit(-1);
		}
		if (access(tmp, F_OK) == 0)
		{
			initialize_path(tmp, *count, data);
			free(tmp);
		}
		else
			free(tmp);
		j++;
	}
	(*count)++;
}

void	arg_has_space(char *argv, char **path_array, t_pipex *data, int *count)
{
	int		j;
	int		command_len;
	char	path[100];

	j = 0;
	command_len = 0;
	while (argv[command_len] != ' ')
		command_len++;
	while (j < command_len)
	{
		path[j] = argv[j];
		j++;
	}
	path[j] = '\0';
	check_access(path, path_array, data, count);
	initialize_path(path, *count, data);
}
