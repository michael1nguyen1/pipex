/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childsft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:07:17 by linhnguy          #+#    #+#             */
/*   Updated: 2024/04/22 14:03:35 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*child1(char **argv, t_pipex *data, int flag)
{
	char	*command_path;

	if (data->fd[0] == -1)
	{
		ft_printf(2, "pipex: %s: %s\n", argv[1], strerror(errno));
		exit (EXIT_FAILURE);
	}
	check_argv(data, argv, flag);
	command_path = data->command_path1;
	dup2(data->fd[0], STDIN_FILENO);
	dup2(data->pipes[1], STDOUT_FILENO);
	return (command_path);
}

char	*child2(char **argv, t_pipex *data, int flag)
{
	char	*command_path;

	if (data->fd[1] == -1)
	{
		ft_printf(2, "pipex: %s: %s\n", argv[4], strerror(errno));
		exit (EXIT_FAILURE);
	}
	check_argv(data, argv, flag);
	command_path = data->command_path2;
	dup2(data->fd[1], STDOUT_FILENO);
	dup2(data->pipes[0], STDIN_FILENO);
	return (command_path);
}

void	argv2_checker(char **argv, t_pipex *data)
{
	if (argv[2][0] == '\0')
	{
		ft_printf(2, "pipex: command not found: %s\n", argv[2]);
		full_clean(NULL, data);
		exit (126);
	}
	else if (only_space(argv[2], ' '))
	{
		ft_printf(2, "pipex: command not found: %s\n", argv[2]);
		full_clean(NULL, data);
		exit (127);
	}
}

void	argv3_checker(char **argv, t_pipex *data)
{
	if (argv[3][0] == '\0')
	{
		ft_printf(2, "pipex: command not found: %s\n", argv[3]);
		full_clean(NULL, data);
		exit (126);
	}
	else if (only_space(argv[3], ' '))
	{
		ft_printf(2, "pipex: command not found: %s\n", argv[3]);
		full_clean(NULL, data);
		exit (127);
	}
}

bool	no_path_check(char **argv, t_pipex *data)
{
	if (!(access(argv[2], F_OK) || (!(ft_strchr(argv[2], '/')))))
		data->command_path1 = ft_strdup(argv[2]);
	if (access(argv[3], F_OK) || (!(ft_strchr(argv[3], '/'))))
		return (true);
	else
		data->command_path2 = ft_strdup(argv[3]);
	return (true);
}
