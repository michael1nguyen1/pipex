/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:53:16 by linhnguy          #+#    #+#             */
/*   Updated: 2024/04/04 14:37:05 by linhnguy         ###   ########.fr       */
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

bool execute(t_pipex *data, char** argv, char**envp, int flag)
{
	char *command_path;

	if (flag == 1)
		command_path = data->command_path1;
	else
		command_path = data->command_path2;
	if (!get_new_argv(data, argv, flag))
		exit(EXIT_FAILURE);
	dup2(data->pids[0], STDOUT_FILENO);
	close(data->pipes[0]);
	close(data->pipes[1]);
	execve(*argv, data->new_argv, envp);
	exit(0);
	printf("here");
	return(true);
}
void openfiles(t_pipex *data, char** argv)
{
	 // Open a file for writing. If the file doesn't exist, create it. 
    // The file permissions are set to 0644 (read/write for owner, read-only for group and others).
    int fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
}

int forking(char **argv, char **envp, t_pipex *data)
{
	int i;
	int status;

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
	close(data->pipes[0]);
	close(data->pipes[1]);
	return (0);
}

int wait_childs(t_pipex *data)
{
	int i =0;
	int status[2];

	while (i < 2)
	{
		waitpid(data->pids[i], &status[i], 0 );
		i++;
	}
	if (status[0] != 0 || status[1] != 0)
		return -1;
	return 0;
}

int main (int argc, char **argv, char **envp)
{
	t_pipex		data;
	
	if (argc == 5)
	{
		if(!make_envir_var_array(argv, envp, &data))
			return(-1);
		forking(argv, envp, &data);
		wait_childs(&data);
	}
	else
		return (-1);
	
	return (0);	
}