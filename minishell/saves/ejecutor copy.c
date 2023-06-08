/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejecutor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:31:57 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/05/25 21:25:39 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "types.h"
# include <readline/readline.h>

char	*clean_spaces(char *str)
{
	char	*newstr;
	int		i;
	int		j;
	int		*q;

	i = 0;
	j = 0;
	q = (int *)ft_calloc(2, sizeof(int));
	if (q == NULL)
		return (NULL);
	newstr = ft_strtrim((const char *)str, " ");
	if (newstr == NULL)
		return (free(q), NULL);
	while (newstr != NULL && newstr[i] != '\0')
	{
		newstr[j++] = newstr[i];
		if (!quotes(newstr[i++], q))
		{
			if (!q[1] && newstr[i - 1] == ' ')
			{
				while (newstr[i] == ' ')
					i++;
			}
		}
	}
	newstr[j] = '\0';
	return (free(q), newstr);
}

/**
 * @brief Delete a section of a string
 * !: Free(s) in function
 * 
 * @param s String
 * @param p1 Init index
 * @param p2 End index
 * @return char* 
 */
char	*strdeleted(char *s, int p1, int p2)
{
	int		len;
	char	*sub1;
	char	*sub2;
	char	*joined;
	char	*result;

	len = ft_strlen(s);
	if (!s)
		return (NULL);
	if ((p1 < 0 || p1 > len - 1) || (p2 < 0 || p2 > len - 1) || p2 < p1)
		return (free(s), NULL);
	sub1 = ft_substr(s, 0, p1);
	if (!sub1)
		return (free(s), NULL);
	sub2 = ft_substr(s, p2 + 1, len - p2);
	if (!sub2)
		return (free(s), free(sub1), NULL);
	free(s);
	joined = ft_strjoin(sub1, sub2);
	if (!joined)
		return (free(sub1), free(sub2), NULL);
	result = clean_spaces(joined);
	if (!result)
		return (free(sub1), free(sub2), free(joined), NULL);
	return (free(sub1), free(sub2), free(joined), result);
}

char	*search_name(char *cmd)
{
	int		i;
	int		j;
	int		len;
	char	*name;
	int		*q;

	i = 0;
	len = 0;
	q = (int *)ft_calloc(2, sizeof(int));
	if (q == NULL)
		return (NULL);
	while (cmd[i] == ' ')
		i++;
	if (cmd[i] == '\'' || cmd[i] == '"')
		quotes(cmd[i++], q);
	while (cmd[i] && (cmd[i] != ' ' || q[1]))
	{
		if (!quotes(cmd[i], q))
		{
			if (cmd[i] != (char)q[0])
				len++;
		}
		i++;
	}
	name = (char *)ft_calloc(len + 1, 1);
	if (!name)
		return (NULL);
	i = 0;
	j = 0;
	while (cmd[i] == ' ')
		i++;
	if (cmd[i] == '\'' || cmd[i] == '"')
		quotes(cmd[i++], q);
	while (cmd[i] && (cmd[i] != ' ' || q[1]))
	{
		if (!quotes(cmd[i], q))
		{
			if (cmd[i] != (char)q[0])
				name[j++] = cmd[i];
		}	
		i++;
	}
	return (name);
}

void	read_buffer(t_ficheros *tp, char *end)
{
	char	*new_line;
	char	*aux;

	new_line = readline("> ");
	while (ft_strcmp(new_line, end))
	{
		aux = ft_strjoin(new_line, "\n");
		write(tp->ft, aux, ft_strlen(aux));
		free(new_line);
		free(aux);
		new_line = readline("> ");
	}
	free(new_line);
}

