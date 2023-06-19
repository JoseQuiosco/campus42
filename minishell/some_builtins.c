/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atalaver <atalaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:48:27 by atalaver          #+#    #+#             */
/*   Updated: 2023/06/19 10:16:57 by atalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

extern t_varbox	g_varbox;

void	ft_pwd(char **cmd_opt)
{
	(void) cmd_opt;
	printf("%s\n", g_varbox.path);
}

//La variable de salida se copia por lo que hay que buscar una solucion
void	ft_exit(char **cmd_opt)
{
	(void) cmd_opt;
	*g_varbox.salir = 1;
}
