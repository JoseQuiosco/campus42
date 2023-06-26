/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_generic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:24:37 by atalaver          #+#    #+#             */
/*   Updated: 2023/06/26 13:31:28 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

extern t_varbox	*g_varbox;

char	*search_wc(int i, int j, char *line, int *q)
{
	char	*aux;
	char	*res;
	t_list	*list;

	if (!q[1] && line[i - 1] == '*')
	{
		while (j >= 0 && !ft_isspace(line[j]))
			j--;
		while (line[i] && !ft_isspace(line[i]))
			i++;
		aux = ft_substr(line, j + 1, i);
		if (!aux)
			return (free(line), NULL);
		list = wildcard_gestor(aux);
		free(aux);
		if (list)
		{
			res = insert_list(line, list, j + 1, &i);
			if (!res)
				return (ft_lstclear(&list, free_content_lst), NULL);
		}
		return (ft_lstclear(&list, free_content_lst), res);
	}
	return (line);
}

char	*insert_content(char *res, t_list *list, int *len)
{
	char	*aux;

	aux = res;
	res = ft_strjoin(res, (char *)list->content);
	free(aux);
	if (!res)
		return (NULL);
	*len += ft_strlen((char *)list->content);
	if (list->next)
	{
		aux = res;
		res = ft_strjoin(res, " ");
		free(aux);
		if (!res)
			return (NULL);
		(*len)++;
	}
	return (res);
}
