/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:53:16 by linhnguy          #+#    #+#             */
/*   Updated: 2024/03/20 17:16:53 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int forking(char **v, t_pipex *data)
{
	int fd1 = open(v[1], O_RDWR);
	int fd2 = open(v[4], O_RDWR);
	if (fd1 == -1 | fd2 == -1)
		{
			perror("open failed");
			return (-1);
		}
	return (0);
}

int main (int c, char **v, char **envp)
{
	t_pipex		data;
	
	if (c == 5)
	{
		make_envir_var_array(v, envp, &data);
		forking(v, &data);
	}
	else
		return (-1);
	printf("command 1 is %s and 2 is %s\n", data.command_path1, data.command_path2);
	return (0);	
}