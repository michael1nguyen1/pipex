/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envir_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:48:32 by linhnguy          #+#    #+#             */
/*   Updated: 2024/03/27 17:20:22 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*make_whole_path(char const *s1, char const *s2)
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
	{
		s3[k++] = s1[i++];
	}
	i = 0;
	s3[k++] = '/';
	while (s2[i])
	{
		s3[k++] = s2[i++];
	}
	s3[k] = '\0';
	return (s3);
}

static void initialize_path(char *path, int counter, t_pipex *data)
{
	if (counter == 1)
		data->command_path1 = path;
	else
		data->command_path2 = path;
}

static bool make_array_full_path(char **v, char**p, t_pipex *data)
{
	int		i;
	int		j;
	int		counter;
	char	*tmp;
	
	counter = 1;
	i = 2;
	while (i <= 3)
	{
		j = 0;
		while (p[j] != NULL)
		{
			tmp = make_whole_path(p[j], v[i]);
			if (!tmp)
			{
				perror("make_whole_path failed");
				return (false);
			}
			if (access(tmp, F_OK) == 0)
			{	
				initialize_path(tmp, counter, data);
				counter++;
			}
			else
				free(tmp);
			j++;
		}
		i++;
	}
	return (true);
}

static char *find_path(char **envp)
{
	int 	i;
	char 	*path;
	
	i = 0;
	while (envp[i])
	{
		if(ft_strncmp("PATH", envp[i], 4) == 0)
		{
			path = ft_strdup(envp[i]);
			if(!path)
			{
				perror("strdup failed");
				return (NULL);
			}
		}
		i++;
	}
	return(path);
}

bool make_envir_var_array(char **argv, char **envp, t_pipex *data)
{
	char 	*path;
	char	**path_array;
	char	*tmp;
	
	data->new_argv[0] = argv[2];
	data->new_argv[1] = argv[3];
	path = find_path(envp);
	if (!path)
		return (false);
	path_array = ft_split(path, ':');
	if (!path_array)
		free_bool(path, "Split failed \n");
	free(path);
	tmp = path_array[0];
	path_array[0] = ft_strdup(&path_array[0][5]);
	if (!path_array[0])
		return (free_array_error(path_array));
	free(tmp);
	if (!make_array_full_path(argv, path_array, data))
		free_bool(NULL, "Making full path failed\n");
	free_array(path_array);
	return (true);
}