int	entrada(char *cmd, t_ficheros *tp, int type)
{
	char	*name;
	int		len;

	name = search_name(cmd);
	if (!name)
		return (0);
	len = ft_strlen(name);
	if (!len)
		return (free(name), 0);
	if (tp->fi > 0)
	{
		close(tp->fi);
		tp->fi = 0;
	}
	if (tp->ft > 0)
	{
		close(tp->ft);
		tp->ft = 0;
	}
	if (type == 0)
		tp->fi = open(name, O_RDONLY);
	if (type == 1)
	{
		tp->ft = open("antiJose", O_WRONLY | O_TRUNC | O_CREAT, 0000777);
		read_buffer(tp, name);
		close(tp->ft);
		tp->ft = open("antiJose", O_RDONLY);
	}
	if (cmd[0] == ' ')
	{
		if (cmd[1] == '\'' || cmd[1] == '"')
			return (free(name), len + 1 + 2 + type);
		return (free(name), len + 1 + type);
	}
	else
	{
		if (cmd[0] == '\'' || cmd[0] == '"')
			return (free(name), len + 2 + type);
		return (free(name), len + type);
	}
	if (name)
		free(name);
	return (0);
}

int	salida(char *cmd, t_ficheros *tp, int type)
{
	char	*name;
	char	*new_line;
	char	*aux;
	int		len;

	name = search_name(cmd);
	if (!name)
		return (0);
	len = ft_strlen(name);
	if (!len)
		return (free(name), 0);
	if (tp->fs > 0)
	{
		close(tp->fs);
		tp->fs = 0;
	}
	if (type == 0)
		tp->fs = open(name, O_WRONLY | O_TRUNC | O_CREAT, 0000777);
	else
		tp->fs = open(name, O_WRONLY | O_APPEND | O_CREAT, 0000777);
	if (cmd[0] == ' ')
	{
		if (cmd[1] == '\'' || cmd[1] == '"')
			return (free(name), len + 1 + 2 + type);
		return (free(name), len + 1 + type);
	}
	else
	{
		if (cmd[0] == '\'' || cmd[0] == '"')
			return (free(name), len + 2 + type);
		return (free(name), len + type);
	}
	if (name)
		free(name);
	return (0);
}

char	*open_and_format(char *s, t_ficheros *tp)
{
	char	*cmd;
	int		i;
	int		j;
	int		*q;

	cmd = clean_spaces(s);
	printf("clean:%s\n", cmd);
	//free(s);
	if (!cmd)
		return (NULL);
	q = (int *)ft_calloc(2, sizeof(int));
	if (q == NULL)
		return (free(cmd), NULL);
	i = -1;
	j = 0;
	while (cmd[++i])
	{
		if (!quotes(cmd[i], q))
		{
			if (cmd[i] == '<' && !q[1])
			{
				if (cmd[i + 1] == '<' && (cmd[i + 2] == '<' || cmd[i + 2] == '>'))
					return (printf("ERROR DE SINTAXIS\n"), free(cmd), NULL);
				if (cmd[i + 1] == '<')
					j = entrada(&cmd[i + 2], tp, 1);
				else
					j = entrada(&cmd[i + 1], tp, 0);
				if (j > 0)
					cmd = strdeleted(cmd, i, j + i);
				else
					return (free(cmd), NULL);
				i = -1;
			}
			else if (cmd[i] == '>' && (q[0] == 0 && q[1] == 0))
			{
				if (cmd[i + 1] == '>' && (cmd[i + 2] == '<' || cmd[i + 2] == '>'))
					return (printf("ERROR DE SINTAXIS\n"), free(cmd), NULL);
				if (cmd[i + 1] == '>')
					j = salida(&cmd[i + 2], tp, 1);
				else
					j = salida(&cmd[i + 1], tp, 0);
				if (j > 0)
					cmd = strdeleted(cmd, i, j + i);
				else
					return (free(cmd), NULL);
				i = -1;
			}
		}
	}
	return (cmd);
}

void ft_leaks3(void)
{
	system("leaks -q a.out");
}

