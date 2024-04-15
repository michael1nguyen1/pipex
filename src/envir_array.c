/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envir_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:48:32 by linhnguy          #+#    #+#             */
/*   Updated: 2024/04/15 22:44:01 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*make_whole_path(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		k;

	k = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!s3)
		return (NULL);
	while (s1[i])
		s3[k++] = s1[i++];
	i = 0;
	s3[k++] = '/';
	while (s2[i] && s2[i] != ' ')
		s3[k++] = s2[i++];
	s3[k] = '\0';
	return (s3);
}

void	initialize_path(char *path, int counter, t_pipex *data)
{
	if (counter == 1)
		data->command_path1 = ft_strdup(path);
	else
		data->command_path2 = ft_strdup(path);
}

static bool	make_array_full_path(char **argv, char**path_array, t_pipex *data)
{
	int		i;
	int		path_counter;

	path_counter = 1;
	i = 2;
	while (i <= 3)
	{
		if (ft_strchr(argv[i], '/'))
		{
			if (access(argv[i], F_OK) == 0)
			{
				initialize_path(argv[i++], path_counter, data);
				path_counter++;
				continue ;
			}
		}
		if (ft_strchr(argv[i], ' '))
		{
			arg_has_space(argv[i++], path_array, data, &path_counter);
			continue ;
		}
		check_access(argv[i++], path_array, data, &path_counter);
	}
	check_path(data, argv);
	return (true);
}

static char	*find_path(char **envp)
{
	int		i;
	char	*path;

	path = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
		{
			path = ft_strdup(envp[i]);
			if (!path)
				return (NULL);
		}
		i++;
	}
	return (path);
}

bool	make_envir_var_array(char **argv, char **envp, t_pipex *data)
{
	char	*path;
	char	**path_array;
	char	*tmp;

	path = find_path(envp);
	if (!path)
		return (full_clean("Path not found\n", data));
	path_array = ft_split(path, ':');
	if (!path_array)
		return (full_clean("Split failed \n", data));
	free(path);
	tmp = path_array[0];
	path_array[0] = ft_strdup(&path_array[0][5]);
	if (!path_array[0])
		return (free_array_error(path_array));
	free(tmp);
	if (!make_array_full_path(argv, path_array, data))
		return (full_clean("Making full path failed\n", data));
	free_array(path_array);
	return (true);
}
