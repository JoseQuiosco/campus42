/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atalaver <atalaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:48:27 by atalaver          #+#    #+#             */
/*   Updated: 2023/06/24 23:11:56 by atalaver         ###   ########.fr       */
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

int	ft_echo(char **cmd_opt)
{
	int	option;
	int	i;

	option = 0;
	i = 1;
	if (ft_len_matrix2(cmd_opt) > 1)
	{
		while (cmd_opt[i] && !ft_strcmp("-n", cmd_opt[i]))
		{
			option = 1;
			i++;
		}
		while (cmd_opt[i])
		{
			printf("%s", cmd_opt[i++]);
			if (cmd_opt[i])
				printf(" ");
		}
	}
	if (!option)
		printf("\n");
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
	ft_order_list(lista);
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

static int	ft_check_var_name(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (!i && !ft_isalpha(s[i]))
			return (0);
		if (i)
		{
			if (!ft_isalnum(s[i]) && !(s[i] == '_'))
				return (0);
		}
		i++;
	}
	return (1);
}

static int	ft_export_args(char **cmd_opt, int i, char **var_val, t_list *lista)
{
	char	*cont;
	t_list	*aux;
	int		code;

	code = 0;
	while (cmd_opt[++i])
	{
		var_val = ft_split(cmd_opt[i], '=');
		if (!var_val)
			return (1);
		if (!ft_check_var_name(var_val[0]) || cmd_opt[i][0] == '=')
		{
			printf("Not valid name\n");
			code = 1;
		}
		else if (var_val[1])
		{
			aux = find_node_enviro_with_key(var_val[0], lista);
			cont = ft_strdup(cmd_opt[i]);
			if (aux)
			{
				free(aux->content);
				aux->content = cont;
			}
			else
			{
				aux = ft_lstnew(cont);
				if (!aux)
					return (free(cont), ft_free_params(var_val), 1);
				ft_lstadd_back(&lista, aux);
			}
		}
		ft_free_params(var_val);
	}
	return (code);
}

//crear variables
int	ft_export(char **cmd_opt)
{
	t_list	*lista;
	t_list	*code;
	t_list	*name;
	char	**split;

	lista = g_varbox->enviroment;
	code = find_node_enviro_with_key("?", g_varbox->enviroment);
	name = find_node_enviro_with_key("0", g_varbox->enviroment);
	if (!cmd_opt[1])
	{
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
	}
	else
		return (ft_export_args(cmd_opt, 0, 0, g_varbox->enviroment));
	return (0);
}

static t_list *ft_lstdel_last(t_list **list)
{
	t_list	*aux;
	t_list	*first;

	first = *list;
	if (!(*list)->next)
	{
		free((*list));
		return (NULL);
	}
	while ((*list)->next->next)
		(*list) = (*list)->next;
	aux = (*list)->next;
	(*list)->next = NULL;
	free(aux);
	return (first);
}

int	ft_unset(char **cmd_opt)
{
	t_list	*var;
	int		i;

	i = 0;
	while (cmd_opt[++i])
	{
		if (!ft_check_var_name(cmd_opt[i]))
			continue ;
		var = find_node_enviro_with_key(cmd_opt[i], g_varbox->enviroment);
		if (var)
		{
			free (var->content);
			while (var->next)
			{
				var->content = var->next->content;
				var = var->next;
			}
			g_varbox->enviroment = ft_lstdel_last(&(g_varbox->enviroment));
		}
	}
	return (0);
}
