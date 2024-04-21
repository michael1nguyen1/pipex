/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:53:16 by linhnguy          #+#    #+#             */
/*   Updated: 2024/04/20 18:10:42 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

bool	get_new_argv(t_pipex *data, char **argv, int flag)
{
	char	newstr[300];

	if (flag == 1)
	{
		prep_split(argv[2], newstr);
		data->new_argv = ft_split(newstr, '\a');
		if (!data->new_argv)
			return (full_clean("split failed for first argv\n", data));
	}
	else
	{
		prep_split(argv[3], newstr);
		data->new_argv = ft_split(newstr, '\a');
		if (!data->new_argv)
			return (full_clean("split failed for second argv\n", data));
	}
	if (!(trim_arg(data)))
		return (full_clean("trim arg failed\n", data));
	return (true);
}

void	execute(t_pipex *data, char **argv, char**envp, int flag)
{
	char	*command_path;

	if (flag == 1)
	{
		command_path = data->command_path1;
		dup2(data->fd[0], STDIN_FILENO);
		dup2(data->pipes[1], STDOUT_FILENO);
	}
	else
	{
		command_path = data->command_path2;
		dup2(data->pipes[0], STDIN_FILENO);
		dup2(data->fd[1], STDOUT_FILENO);
	}
	if (!get_new_argv(data, argv, flag))
		exit(EXIT_FAILURE);
	close(data->pipes[0]);
	close(data->pipes[1]);
	// for (int i = 0; data->new_argv[i]; i++)
	// 	ft_printf(2, "%s\n", data->new_argv[i]);
	// ft_printf(2, "command path is %s\n", command_path);
	execve(command_path, data->new_argv, envp);
	exit(127);
}

void	openfiles(t_pipex *data, char **argv)
{
	data->fd[0] = open(argv[1], O_RDONLY);
	data->fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fd[0] == -1)
		ft_printf(2, "pipex: %s: %s\n", argv[1], strerror(errno));
	if (data->fd[1] == -1)
		ft_printf(2, "pipex: %s: %s\n", argv[4], strerror(errno));
}

bool	forking(char **argv, char **envp, t_pipex *data)
{
	int	i;

	i = 1;
	if (pipe(data->pipes) < 0)
	{
		ft_printf(2, "creating pipe failed\n");
		return (false);
	}
	openfiles(data, argv);
	while (i <= 2)
	{
		if (data->fd[0] == -1 || data->fd[1] == -1)
		{
			i++;
			continue ;
		}
		data->pids[i - 1] = fork();
		if (data->pids[i - 1] == 0)
			execute(data, argv, envp, i);
		i++;
	}
	close(data->pipes[0]);
	close(data->pipes[1]);
	full_clean(NULL, data);
	return (true);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	data = (t_pipex){0};
	if (argc == 5)
	{
		if (!check_argv(argv))
			exit (127);
		if (!make_envir_var_array(argv, envp, &data))
			return (EXIT_FAILURE);
		if (!forking(argv, envp, &data))
			full_clean(NULL, &data);
		if (!wait_childs(&data))
			return (EXIT_FAILURE);
	}
	else
	{
		ft_printf(2, "Error!! Usage: ./pipex file1 cmd1 cmd2 file2\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
