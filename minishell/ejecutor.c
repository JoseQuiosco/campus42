/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejecutor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:31:57 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/06/26 22:24:16 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

extern t_varbox	*g_varbox;

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
	*(*inpipes + v->i) = expand_envar(*(*inpipes + v->i));
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

static int	ft_init_ejecutor(t_ejevars *v, char *ins)
{
	v->inpipes = ft_split_m2(ins, '|');
	if (!v->inpipes)
		return (-1);
	if (!v->inpipes[0])
		return (ft_free_params(v->inpipes), 0);
	v->npipes = count_pipes(v->inpipes);
	v->pipes = creat_pipes(v->npipes);
	v->status = 0;
	v->i = -1;
	v->j = v->npipes;
	return (1);
}

int	ejecutor_i(char *ins)
{
	t_ejevars	v;
	int			code;

	code = ft_init_ejecutor(&v, ins);
	if (code <= 0)
		return (-code);
	g_varbox->flag_c = 0;
	while (v.inpipes[++v.i])
	{
		v.route = define_route(&v, &v.inpipes, &v.cmd_opt, v.pipes);
		if (!v.route)
			return (ft_freedom(v.inpipes, v.cmd_opt, v.pipes, v.route), 1);
		if (g_varbox->flag_c)
		{
			ft_free_params(v.cmd_opt);
			if (v.route)
				free(v.route);
			break ;
		}
		if (procrear(&v, v.inpipes, v.pipes, v.cmd_opt))
			continue ;
		if (v.j > 0)
			v.j--;
	}
	return (ft_freedom(v.inpipes, NULL, v.pipes, NULL), g_varbox->exit_code);
}
