/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:53:16 by linhnguy          #+#    #+#             */
/*   Updated: 2024/04/02 22:13:46 by linhnguy         ###   ########.fr       */
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

// bool (dup_files(char **argv))
// {
	
// }

bool execute(t_pipex *data, char** argv, char**envp, int flag)
{
	char *command_path;

	if (flag == 1)
		command_path = data->command_path1;
	else
		command_path = data->command_path2;
	if (!get_new_argv(data, argv, flag))
		exit(EXIT_FAILURE);
	printf("command_path%s\n", command_path);
	for(int i = 0; data->new_argv[i]; i++)
		printf("new argv%d %s\n", i, data->new_argv[i]);
	dup2(pipes[1], STDOUT_FILENO);
	execve(*argv, argv, envp);
	fflush(stdin);
	exit (0);
	return(true);
}

int forking(char **argv, char **envp, t_pipex *data)
{
	int i;
	int pipes[2];
	int status;

	i = 1;
	if (pipe(pipes) < 0)
	{
		perror("creating pipe failed");
		return (-1);
	}
	while (i <= 2)
	{
		printf("this is the %d child\n", i);
		data->pids[i - 1] = fork();
		if (data->pids[i - 1] == 0)
		{
			close(pipes[0]);
			close(pipes[1]);
			execute(data, argv, envp, i);
		}
		dup2(pipes[0], STDIN_FILENO);
		i++;
	}
	close(pipes[0]);
	close(pipes[1]);
	// close_parents_forks();
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