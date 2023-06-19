/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atalaver <atalaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:25:59 by jahernan          #+#    #+#             */
/*   Updated: 2023/06/19 18:55:05 by atalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clean_cmd.h"
#include "libft/libft.h"
#include "types.h"

static int	ft_count_bars(char *cmd)
{
	int	i;
	int	count;
	int	*q;

	q = (int *)ft_calloc(2, sizeof(int));
	if (!q)
		return (1);
	i = 0;
	count = 0;
	while (cmd[i])
	{
		quotes(cmd[i], q);
		if (cmd[i] == '(' && !q[1])
			count++;
		else if (cmd[i] == ')' && !q[1])
			count--;
		if (count < 0)
			return (free(q), 1);
		i++;
	}
	return (free(q), count);
}

static char	*ft_straight_bars(char *cmd)
{
	int		len;
	char	*aux;
	char	*aux2;

	aux = clean_spaces(cmd);
	free(cmd);
	cmd = NULL;
	len = ft_strlen(aux);
	while (!ft_count_bars(aux) && aux[0] == '(' && aux[len - 1] == ')')
	{
		if (cmd)
			free(cmd);
		cmd = clean_spaces(aux);
		aux2 = aux;
		aux = ft_substr(aux, 1, len - 2);
		free(aux2);
		len = ft_strlen(aux);
	}
	if (!ft_count_bars(aux))
	{
		if (cmd)
			free(cmd);
		cmd = ft_strdup(aux);
	}
	return (free(aux), cmd);
}

static int	ft_check_operators(char *cmd)
{
	int	i;
	int	j;
	int	*q;

	q = (int *)ft_calloc(2, sizeof(int));
	if (!q)
		return (1);
	i = 0;
	while (cmd[i])
	{
		quotes(cmd[i], q);
		if (cmd[i] == '&' && !q[1])
		{
			if (ft_strncmp(&cmd[i], "&&", 2))
				return (free(q), 1);
			else
				i++;
			//Derecha
			j = i + 1;
			while (cmd[j] && ft_isspace(cmd[j]))
				j++;
			if (cmd[j] == ')' || cmd[j] == '&' || cmd[j] == '|')
				return (free(q), 1);
			//Izquierda
			j = i - 2;
			while (j > 0 && ft_isspace(cmd[j]))
				j--;
			if (j <= 0 || cmd[j] == '(' || cmd[j] == '&' || cmd[j] == '|')
				return (free(q), 1);
		}
		else if (cmd[i] == '|' && !q[1])
		{
			if (!ft_strncmp(&cmd[i], "||", 2))
				i++;
			//Derecha
			j = i + 1;
			while (cmd[j] && ft_isspace(cmd[j]))
				j++;
			if (cmd[j] == ')' || cmd[j] == '&' || cmd[j] == '|')
				return (free(q), 1);
			//Izquierda
			j = i - 2;
			while (j > 0 && ft_isspace(cmd[j]))
				j--;
			if (j <= 0 || cmd[j] == '(' || cmd[j] == '&' || cmd[j] == '|')
				return (free(q), 1);
		}
		i++;
	}
	return (free(q), 0);
}

static char	*ft_check_comillas(char *cmd, int i)
{
	int		*q;
	char	*aux;
	char	*aux2;

	q = (int *)ft_calloc(2, sizeof(int));
	if (!q)
		return (NULL);
	while (cmd[i])
		quotes(cmd[i++], q);
	while (q[1])
	{
		aux = readline("> ");
		aux2 = cmd;
		cmd = ft_strjoin(cmd, "\n");
		free(aux2);
		aux2 = cmd;
		cmd = ft_strjoin(cmd, aux);
		free(aux2);
		i = 0;
		while (aux[i])
			quotes(aux[i++], q);
		free(aux);
	}
	return (free(q), cmd);
}

char	*ft_cpy_cmd_clean(char *cmd_ln)
{
	char	*aux;
	char	*aux2;
	int		i;

	i = 0;
	if (!ft_strlen(cmd_ln))
		return (cmd_ln);
	while (cmd_ln[i] && ft_isspace(cmd_ln[i]))
		i++;
	if (!cmd_ln[i])
		return (cmd_ln);
	cmd_ln = ft_check_comillas(cmd_ln, 0);
	if (!cmd_ln)
		return (printf("Error comillas\n"), NULL);
	if (ft_check_operators(cmd_ln))
		return (free(cmd_ln), printf("Invalid operators\n"), NULL);
	if (ft_count_bars(cmd_ln))
		return (free(cmd_ln), printf("Invalid ()\n"), NULL);
	aux = ft_straight_bars(cmd_ln);
	if (!aux)
		return (NULL);
	aux2 = clean_spaces(aux);
	if (!aux2)
		return (free(aux), NULL);
	if (ft_strlen(aux2) > 0)
		return (free(aux), aux2);
	else
		return (free(aux), free(aux2), printf("Invalid ()\n"), NULL);
}

/*
int	main()
{
	char *s = ft_strdup("((ls  &&  ls ) ||  '( ls      libft )')");
	char *res = ft_cpy_cmd_clean(s);
	printf("S:%s\n",s);
	printf("Filtrado:%s\n", res);
	free(res);
	return (0);
}
*/
