/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejecutor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:31:57 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/06/07 20:46:50 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

extern t_varbox	g_varbox;

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
	*(*inpipes + v->i) = expand_envar(*(*inpipes + v->i), g_varbox.enviroment);
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
		if (pipe(*pipes + v->i) < 0)
			return (NULL);
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
	return (ft_freedom(inpipes, NULL, pipes, NULL), g_varbox.exit_code);
}
