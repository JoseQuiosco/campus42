/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_wildcard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:12:51 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/06/19 18:18:39 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

extern t_varbox	g_varbox;

static int	creat_infowc(t_infowc *infowc, char *str, int i, int flag)
{
	infowc->nwc = 0;
	infowc->wci = 0;
	infowc->wcf = 0;
	while (str && str[++i] != '\0')
	{
		if (str[i] == '*')
		{
			if (flag == 0)
				infowc->nwc += 1;
			if (i == 0)
				infowc->wci = 1;
			if (str[i + 1] == '\0')
				infowc->wcf = 1;
			flag = 1;
		}
		else
			flag = 0;
	}
	if (infowc->nwc > 0)
	{
		infowc->patrons = ft_split(str, '*');
		if (infowc->patrons == NULL)
			return (1);
	}
	return (0);
}

 static int initial_analysis(struct dirent *file, t_infowc *infowc, int *wc, int *i)
 {
	if (infowc->nwc == 1 && infowc->wci == 1 && infowc->wcf == 1)
		return (0);
	infowc->ptr_f = file->d_name;
	if (infowc->wci && infowc->nwc == 1)
		*wc += 1;
	else if (infowc->wci)
	{
		infowc->ptr_f = ft_strnstr(infowc->ptr_f, infowc->patrons[*i], ft_strlen(file->d_name));
		if (!infowc->ptr_f)
			return (1);
		infowc->ptr_f += ft_strlen(infowc->patrons[(*i)++]);
		*wc += 1;
	}
	else if (infowc->nwc > 0)
	{
		if (ft_strncmp(infowc->ptr_f, infowc->patrons[*i], ft_strlen(infowc->patrons[*i])) == 0)
		{
			infowc->ptr_f = ft_strnstr(infowc->ptr_f, infowc->patrons[*i], ft_strlen(file->d_name));
			if (!infowc->ptr_f)
				return (1);
			infowc->ptr_f += ft_strlen(infowc->patrons[(*i)++]);
		}
		else
			return (1);
	}
	return (2);
 }

 static int	analize_file(struct dirent *file, t_infowc *infowc, int wc, int i)
{
	infowc->r = initial_analysis(file, infowc, &wc, &i);
	if (infowc->r < 2)
		return (infowc->r);
	while (++wc < infowc->nwc)
	{
		if (wc == infowc->nwc - 1)
			continue;
		infowc->ptr_f = ft_strnstr(infowc->ptr_f, infowc->patrons[i], ft_strlen(infowc->ptr_f));
		if (!infowc->ptr_f)
			return (1);
		infowc->ptr_f += ft_strlen(infowc->patrons[i]);
		if (infowc->patrons[i + 1] != NULL)
			i++;
	}
	if (infowc->wcf && wc == infowc->nwc)
		return (0);
	else
	{
		if (((int)ft_strlen(file->d_name) - (int)ft_strlen(infowc->patrons[i])) < 0)
			return (1);
		infowc->ptr_f = file->d_name + (ft_strlen(file->d_name) - ft_strlen(infowc->patrons[i]));
		if (ft_strcmp(infowc->ptr_f, infowc->patrons[i]) == 0)
			return (0);
	}
	return (1);
}

static t_list	*expand_wildcard(char * str, t_infowc *infowc, t_list *matchs, char *copy)
{
	struct dirent	*file;
	DIR				*dirp;

	dirp = opendir(g_varbox.path);
	file = readdir(dirp);
	while (file)
	{
		if (infowc->nwc == 0 && !((*file->d_name == '.' && (*str != '.')) 
				|| !ft_strcmp(".", file->d_name) || !ft_strcmp("..", file->d_name)))
		{
			if (ft_strcmp(file->d_name, str) == 0)
			{
				copy = ft_strdup(file->d_name);
				ft_lstadd_back(&matchs, ft_lstnew(copy));
			}
		}
		else if (!((*file->d_name == '.' && (*str != '.')) || !ft_strcmp(".", file->d_name) 
					|| !ft_strcmp("..", file->d_name)) && (analize_file(file, infowc, -1, 0) != 1))
		{
				copy = ft_strdup(file->d_name);
				ft_lstadd_back(&matchs, ft_lstnew(copy));
		}
		file = readdir(dirp);
	}
	return (closedir(dirp), matchs);
}

t_list	*wildcard_gestor(char *str)
{
	t_infowc		infowc;
	t_list			*matchs;

	if (*str == '\0')
		return (NULL);
	matchs = NULL;
	if (creat_infowc(&infowc, str, -1, 0))
		return (NULL);
	matchs = expand_wildcard(str, &infowc, matchs, NULL);	
	ft_free_params(infowc.patrons);
	return (matchs);
}
