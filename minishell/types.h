/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atalaver <atalaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:43:49 by jahernan          #+#    #+#             */
/*   Updated: 2023/06/19 22:45:05 by atalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"
# include "shell_utils.h"
# include <dirent.h>
# include <sys/types.h>

# define T_LEAF 0
# define T_OR 1
# define T_AND 2
# define T_ERROR 3

typedef struct s_cmdtree {
	int					type;
	int					rc;
	struct s_cmdtree	*left;
	struct s_cmdtree	*right;
	char				*cmd;
}	t_cmdtree;

typedef struct ficheros
{
	int		fi;
	int		ft;
	int		fs;
	int		control_i;
}	t_ficheros;

typedef struct varbox
{
	char		path[1024];
	t_list		*enviroment;
	int			exit_code;
}	t_varbox;

typedef struct ejevars
{
	t_ficheros	tp;
	pid_t		pid;
	char		*route;
	int			status;
	int			i;
	int			j;
	int			npipes;
	int			control_route;
}	t_ejevars;

typedef struct infowc
{
	int		nwc;
	int		wci;
	int		wcf;
	char	**patrons;
	char	*ptr_f;
	int		r;
}	t_infowc;

t_cmdtree	*ft_build_cmdtree(char *cmd);
void		ft_exec_cmdtree(t_cmdtree *tree);
void		ft_free_cmdtree(t_cmdtree *tree);
char		*export_value(char *var, t_list	*enviroment);
char		*expand_envar(char *line, t_list *enviroment);
int			ejecutor_i(char *ins);
int			actualizar_exit_code(int code);
char		*clean_spaces(char *str);
char		*strdeleted(char *s, int p1, int p2);
char		*search_name(char *cmd, int len);
int			salida(char *cmd, t_ficheros *tp, int type);
int			entrada(char *cmd, t_ficheros *tp, int type);
char		*open_and_format(char *s, t_ficheros *tp, int i, char *cmd);
void		ft_freedom(char **inpipes, char **cmd_opt, int **pipes,
				char *route);
int			**creat_pipes(int npipes);
int			count_pipes(char **inpipes);
char		*find_path(char *cmd, int *control, int i);
int			procrear(t_ejevars *v, char **inpipes, int **pipes, char **cmd_opt);
t_list		*find_node_enviro_with_key(char *key, t_list *list);
t_list		*wildcard_gestor(char *str);

//BUILTINS
void		ft_pwd(char **cmd_opt);
void		ft_exit(char **cmd_opt);
#endif
