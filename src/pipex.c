/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:53:16 by linhnguy          #+#    #+#             */
/*   Updated: 2024/03/16 21:49:23 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int free_array_error(char **array)
{
	int i;
	
	i = 0;
	while(array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (-1);
}

void free_array(char **array)
{
	int i;
	
	i = 0;
	while(array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	array_len(char **a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		i++;
	}
	return (i);
}

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

void initialize_path(char *path, int counter, t_pipex *data)
{
	if (counter == 1)
		data->command_path1 = path;
	else
		data->command_path2 = path;
}

void make_array_full_path(char **v, char**p, t_pipex *data)
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
	printf("command 1 is %s and 2 is %s\n", data->command_path1, data->command_path2);
}

int make_envir_var_array(char **v, char **e, t_pipex *data)
{
	int 	i;
	char 	*path;
	char	**path_array;
	char	*tmp;
	
	i = 0;
	while (e[i])
	{
		if(ft_strncmp("PATH", e[i], 4) == 0)
		{
			path = ft_strdup(e[i]);
			if(!path)
				return (-1);
		}
		i++;
	}
	path_array = ft_split(path, ':');
	if (!path_array)
		return (-1);
	free(path);
	tmp = path_array[0];
	path_array[0] = ft_strdup(&path_array[0][5]);
	if (!path_array[0])
		return (free_array_error(path_array));
	free(tmp);
	make_array_full_path(v, path_array, data);
	free_array(path_array);
	return (0);
}

int main (int c, char** v, char **envp)
{
	t_pipex		data;
	// int fd1;
	// int fd2;
	
	if (c != 5)
		return (-1);
	else 
		make_envir_var_array(v, envp, &data);
	return (0);	
}