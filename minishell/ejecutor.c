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


// int	ejecutor_i(char *ins)
// {
// 	t_ficheros	tp;
// 	pid_t		pid; //necesidad
// 	char		*route;
// 	char		**cmd_opt;
// 	int			status;
// 	char		**inpipes;
// 	int			i;
// 	int			j;
// 	int			npipes;
// 	int			**pipes;
// 	int			v.control_route;

// 	inpipes = ft_split_m2(ins, '|');
// 	npipes = count_pipes(inpipes);
// 	pipes = creat_pipes(npipes);
// 	i = 0;
// 	j = npipes;
// 	while (inpipes[i])
// 	{
// 		tp.fi = 0;
// 		tp.ft = 0;
// 		tp.fs = 0;
// 		tp.control_i = 0;
// 		inpipes[i] = open_and_format(inpipes[i], &tp, -1, clean_spaces(inpipes[i]));
// 		inpipes[i] = expand_envar(inpipes[i], g_varbox.enviroment);
// 		cmd_opt = ft_split_m(inpipes[i], ' ');
// 		control_route = 0;
// 		if (access(inpipes[i], F_OK | X_OK) != 0)
// 			route = find_path(cmd_opt[0], &control_route, -1);
// 		else
// 			route = inpipes[i];
// 		if (j > 0)
// 			pipe(pipes[i]);
// 		pid = fork();
// 		if (pid < 0)
// 			return (ft_freedom(inpipes, cmd_opt, pipes, route), 0);
// 		else if (pid == 0)
// 		{
// 			if (tp.fi > 0)
// 			{
// 				dup2(tp.fi, STDIN_FILENO);
// 				close(tp.fi);
// 			}
// 			else if (tp.ft > 0)
// 			{
// 				dup2(tp.ft, STDIN_FILENO);
// 				close(tp.ft);
// 			}
// 			else if (j >= 0)
// 			{
// 				if (i < npipes)
// 					close(pipes[i][0]);
// 				if (i > 0)
// 				{
// 					dup2(pipes[i - 1][0], STDIN_FILENO);
// 					close(pipes[i - 1][0]);
// 				}
// 				if (tp.control_i)
// 				{
// 					printf("ERROR DE ENTRADA\n");
// 					i++;
// 					continue ;
// 				}
// 			}
// 			if (tp.fs > 0)
// 			{
// 				dup2(tp.fs, STDOUT_FILENO);
// 				close(tp.fs);
// 			}
// 			else if (j > 0)
// 			{
// 				if (i < npipes)
// 				{
// 					dup2(pipes[i][1], STDOUT_FILENO);
// 					close(pipes[i][1]);
// 				}
// 			}
// 			if (execve(route, cmd_opt, NULL) < 0)
// 			{
// 				printf("ERROR CABRON...\n");
// 				if (errno == ENOENT)
// 					exit(127);
// 				else if (errno == EACCES)
// 					exit(126);
// 				exit(1);
// 			}
// 		}
// 		else
// 		{
// 			if (npipes > 0)
// 			{
// 				if (i < npipes)
// 					close(pipes[i][1]);
// 				if (i > 0)
// 					close(pipes[i - 1][0]);
// 			}
// 			waitpid(pid, &status, 0);
// 			ft_free_params(cmd_opt);
// 			if (control_route)
// 				free(route);
// 		}
// 		if (j > 0)
// 			j--;
// 		i++;
// 	}
// 	actualizar_exit_code(WEXITSTATUS(status));
// 	return (ft_freedom(inpipes, NULL, pipes, NULL), g_varbox.exit_code);
// }
