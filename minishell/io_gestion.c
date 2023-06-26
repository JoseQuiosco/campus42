/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_gestion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atalaver <atalaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:45:38 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/06/26 18:13:55 by atalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

static int	redirect_gestor_entrada(char **cmd, int *i, int *q, t_ficheros *tp)
{
	int	j;

	j = 0;
	if (*(*cmd + (*i + 1)) == '<' && (*(*cmd + (*i + 2)) == '<'
			|| *(*cmd + (*i + 2)) == '>'))
		return (printf("ERROR DE SINTAXIS\n"), free(cmd), free(q), 1);
	if (*(*cmd + (*i + 1)) == '<')
		j = entrada(*cmd + (*i + 2), tp, 1);
	else
		j = entrada(*cmd + (*i + 1), tp, 0);
	if (j > 0)
		*cmd = strdeleted(*cmd, *i, j + *i);
	else
		return (free(*cmd), free(q), 1);
	*i = -1;
	return (0);
}

static int	redirect_gestor_salida(char **cmd, int *i, int *q, t_ficheros *tp)
{
	int	j;

	j = 0;
	if (*(*cmd + (*i + 1)) == '>' && (*(*cmd + (*i + 2)) == '<'
			|| *(*cmd + (*i + 2)) == '>'))
		return (printf("ERROR DE SINTAXIS\n"), free(cmd), free(q), 1);
	if (*(*cmd + (*i + 1)) == '>')
		j = salida(*cmd + (*i + 2), tp, 1);
	else
		j = salida(*cmd + (*i + 1), tp, 0);
	if (j > 0)
		*cmd = strdeleted(*cmd, *i, j + *i);
	else
		return (free(*cmd), free(q), 1);
	*i = -1;
	return (0);
}

char	*open_and_format(char *s, t_ficheros *tp, int i, char *cmd)
{
	int	*q;

	free(s);
	if (!cmd)
		return (NULL);
	q = (int *)ft_calloc(2, sizeof(int));
	if (q == NULL)
		return (free(cmd), NULL);
	while (cmd[++i])
	{
		if (!quotes(cmd[i], q))
		{
			if (cmd[i] == '<' && !q[1])
			{
				if (redirect_gestor_entrada(&cmd, &i, q, tp))
					return (NULL);
			}
			else if (cmd[i] == '>' && (q[0] == 0 && q[1] == 0))
			{
				if (redirect_gestor_salida(&cmd, &i, q, tp))
					return (NULL);
			}
		}
	}
	return (free(q), cmd);
}

int	size_name(char *cmd, char *name, int type, int len)
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
