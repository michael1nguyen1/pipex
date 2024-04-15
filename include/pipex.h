/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:15:40 by linhnguy          #+#    #+#             */
/*   Updated: 2024/04/15 22:43:04 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include "../libft/libft.h"

typedef struct pipex
{
	char	*command_path1;
	char	*command_path2;
	char	**new_argv;
	pid_t	pids[2];
	int		pipes[2];
	int		fd[2];
}	t_pipex;

bool	make_envir_var_array(char **argv, char **envp, t_pipex *data);
int		array_len(char **a);
bool	trim_arg(t_pipex *data);
void	prep_split(char *old, char *new);
bool	wait_childs(t_pipex *data);
void	free_array(char **array);
bool	free_array_error(char **array);
bool	full_clean(char *s, t_pipex *data);
void	check_path(t_pipex *data, char **argv);
void	check_access(char *path, char **path_array, t_pipex *data, int *count);
void	arg_has_space(char *argv, char **path_array, t_pipex *data, int *count);
char	*make_whole_path(char const *s1, char const *s2);
void	initialize_path(char *path, int counter, t_pipex *data);

#endif