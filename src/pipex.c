/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:53:16 by linhnguy          #+#    #+#             */
/*   Updated: 2024/04/15 20:30:17 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

bool	trim_arg(t_pipex *data)
{
	int i;
	char *tmp;

	i = 0;
	while (data->new_argv[i])
	{
		if(ft_strchr(data->new_argv[i], 39))
		{
			tmp = data->new_argv[i];
			if (!(data->new_argv[i] = ft_strtrim(data->new_argv[i], "'")))
			{	
				free(tmp);
				return (false);
			}
		}
		i++;
	}
	return (true);
}

void prep_split(char *old, char *new)
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


bool	get_new_argv(t_pipex *data, char **argv, int flag)
{	
	char newstr[300];
	
	if (flag == 1)
	{
		prep_split(argv[2], newstr);
		ft_printf(2, "newstr is %s\n", newstr);
		data->new_argv = ft_split(newstr, '\a');
		if (!data->new_argv)
			return (full_clean("split failed for first argv\n", data));
	}
	else
	{
		prep_split(argv[3], newstr);
		data->new_argv = ft_split(newstr, '\a');
		if (!data->new_argv)
			return (full_clean("split failed for second argv\n", data));
	}
	if (!(trim_arg(data)))
		return (full_clean("trim arg failed\n", data));
	for(int i = 0; data->new_argv[i]; i++)
		ft_printf(2, "string is %s\n", data->new_argv[i]);
	return (true);
}

void	execute(t_pipex *data, char **argv, char**envp, int flag)
{
	char	*command_path;

	if (flag == 1)
	{
		command_path = data->command_path1;
		dup2(data->fd[0], STDIN_FILENO);
		dup2(data->pipes[1], STDOUT_FILENO);
	}
	else
	{
		command_path = data->command_path2;
		dup2(data->pipes[0], STDIN_FILENO);
		dup2(data->fd[1], STDOUT_FILENO);
	}
	// dprintf(2, "command-path is : %s \n", command_path);
	if (!get_new_argv(data, argv, flag))
		exit(EXIT_FAILURE);
	close(data->pipes[0]);
	close(data->pipes[1]);
	// for (int i = 0; data->new_argv[i]; i++)
	// 	ft_printf(2, "%s\n", data->new_argv[i]);
	if (execve(command_path, data->new_argv, envp) == -1)
		perror ("execve");
	exit(EXIT_FAILURE);
}

void	openfiles(t_pipex *data, char **argv)
{
	data->fd[0] = open(argv[1], O_RDONLY);
	data->fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// data->fd[0] = -1;
	if (data->fd[0] == -1)
	{
		full_clean(NULL, data);
		ft_printf(2, "permission denied: %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (data->fd[1] == -1)
	{
		full_clean(NULL, data);
		ft_printf(2, "permission denied: %s\n", argv[4]);
		exit(EXIT_FAILURE);
	}
}

int	forking(char **argv, char **envp, t_pipex *data)
{
	int	i;

	i = 1;
	if (pipe(data->pipes) < 0)
	{
		perror("creating pipe failed");
		return (-1);
	}
	openfiles(data, argv);
	while (i <= 2)
	{
		data->pids[i - 1] = fork();
		if (data->pids[i - 1] == 0)
			execute(data, argv, envp, i);
		i++;
	}
	close(data->fd[0]);
	close(data->fd[1]);
	close(data->pipes[0]);
	close(data->pipes[1]);
	return (0);
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

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	data = (t_pipex){0};
	if (argc == 5)
	{
		if (!make_envir_var_array(argv, envp, &data))
			return (EXIT_FAILURE);
		forking(argv, envp, &data);
		if (!wait_childs(&data))
			return (EXIT_FAILURE);
	}
	else
	{
		ft_printf(2, "Error!! Usage: ./pipex file1 cmd1 cmd2 file2\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
