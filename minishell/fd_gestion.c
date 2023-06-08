/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_gestion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:09:57 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/06/07 17:00:36 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

static void	read_buffer(t_ficheros *tp, char *end)
{
	char	*new_line;
	char	*aux;

	new_line = readline("> ");
	while (new_line && ft_strcmp(new_line, end))
	{
		aux = ft_strjoin(new_line, "\n");
		write(tp->ft, aux, ft_strlen(aux));
		free(new_line);
		free(aux);
		new_line = readline("> ");
	}
	free(new_line);
}

static int	size_name(char *cmd, char *name, int type, int len)
{
	if (cmd[0] == ' ')
	{
		if (cmd[1] == '\'' || cmd[1] == '"')
			return (free(name), len + 1 + 2 + type);
		return (free(name), len + 1 + type);
	}
	else
	{
		if (cmd[0] == '\'' || cmd[0] == '"')
			return (free(name), len + 2 + type);
		return (free(name), len + type);
	}
	if (name)
		free(name);
	return (0);
}

static void	close_fin(t_ficheros *tp)
{
	if (tp->fi > 0)
	{
		close(tp->fi);
		tp->fi = 0;
	}
	if (tp->ft > 0)
	{
		close(tp->ft);
		tp->ft = 0;
	}
}

int	entrada(char *cmd, t_ficheros *tp, int type)
{
	char	*name;
	int		len;

	name = search_name(cmd, 0);
	if (!name)
		return (0);
	len = ft_strlen(name);
	if (!len)
		return (free(name), 0);
	close_fin(tp);
	if (type == 0)
	{
		tp->control_i = 1;
		tp->fi = open(name, O_RDONLY);
	}
	if (type == 1)
	{
		tp->ft = open(".antiJose", O_WRONLY | O_TRUNC | O_CREAT, 0000777);
		read_buffer(tp, name);
		close(tp->ft);
		tp->ft = open(".antiJose", O_RDONLY);
	}
	return (size_name(cmd, name, type, len));
}

int	salida(char *cmd, t_ficheros *tp, int type)
{
	char	*name;
	char	*new_line;
	char	*aux;
	int		len;

	name = search_name(cmd, 0);
	if (!name)
		return (0);
	len = ft_strlen(name);
	if (!len)
		return (free(name), 0);
	if (tp->fs > 0)
	{
		close(tp->fs);
		tp->fs = 0;
	}
	if (type == 0)
		tp->fs = open(name, O_WRONLY | O_TRUNC | O_CREAT, 0000777);
	else
		tp->fs = open(name, O_WRONLY | O_APPEND | O_CREAT, 0000777);
	return (size_name(cmd, name, type, len));
}
