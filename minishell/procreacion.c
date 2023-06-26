/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procreacion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:47:46 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/06/26 13:14:12 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

extern t_varbox	*g_varbox;

void	aumentar_profundidad(t_list *list, int shlvl, char *aux2,
	char *aux3)
{
	t_list	*aux;

	if (aux2)
	{
		shlvl = ft_atoi(aux2) + 1;
		free(aux2);
	}
	aux2 = ft_itoa(shlvl);
	if (!aux2)
		return ;
	aux3 = ft_strjoin("SHLVL=", aux2);
	free(aux2);
	if (!aux3)
		return ;
	list = find_node_enviro_with_key("SHLVL", g_varbox->enviroment);
	if (!list)
	{
		aux = ft_lstnew(aux3);
		if (!aux)
			return ;
		ft_lstadd_back(&g_varbox->enviroment, aux);
		return ;
	}
	free(list->content);
	list->content = aux3;
}

static int	is_builtin(char **cmd_opt)
{
	if (ft_len_matrix2(cmd_opt) > 0)
	{
		if (!ft_strcmp(cmd_opt[0], "pwd"))
			return (1);
		else if (!ft_strcmp(cmd_opt[0], "exit"))
			return (2);
		else if (!ft_strcmp(cmd_opt[0], "env"))
			return (3);
		else if (!ft_strcmp(cmd_opt[0], "export"))
			return (4);
		else if (!ft_strcmp(cmd_opt[0], "echo"))
			return (5);
		else if (!ft_strcmp(cmd_opt[0], "unset"))
			return (6);
		else if (!ft_strcmp(cmd_opt[0], "cd"))
			return (7);
	}
	return (0);
}

// la salida de builtin no se está usando
static int	builtin(t_ejevars *v, int **pipes, char **cmd_opt)
{
	int	saved;

	saved = dup(STDOUT_FILENO);
	if (v->tp.control_i)
	{
		actualizar_exit_code(1);
		return (v->i++, printf("ERROR DE ENTRADA\n"), 1);
	}
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
	if (v->builtin == 1)
		v->status = ft_pwd(cmd_opt);
	else if (v->builtin == 2)
		v->status = ft_exit(cmd_opt);
	else if (v->builtin == 3)
		v->status = ft_env(cmd_opt);
	else if (v->builtin == 4)
		v->status = ft_export(cmd_opt);
	else if (v->builtin == 5)
		v->status = ft_echo(cmd_opt);
	else if (v->builtin == 6)
		v->status = ft_unset(cmd_opt);
	else if (v->builtin == 7)
		v->status = ft_cd(cmd_opt);
	dup2(saved, STDOUT_FILENO);
	return (actualizar_exit_code(v->status), 0);
}

static char	**env_to_matrix(t_list *list)
{
	char	**res;
	int		i;
	t_list	*code;
	t_list	*name;

	list = g_varbox->enviroment;
	code = find_node_enviro_with_key("?", g_varbox->enviroment);
	name = find_node_enviro_with_key("0", g_varbox->enviroment);
	res = ft_calloc(ft_len_list(list) - 1, sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (list)
	{
		if (list == name || list == code)
		{
			list = list->next;
			continue ;
		}
		res[i] = ft_strdup(list->content);
		if (!res[i])
			return (ft_free_params(res), NULL);
		list = list->next;
		i++;
	}
	return (res);
}

static void	hijo2(t_ejevars *v, int **pipes, char *route, char **cmd_opt)
{
	char	**env;

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
	if (!ft_len_matrix2(cmd_opt))
		exit(0);
	env = env_to_matrix(NULL);
	if (!env)
		exit(1);
	if (execve(route, cmd_opt, env) < 0)
	{
		ft_free_params(env);
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
	g_varbox->flag_c = 1;
	waitpid(v->pid, &v->status, 0);
	actualizar_exit_code(WEXITSTATUS(v->status));
	if (g_varbox->flag_c == 2)
		actualizar_exit_code(CODE_ERROR);
	g_varbox->flag_c = 0;
	ft_free_params(cmd_opt);
	if (v->control_route)
		free(route);
}

int	procrear(t_ejevars *v, char **inpipes, int **pipes, char **cmd_opt)
{
	v->builtin = is_builtin(cmd_opt);
	if (v->builtin)
	{
		builtin(v, pipes, cmd_opt);
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
			if (hijo(v, pipes, v->route, cmd_opt))
				exit(1);
		}
		else
			papa(v, pipes, v->route, cmd_opt);
	}
	return (0);
}
