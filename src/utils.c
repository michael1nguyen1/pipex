/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:17:45 by linhnguy          #+#    #+#             */
/*   Updated: 2024/04/19 14:47:07 by linhnguy         ###   ########.fr       */
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

bool	wait_childs(t_pipex *data)
{
	int	i;
	int	status[2];

	i = 0;
	while (i < 2)
	{
		waitpid(data->pids[i], &status[i], 0);
		i++;
	}
	if (status[0] != 0 || status[1] != 0)
		return (false);
	return (true);
}

bool	space_checker(char *s)
{
	int	i;

	i = 0;
	if (s[0] == ' ')
		return (true);
	while (s[i])
	{
		if (s[i] == ' ' && s[i + 1] == ' ')
			return (true);
		if (s[i] == ' ' && s[i + 1] == '\0')
			return (true);
		i++;
	}
	return (false);
}
