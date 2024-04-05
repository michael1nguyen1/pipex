/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:53:16 by linhnguy          #+#    #+#             */
/*   Updated: 2024/04/04 18:41:10 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

bool get_new_argv(t_pipex *data, char** argv , int flag)
{
	if (flag == 1)
	{
		data->new_argv = ft_split(argv[2], ' ');
		if (!data->new_argv)
		{
			perror("split failed for first argv");
			return (false);
		}
	}
	else
	{
		data->new_argv = ft_split(argv[3], ' ');
		if (!data->new_argv)
		{
			perror("split failed for first argv");
			return (false);
		}
	}
	return (true);
}

void execute(t_pipex *data, char** argv, char**envp, int flag)
{
	char *command_path;

	if (flag == 1)
	{	
		command_path = data->command_path1;
		dup2(data->fd[0], STDIN_FILENO);
	}
	else
	{
		command_path = data->command_path2;
		dup2(data->fd[0], STDIN_FILENO);
		dup2(data->fd[1], STDOUT_FILENO);
	}
	if (!get_new_argv(data, argv, flag))
		exit(EXIT_FAILURE);
	close(data->pipes[0]);
	close(data->pipes[1]);
	if (execve(command_path, data->new_argv, envp) == -1)
		perror ("execve");
	exit(EXIT_FAILURE);
}
void openfiles(t_pipex *data, char** argv)
{
    data->fd[0] = open(argv[1], O_RDONLY);
	data->fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    
    if (data->fd[0] == -1 || data->fd[1] == -1) 
	{
        perror("open");
        exit(EXIT_FAILURE);
    }
}

int forking(char **argv, char **envp, t_pipex *data)
{
	int i;
	
	i = 1;
	if (pipe(data->pipes) < 0)
	{
		perror("creating pipe failed");
		return (-1);
	}
	openfiles(data, argv);
	while (i <= 2)
	{
		data->pids[i - 1] = fork();
		if (data->pids[i - 1] == 0)
			execute(data, argv, envp, i);
		i++;
	}
	close(data->fd[0]);
	close(data->fd[1]);
	close(data->pipes[0]);
	close(data->pipes[1]);
	return (0);
}

bool wait_childs(t_pipex *data)
{
	int i = 0;
	int status[2];

	while (i < 2)
	{
		waitpid(data->pids[i], &status[i], 0 );
		i++;
	}
	if (status[0] != 0 || status[1] != 0)
		return (false);
	return (true);
}

int main (int argc, char **argv, char **envp)
{
	t_pipex		data;
	
	if (argc == 5)
	{
		if(!make_envir_var_array(argv, envp, &data))
			return(-1);
		forking(argv, envp, &data);
		if(!wait_childs(&data))
			return (-1);
	}
	else
		return (-1);
	return (0);	
}