/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:53:16 by linhnguy          #+#    #+#             */
/*   Updated: 2024/03/27 17:25:52 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

bool execute()
{
	
}

int forking(char **argv, char **envp, t_pipex *data)
{
	int i;
	int pid;
	int pipes[2]; 

	i = 0;
	if (pipe(pipes) < 0)
	{
		perror("creating pipe failed");
		return (-1);
	}
	while (i < 2)
	{
		fork();
		if (pid == 0)
			execute(data, argv, envp);
		else
			wait(NULL);
		i++;
	}
	close_parents_forks();
	return (0);
}

int main (int argc, char **argv, char **envp)
{
	t_pipex		data;
	
	if (argc == 5)
	{
		if(!make_envir_var_array(argv, envp, &data))
			return(-1);
		forking(argv, envp, &data);
	}
	else
		return (-1);
	return (0);	
}