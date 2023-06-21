/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejecutor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atalaver <atalaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:31:57 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/06/21 16:00:15 by atalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

extern t_varbox	g_varbox;

// static char	*insert_list(char *line, t_list *list, int j, int *i)
// {
// 	char	*res;
// 	int		len;

// 	res = ft_substr(line, 0, j);
// 	if (!res)
// 		return (free(line), NULL);
// 	len = 0;
// 	while (list)
// 	{
// 		res = ft_strjoin(res, (char *)list->content);
// 		if (!res)
// 			return (free(line), NULL);
// 		len += ft_strlen((char *)list->content);
// 		if (list->next)
// 		{
// 			res = ft_strjoin(res, " ");
// 			if (!res)
// 				return (free(line), NULL);
// 			len++;
// 		}
// 		list = list->next;
// 	}
// 	res = ft_strjoin(res, ft_substr(line, *i + 1, ft_strlen(line)));
// 	if (!res)
// 		return (free(line), NULL);
// 	*i += len;
// 	return (free(line), res);
// }

// static char	*expand_wildcard(char *line)
// {
// 	int		i;
// 	int		j;
// 	int		*q;
// 	char	*aux;
// 	t_list	*list;

// 	i = 0;
// 	q = (int *)ft_calloc(2, sizeof(int));
// 	if (q == NULL)
// 		return (NULL);
// 	while (line != NULL && line[i] != '\0')
// 	{
// 		if (!quotes(line[i++], q))
// 		{
// 			if (!q[1] && line[i - 1] == '*')
// 			{
// 				j = i;
// 				while (j >= 0 && !ft_isspace(line[j]))
// 					j--;
// 				while (line[i] && !ft_isspace(line[i]))
// 					i++;
// 				aux = ft_substr(line, j + 1, i);
// 				if (!aux)
// 					return (free(q), NULL);
// 				list = wildcard_gestor(aux, g_varbox.path);
// 				free(aux);
// 				if (list)
// 				{
// 					line = insert_list(line, list, j + 1, &i);
// 					if (!line)
// 						return (free(q), NULL);
// 				}
// 			}
// 		}
// 	}
// 	return (free(q), line);
// }

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
	// *(*inpipes + v->i) = expand_wildcard(*(*inpipes + v->i));
	// if (!(*(*inpipes + v->i)))
	// 	return (1);
	return (0);
}

static char	*define_route(t_ejevars *v, char ***inpipes,
	char ***cmd_opt, int **pipes)
{
	char	*aux;

	if (init_and_clear_spaces(v, inpipes))
		return (NULL);
	printf("LINE:%s~\n", *(*inpipes + v->i));
	*cmd_opt = ft_split_m(*(*inpipes + v->i), ' ');
	int i = 0;
	while (*cmd_opt && (*cmd_opt)[i])
	{
		printf("%d:%s\n", i, (*cmd_opt)[i]);
		i++;
	}
	if (!(*cmd_opt))
		return (NULL);
	if (v->j > 0)
	{
		if (pipe(*pipes + v->i) < 0)
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
	printf("N_pipes:%d\n", v.npipes);
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