char	*find_path(char *cmd, char **paths)
{
	int		i;
	char	*fullpath;
	char	*aux;

	i = 0;
	while (paths[i])
	{
		fullpath = ft_strjoin(paths[i], "/");
		if (!fullpath)
			return (cmd);
		aux = fullpath;
		fullpath = ft_strjoin(fullpath, cmd);
		free(aux);
		if (!fullpath)
			return (cmd);
		if (access(fullpath, F_OK | X_OK) == 0)
			return (fullpath);
		i++;
	}
	return (cmd);
}

int	ejecutor_i(char *ins, char **paths)
{
	t_ficheros	tp;
	pid_t		pid;
	char		*route;
	char		**cmd_opt;
	int			status;
	int			err;

	tp.fi = 0;
	tp.ft = 0;
	tp.fs = 0;
	err = 0;
	ins = open_and_format(ins, &tp);
	cmd_opt = ft_split_m(ins, ' ');
	if (access(ins, F_OK | X_OK) != 0)
		route = find_path(cmd_opt[0], paths);
	else
		route = ins;
	pid = fork();
	if (pid < 0)
		return (free(route), ft_free_params(cmd_opt), 0);
	else if (pid == 0)
	{
		if (tp.fi > 0)
			dup2(tp.fi, STDIN_FILENO);
		if (tp.fi > 0)
			close(tp.fi);
		if (tp.ft > 0)
			dup2(tp.ft, STDIN_FILENO);
		if (tp.ft > 0)
			close(tp.ft);
		if (tp.fs > 0)
			dup2(tp.fs, STDOUT_FILENO);
		if (tp.fs > 0)
			close(tp.fs);
		err = execve(route, cmd_opt, NULL);
		if (err < 0)
		{
			printf("ERROR CABRON...\n");
			if (errno == ENOENT)
				exit(127);
			else if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
		waitpid(pid, &status, 0);
	return (WEXITSTATUS(status));
}

// int main(int argc, char *argv[], char **envp)
// {
// 	char	**paths;
// 	int		i = 0;
// 	int		code = 0;

// 	paths = ft_split(getenv("PATH"), ':');
// 	if (!paths)
// 		return (0);
// 	code = ejecutor_i(argv[1], paths);
// 	ft_free_params(paths);
// 	return (code);
// }

// int main(int argc, char *argv[], char **envp)
// {
// 	pid_t	pid;
// 	int		*status;
// 	int		*code;
// 	char	*route;

// 	char *s = " > salida < entrada echo holas   ";
// 	t_ficheros tp;
// 	code = malloc(sizeof(int));
// 	*code = 0;
// 	tp.fi = 0;
// 	tp.fs = 0;
// 	tp.buffer = (char *)malloc(1);
// 	tp.buffer[0] = 0;
// 	//atexit(ft_leaks3);
// 	char *r = open_and_format(s, &tp);
// 	char **cmd_opt;
// 	cmd_opt = ft_split_m(r, ' ');
// 	int i = 0;
// 	while (cmd_opt && cmd_opt[i])
// 		printf("%s\n", cmd_opt[i++]);
// 	// printf("ORIGINAL:%s\n", s);
// 	// printf("SIN ENTRADAS:%s\n", r);
// 	// printf("FI:%d\n", tp.fi);
// 	// printf("FS:%d\n", tp.fs);
// 	route = ft_strjoin("/bin/", cmd_opt[0]);
// 	if (route == NULL)
// 		return (0);
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		printf("%s\n", envp[0]);
// 		if (execve("\0", cmd_opt, envp) < 0)
// 		{
// 			printf("cagaste %d\n", errno);
// 			*code = errno;
// 			exit(errno);
// 		}
// 	}
// 	wait(0);
// 	if (r)
// 		free(r);
// 	if (tp.buffer)
// 		free(tp.buffer);
// 	if (tp.fi > 0)
// 		close(tp.fi);
// 	if (tp.fs > 0)
// 		close(tp.fs);
// 	return(WEXITSTATUS(*code));
// }
