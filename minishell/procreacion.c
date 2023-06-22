/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procreacion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atalaver <atalaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:47:46 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/06/22 13:14:48 by atalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

extern t_varbox	*g_varbox;

static int	is_builtin(char **cmd_opt)
{
	if (!ft_strcmp(cmd_opt[0], "pwd"))
		return (1);
	else if (!ft_strcmp(cmd_opt[0], "exit"))
		return (2);
	return (0);
}

static void	builtin2(t_ejevars *v, int **pipes, char **cmd_opt)
{
	int saved;

	if (v->tp.fs > 0)
	{
		dup2(v->tp.fs, STDOUT_FILENO);
		//close(v->tp.fs);
	}
	else if (v->j > 0)
	{
		if (v->i < v->npipes)
		{
			printf("a\n");
			saved = dup(STDOUT_FILENO);
			dup2(pipes[v->i][1], STDOUT_FILENO);
			close(pipes[v->i][1]);
		}
	}
	if (v->builtin == 1)
		ft_pwd(cmd_opt);
	else if (v->builtin == 2)
		ft_exit(cmd_opt);
	dup2(saved, STDOUT_FILENO);
}

static int	builtin1(t_ejevars *v, int **pipes, char **cmd_opt)
{
	if (v->tp.fi > 0)
	{
		dup2(v->tp.fi, STDIN_FILENO);
		//close(v->tp.fi);
	}
	else if (v->tp.ft > 0)
	{
		dup2(v->tp.ft, STDIN_FILENO);
		//close(v->tp.ft);
	}
	else if (v->j >= 0)
	{
		printf("I:%d\n", v->i);
		// if (v->i < v->npipes)
		// 	close(pipes[v->i][0]);
		if (v->i > 0)
		{
			dup2(pipes[v->i - 1][0], STDIN_FILENO);
			//close(pipes[v->i - 1][0]);
		}
		if (v->tp.control_i)
			return (v->i++, printf("ERROR DE ENTRADA\n"), 1);
	}
	builtin2(v, pipes, cmd_opt);
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
	if (execve(route, cmd_opt, NULL) < 0)
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
			printf("salida\n");
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
	v->builtin = is_builtin(cmd_opt);
	if (v->builtin)
	{
		// if (v->npipes > 0)
		// {
		// 	if (v->i < v->npipes)
		// 		close(pipes[v->i][1]);
		// 	if (v->i > 0)
		// 		close(pipes[v->i - 1][0]);
		// }
		builtin1(v, pipes, cmd_opt);
		//dup2(0, STDIN_FILENO);
		//dup2(1, STDOUT_FILENO);
		ft_free_params(cmd_opt);
		if (v->control_route)
			free(v->route);
	}
	else
	{
		v->pid = fork();
		if (v->pid < 0)
			return (ft_freedom(inpipes, cmd_opt, pipes, v->route), 1);
		else if (v->pid == 0)
		{
			signal(SIGINT, SIG_DFL);
			if (hijo(v, pipes, v->route, cmd_opt))
			{
				ft_freedom(inpipes, cmd_opt, pipes, v->route);
				return (1);
			}
		}
		else
			papa(v, pipes, v->route, cmd_opt);
	}
	return (0);
}
