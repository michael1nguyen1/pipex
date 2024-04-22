/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:17:45 by linhnguy          #+#    #+#             */
/*   Updated: 2024/04/21 20:58:56 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	array_len(char **a)
{
	int	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}

bool	trim_arg(t_pipex *data)
{
	int		i;
	char	*tmp;

	i = 0;
	while (data->new_argv[i])
	{
		if (ft_strchr(data->new_argv[i], 39))
		{
			tmp = data->new_argv[i];
			data->new_argv[i] = ft_strtrim(data->new_argv[i], "'");
			if (!(data->new_argv[i]))
			{
				free(tmp);
				return (false);
			}
		}
		i++;
	}
	return (true);
}

void	prep_split(char *old, char *new)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (old[i])
	{
		if (old[i] == '\'')
			p = (p + 1) % 2;
		else if (old[i] == '{')
			p++;
		else if (old[i] == '}')
			p--;
		if (old[i] == ' ' && p == 0)
			new[i] = '\a';
		else
			new[i] = old[i];
		i++;
	}
	new[i] = '\0';
}

void	wait_childs(t_pipex *data)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		waitpid(data->pids[i], &data->status[i], 0);
		i++;
	}
}
