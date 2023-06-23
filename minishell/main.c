/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atalaver <atalaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:11:19 by atalaver          #+#    #+#             */
/*   Updated: 2023/06/24 01:20:34 by atalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

t_varbox	*g_varbox;

void	control_c(int n)
{
	if (!g_varbox->flag_c)
	{
		printf("\n");
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
		actualizar_exit_code(1);
	}
	else if (g_varbox->flag_c == 1)
	{
		printf("\n");
		g_varbox->flag_c = 2;
	}
	else if (g_varbox->flag_c == 2)
		exit(1);
	signal(n, control_c);
}

int	init_varbox(char **env)
{
	char	*aux_str;
	t_list	*aux;

	g_varbox = (t_varbox *)malloc(sizeof(t_varbox));
	if (!g_varbox)
		return (1);
	g_varbox->exit = 0;
	g_varbox->flag_c = 0;
	getcwd(g_varbox->path, 1024);
	g_varbox->enviroment = matrix_to_list((void **)env);
	if (!g_varbox->enviroment)
		return (1);
	aux_str = ft_strdup("0=minishell");
	if (!aux_str)
		return (1);
	aux = ft_lstnew(aux_str);
	if (!aux)
		return (free(aux_str), 1);
	ft_lstadd_back(&g_varbox->enviroment, aux);
	actualizar_exit_code(0);
	return (0);
}

int	actualizar_exit_code(int code)
{
	char	*aux;
	char	*aux2;
	t_list	*aux3;

	g_varbox->exit_code = code;
	aux = ft_itoa(code);
	if (!aux)
		return (1);
	aux2 = ft_strjoin("?=", aux);
	free(aux);
	if (!aux2)
		return (1);
	aux3 = find_node_enviro_with_key("?", g_varbox->enviroment);
	if (!aux3)
	{
		aux3 = ft_lstnew(aux2);
		if (!aux3)
			return (free(aux2), 1);
		ft_lstadd_back(&g_varbox->enviroment, aux3);
		return (0);
	}
	free(aux3->content);
	aux3->content = aux2;
	return (0);
}

int	main(int argc, char *argv[], char **env)
{
	char		*command_ln;
	t_cmdtree	*tree;
	int			exit_code;

	(void)argc;
	(void)argv;
	signal(SIGINT, control_c);
	signal(SIGQUIT, SIG_IGN);
	if (init_varbox(env))
		return (ft_lstclear(&g_varbox->enviroment, free_content_lst), 1);
	while (!g_varbox->exit)
	{
		command_ln = readline("\033[0;37mJAVITORSHELL > ");
		if (!command_ln)
			break ;
		add_history(command_ln);
		tree = ft_build_cmdtree(command_ln);
		if (!tree)
			continue ;
		ft_exec_cmdtree(tree);
		ft_free_cmdtree(tree);
	}
	exit_code = g_varbox->exit_code;
	ft_lstclear(&g_varbox->enviroment, free_content_lst);
	return (unlink(".antiJose"), exit_code);
}
