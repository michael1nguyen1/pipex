/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:15:40 by linhnguy          #+#    #+#             */
/*   Updated: 2024/03/20 16:14:25 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "../libft/libft.h"

typedef struct pipex
{
	char	*command_path1;
	char	*command_path2;
} t_pipex;

int			make_envir_var_array(char **argv, char **envp, t_pipex *data);

int			array_len(char **a);

void		free_array(char **array);
int			free_array_error(char **array);

#endif