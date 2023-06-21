/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ejecutor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:55:13 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/06/21 16:06:54 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

extern t_varbox	g_varbox;

static int	get_paths(char ***paths)
{
	char	*aux;

	aux = export_value("PATH", g_varbox.enviroment);
	if (!aux)
		return (1);
	*paths = ft_split(aux, ':');
	free(aux);
	if (!(*paths))
		return (1);
	return (0);
}

char	*find_path(char *cmd, int *control, int i)
{
	char	*fullpath;
	char	*aux;
	char	**paths;

	if (get_paths(&paths))
		return (cmd);
	while (paths[++i])
	{
		fullpath = ft_strjoin(paths[i], "/");
		if (!fullpath)
			return (ft_free_params(paths), cmd);
		aux = fullpath;
		fullpath = ft_strjoin(fullpath, cmd);
		free(aux);
		if (!fullpath)
			return (ft_free_params(paths), cmd);
		if (access(fullpath, F_OK | X_OK) == 0)
		{
			*control = 1;
			return (ft_free_params(paths), fullpath);
		}
		free(fullpath);
	}
	return (ft_free_params(paths), cmd);
}

int	count_pipes(char **inpipes)
{
	int	i;

	i = 0;
	while (inpipes[i])
		i++;
	return (i - 1);
}

int	**creat_pipes(int npipes)
{
	int	**pipes;
	int	i;

	pipes = (int **)calloc((npipes + 1), sizeof(int *));
	if (pipes == NULL)
		return (NULL);
	i = 0;
	while (i < npipes)
	{
		pipes[i] = (int *)malloc(2 * sizeof(int));
		if (pipes[i] == NULL)
		{
			ft_free_params((char **)pipes);
			return (NULL);
		}
		i++;
	}
	pipes[i] = NULL;
	return (pipes);
}

void	ft_freedom(char **inpipes, char **cmd_opt, int **pipes, char *route)
{
	if (pipes != NULL)
		ft_free_params((char **)pipes);
	if (inpipes != NULL)
		ft_free_params(inpipes);
	if (cmd_opt != NULL)
		ft_free_params(cmd_opt);
	if (route != NULL)
		free(route);
}
