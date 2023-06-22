/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:48:27 by atalaver          #+#    #+#             */
/*   Updated: 2023/06/22 19:18:02 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

extern t_varbox	*g_varbox;

int	ft_pwd(char **cmd_opt)
{
	(void) cmd_opt;
	if (!getcwd(g_varbox->path, 1024))
		return (printf("Path's length is too long\n"), 1); 
	ft_printf("%s\n", g_varbox->path);
	return (0);
}

//La variable de salida se copia por lo que hay que buscar una solucion
int	ft_exit(char **cmd_opt)
{
	char	*aux;

	g_varbox->exit = 1;
	if (ft_len_matrix2(cmd_opt) > 2)
	{
		aux = ft_strtrim(cmd_opt[1], " ");
		if (!aux)
			return (1);
		if (ft_is_full_digit(aux))
			return (printf("Too much arguments!\n"), free(aux), 1);
		else
			return (printf("Too much arguments!\n"), free(aux), 2);
	}
	else if (ft_len_matrix2(cmd_opt) == 2)
	{
		aux = ft_strtrim(cmd_opt[1], " ");
		if (!aux)
			return (1);
		if (ft_is_full_digit(aux))
			return (free(aux), ft_atoi(cmd_opt[1]));
		else
			return (printf("Argument isn't a number!\n"), free(aux), 2);
	}
	return (0);
}

int	ft_env(char **cmd_opt)
{
	t_list	*lista;
	t_list	*code;
	t_list	*name;

	if (ft_len_matrix2(cmd_opt) >= 2)
		return (printf("Too much arguments!\n"), 1);
	lista = g_varbox->enviroment;
	code = find_node_enviro_with_key("?", g_varbox->enviroment);
	name = find_node_enviro_with_key("0", g_varbox->enviroment);
	while (lista)
	{
		if (lista != code && lista != name)
			printf("%s\n", (char *)lista->content);
		lista = lista->next;
	}
	return (0);
}

//crear variables
int	ft_export(char **cmd_opt)
{
	t_list	*lista;
	t_list	*code;
	t_list	*name;
	char	**split;

	(void)cmd_opt;
	lista = g_varbox->enviroment;
	code = find_node_enviro_with_key("?", g_varbox->enviroment);
	name = find_node_enviro_with_key("0", g_varbox->enviroment);
	while (lista)
	{
		if (lista != code && lista != name)
		{
			split = ft_split(lista->content, '=');
			if (!split)
				return (1);
			printf("declare -x %s=\"%s\"\n", split[0], split[1]);
			free(split);
		}
		lista = lista->next;
	}
	return (0);
}
