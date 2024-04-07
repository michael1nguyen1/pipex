/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:15:40 by linhnguy          #+#    #+#             */
/*   Updated: 2024/04/07 18:21:04 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/wait.h>
#include "../libft/libft.h"

typedef struct pipex
{
	char	*command_path1;
	char	*command_path2;
	char	**new_argv;
	pid_t 	pids[2];
	int 	pipes[2];
	int		fd[2];
} t_pipex;



bool		make_envir_var_array(char **argv, char **envp, t_pipex *data);

int			array_len(char **a);

void		free_array(char **array);
bool		free_array_error(char **array);
bool		full_clean(char* s, t_pipex *data);

#endif