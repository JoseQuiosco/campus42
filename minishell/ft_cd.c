/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atalaver <atalaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:46:40 by atalaver          #+#    #+#             */
/*   Updated: 2023/06/26 20:55:10 by atalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

extern t_varbox	*g_varbox;

static int	ft_set_path(char *path)
{
	if (chdir(path) < 0)
		return (1);
	return (0);
}

static int	ft_old_pwd(char *path)
{
	t_list	*list;
	char	*aux;

	list = find_node_enviro_with_key("OLDPWD", g_varbox->enviroment);
	free(list->content);
	aux = ft_strjoin("OLDPWD=", path);
	if (!aux)
		return (1);
	list->content = aux;
	return (0);
}

static int	ft_new_pwd(char *path)
{
	t_list	*list;
	char	*aux;

	list = find_node_enviro_with_key("PWD", g_varbox->enviroment);
	free(list->content);
	aux = ft_strjoin("PWD=", path);
	if (!aux)
		return (1);
	list->content = aux;
	return (0);
}

static int	ft_get_path(char *path, char **split, char **cmd_opt, int i)
{
	path = ft_clean_bars(cmd_opt[1], 0, 0, 0);
	if (!path)
		return (1);
	if (path[0] != '/')
	{
		split = ft_split(path, '/');
		if (!split)
			return (free(path), 1);
		while (split[++i])
		{
			if (ft_set_path(split[i]))
				return (ft_free_params(split), free(path),
					printf("File or directory doesn't exist\n"), 1);
		}
		ft_free_params(split);
	}
	else
	{
		if (ft_set_path(path))
			return (printf("File or directory doesn't exist\n"),
				free(path), 1);
	}
	return (0);
}

int	ft_cd(char **cmd_opt)
{
	if (ft_len_matrix2(cmd_opt) > 2 || ft_len_matrix2(cmd_opt) < 2)
		return (printf("Should be 1 argument!\n"), 1);
	if (ft_len_matrix2(cmd_opt) == 2)
	{
		if (ft_get_path(0, 0, cmd_opt, -1))
			return (1);
	}
	if (ft_old_pwd(g_varbox->path))
		return (1);
	getcwd(g_varbox->path, 1024);
	if (ft_new_pwd(g_varbox->path))
		return (1);
	return (0);
}
