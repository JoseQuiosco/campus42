/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejecutor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:31:57 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/06/22 14:41:44 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

extern t_varbox	*g_varbox;

char	*insert_list(char *line, t_list *list, int j, int *i)
{
	char	*res;
	char	*aux;
	char	*aux2;
	int		len;

	res = ft_substr(line, 0, j);
	if (!res)
		return (free(line), NULL);
	len = 0;
	while (list)
	{
		res = insert_content(res, list, &len);
		if (!res)
			return (free(line), NULL);
		list = list->next;
	}
	aux = res;
	aux2 = ft_substr(line, *i + 1, ft_strlen(line));
	res = ft_strjoin(res, aux2);
	free(aux);
	free(aux2);
	if (!res)
		return (free(line), NULL);
	*i += len;
	return (free(line), res);
}

static char	*expand_wildcard(char *line)
{
	int		i;
	int		*q;

	i = 0;
	q = (int *)ft_calloc(2, sizeof(int));
	if (q == NULL)
		return (NULL);
	while (line != NULL && line[i] != '\0')
	{
		if (!quotes(line[i++], q))
		{
			line = search_wc(i, i, line, q);
			if (!line)
				return (free(q), NULL);
		}
	}
	return (free(q), line);
}

static int	init_and_clear_spaces(t_ejevars *v, char ***inpipes)
{
	char	*aux;

	v->tp.fi = 0;
	v->tp.ft = 0;
	v->tp.fs = 0;
	v->tp.control_i = 0;
	v->control_route = 0;
	aux = clean_spaces(*(*inpipes + v->i));
	if (!aux)
		return (1);
	*(*inpipes + v->i) = open_and_format(*(*inpipes + v->i), &v->tp, -1, aux);
	if (!(*(*inpipes + v->i)))
		return (1);
	*(*inpipes + v->i) = expand_envar(*(*inpipes + v->i), g_varbox->enviroment);
	if (!(*(*inpipes + v->i)))
		return (1);
	*(*inpipes + v->i) = expand_wildcard(*(*inpipes + v->i));
	if (!(*(*inpipes + v->i)))
		return (1);
	return (0);
}

static char	*define_route(t_ejevars *v, char ***inpipes,
	char ***cmd_opt, int **pipes)
{
	char	*aux;

	if (init_and_clear_spaces(v, inpipes))
		return (NULL);
	*cmd_opt = ft_split_m(*(*inpipes + v->i), ' ');
	if (!(*cmd_opt))
		return (NULL);
	if (v->j > 0)
	{
		if (pipe(*(pipes + v->i)) < 0)
			return (printf("ERROR CREATE PIPE\n"), NULL);
	}
	if (access(*(*inpipes + v->i), F_OK | X_OK) != 0)
	{
		aux = find_path(**cmd_opt, &v->control_route, -1);
		if (!aux)
			return (NULL);
		return (aux);
	}
	else
		return (*(*inpipes + v->i));
}

int	ejecutor_i(char *ins)
{
	t_ejevars	v;
	char		**cmd_opt;
	char		**inpipes;
	int			**pipes;

	inpipes = ft_split_m2(ins, '|');
	v.npipes = count_pipes(inpipes);
	pipes = creat_pipes(v.npipes);
	v.status = 0;
	v.i = -1;
	v.j = v.npipes;
	while (inpipes[++v.i])
	{
		v.route = define_route(&v, &inpipes, &cmd_opt, pipes);
		if (!v.route)
			return (ft_freedom(inpipes, cmd_opt, pipes, v.route), 1);
		if (procrear(&v, inpipes, pipes, cmd_opt))
			continue ;
		if (v.j > 0)
			v.j--;
	}
	actualizar_exit_code(WEXITSTATUS(v.status));
	return (ft_freedom(inpipes, NULL, pipes, NULL), g_varbox->exit_code);
}
