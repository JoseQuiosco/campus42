/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procreacion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atalaver <atalaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:47:46 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/06/19 17:40:23 by atalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

static int	is_builtin(char **cmd_opt)
{
	if (!ft_strcmp(cmd_opt[0], "pwd"))
		return (printf("MIO:"), ft_pwd(cmd_opt), 1);
	else if (!ft_strcmp(cmd_opt[0], "exit"))
		return (printf("SALIENDO...\n"), ft_exit(cmd_opt), 1);
	return (0);
}

static void	hijo2(t_ejevars *v, int **pipes, char *route, char **cmd_opt)
{
	if (v->tp.fs > 0)
	{
		dup2(v->tp.fs, STDOUT_FILENO);
		close(v->tp.fs);
	}
	else if (v->j > 0)
	{
		if (v->i < v->npipes)
		{
			dup2(pipes[v->i][1], STDOUT_FILENO);
			close(pipes[v->i][1]);
		}
	}
	if (is_builtin(cmd_opt))
		exit(0);
	else if (execve(route, cmd_opt, NULL) < 0)
	{
		printf("ERROR CABRON...\n");
		if (errno == ENOENT)
			exit(127);
		else if (errno == EACCES)
			exit(126);
		exit(1);
	}
}

static int	hijo(t_ejevars *v, int **pipes, char *route, char **cmd_opt)
{
	if (v->tp.fi > 0)
	{
		dup2(v->tp.fi, STDIN_FILENO);
		close(v->tp.fi);
	}
	else if (v->tp.ft > 0)
	{
		dup2(v->tp.ft, STDIN_FILENO);
		close(v->tp.ft);
	}
	else if (v->j >= 0)
	{
		if (v->i < v->npipes)
			close(pipes[v->i][0]);
		if (v->i > 0)
		{
			dup2(pipes[v->i - 1][0], STDIN_FILENO);
			close(pipes[v->i - 1][0]);
		}
		if (v->tp.control_i)
			return (v->i++, printf("ERROR DE ENTRADA\n"), 1);
	}
	hijo2(v, pipes, route, cmd_opt);
	return (0);
}

static void	papa(t_ejevars *v, int **pipes, char *route, char **cmd_opt)
{
	if (v->npipes > 0)
	{
		if (v->i < v->npipes)
			close(pipes[v->i][1]);
		if (v->i > 0)
			close(pipes[v->i - 1][0]);
	}
	waitpid(v->pid, &v->status, 0);
	ft_free_params(cmd_opt);
	if (v->control_route)
		free(route);
}

int	procrear(t_ejevars *v, char **inpipes, int **pipes, char **cmd_opt)
{
	v->pid = fork();
	if (v->pid < 0)
		return (ft_freedom(inpipes, cmd_opt, pipes, v->route), 1);
	else if (v->pid == 0)
	{
		if (hijo(v, pipes, v->route, cmd_opt))
		{
			ft_freedom(inpipes, cmd_opt, pipes, v->route);
			return (1);
		}
	}
	else
		papa(v, pipes, v->route, cmd_opt);
	return (0);
}
