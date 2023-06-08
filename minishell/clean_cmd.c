/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:25:59 by jahernan          #+#    #+#             */
/*   Updated: 2023/05/25 19:31:10 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clean_cmd.h"
#include "libft/libft.h"

/**
 * TODO: Count all redundant parentheses
 * @param cmd_ln Command text
 * @return Number of redundant parentheses
 * */
static int	ft_cnt_redundant_bars(char *cmd_ln)
{
	int	open_cnt;
	int	i;

	i = 0;
	open_cnt = 0;
	while (1)
	{
		while (ft_isspace(cmd_ln[i]))
		{
			i++;
		}
		if (cmd_ln[i] == '(')
		{
			if (ft_is_redundant_bar(cmd_ln, i, open_cnt))
				open_cnt++;
			i++;
		}
		else
			break ;
	}
	return (open_cnt);
}

/**
 * !: Deprecated
 * *: Only count right side
 * TODO: Count close bars
 * @param cmd_ln Command text
 * @return Number of close bars
 * 
static int	ft_cnt_close_par(char *cmd_ln)
{
	int	i;
	int	close_cnt;

	i = ft_strlen(cmd_ln) - 1;
	close_cnt = 0;
	while (i >= 0)
	{
		while (i > 0 && ft_isspace(cmd_ln[i]))
		{
			i--;
		}
		if (cmd_ln[i] == ')')
		{
			i--;
			close_cnt++;
		}
		else
			break ;
	}
	return (close_cnt);
}
*/

/**
 * !: Deprecated
 * TODO: Count redundant bars
 * @param cmd_ln Command text
 * @return Min number of bars found
 * 
int	ft_cnt_redundant_pars(char *cmd_ln)
{
	int	open_cnt;
	int	close_cnt;

	open_cnt = ft_cnt_open_par(cmd_ln);
	close_cnt = ft_cnt_close_par(cmd_ln);
	return (ft_min(open_cnt, close_cnt));
}
*/

char	*ft_rm_pars(char *cmd_ln, int pars_cnt)
{
	int	i;
	int	j;

	i = ft_begin_no_par_idx(cmd_ln, pars_cnt);
	j = ft_end_no_par_idx(cmd_ln, pars_cnt);
	return (ft_strcpy_range(cmd_ln, i, j));
}

/**
 * TODO: Remove redundant parentheses
 * @param cmd_ln Command text
 * @return A newly allocated string that contains no redundant parentheses.
 * (i.e `((a && b))` would become `a && b`. `((a && b) && c)` to `(a && b) && c`
 * */
char	*ft_cpy_cmd_clean(char *cmd_ln)
{
	int		pars_cnt;
	char	*str;

	pars_cnt = ft_cnt_redundant_bars(cmd_ln);
	str = ft_rm_pars(cmd_ln, pars_cnt);
	return (str);
}
