/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:15:43 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/06/09 13:49:29 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

void	expand_wildcard(char *str, int i)
{
	struct dirent	*file;
	int				j;
	DIR				*dirp;

	j = 0;
	dirp = opendir(g_varbox.path);
	file = readdir(dirp);
	while (file)
	{
		if (ft_strncmp(str, file->d_name, i) == 0)
		{
			printf("%s\n", file->d_name);
		}
		file = readdir(dirp);
	}
	closedir(dirp);
}

void	wildcard_gestor(char *str)
{
	int				i;
	//char			*expanded;

	i = 0;
	getcwd(g_varbox.path, 1024);
	//expanded = NULL;
	while (str && str[i] != '\0')
	{
		if (str[i] == '*')
		{
			expand_wildcard(str, i);
		}
		i++;
	}
}

int	main(void)
{
	wildcard_gestor("min*");
	return (0);
}
