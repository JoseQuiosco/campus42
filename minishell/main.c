/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:11:19 by atalaver          #+#    #+#             */
/*   Updated: 2023/06/08 13:48:46 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

t_varbox	g_varbox;

void	control_c(int n)
{
	printf("\n");
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
	signal(n, control_c);
}

void	ft_leaks4(void)
{
	system("leaks -q minishell");
}

void	control_d(int n)
{
	(void)n;
	g_varbox.salir = 1;
}

int	init_varbox(char **env)
{
	getcwd(g_varbox.path, 1024);
	g_varbox.enviroment = matrix_to_list((void **)env);
	if (!g_varbox.enviroment)
		return (1);
	actualizar_exit_code(0);
	g_varbox.salir = 0;
	return (0);
}

int	actualizar_exit_code(int code)
{
	char	*aux;
	char	*aux2;
	t_list	*aux3;

	g_varbox.exit_code = code;
	aux = ft_itoa(code);
	if (!aux)
		return (1);
	aux2 = ft_strjoin("?=", aux);
	free(aux);
	if (!aux2)
		return (1);
	aux3 = find_node_enviro_with_key("?", g_varbox.enviroment);
	if (!aux3)
	{
		aux3 = ft_lstnew(aux2);
		if (!aux3)
			return (free(aux2), 1);
		ft_lstadd_back(&g_varbox.enviroment, aux3);
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

	//atexit(ft_leaks4);
	(void)argc;
	(void)argv;
	signal(SIGINT, control_c);
	signal(SIGQUIT, control_d);
	rl_redisplay();
	if (init_varbox(env))
		return (1);
	while (!g_varbox.salir)
	{
		command_ln = readline("JAVITORSHELL > ");
		if (!command_ln)
			break ;
		add_history(command_ln);
		tree = ft_build_cmdtree(command_ln);
		ft_exec_cmdtree(tree);
		ft_free_cmdtree(tree);
	}
	ft_lstclear(&g_varbox.enviroment, free_content_lst);
	unlink(".antiJose");
	return (0);
}
