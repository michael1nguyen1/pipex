/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:53:16 by linhnguy          #+#    #+#             */
/*   Updated: 2024/03/20 16:32:33 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void forking(char **v, t_pipex *data)
{
	int fd1 = open
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