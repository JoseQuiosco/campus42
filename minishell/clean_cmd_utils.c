/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_cmd_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:30:07 by jahernan          #+#    #+#             */
/*   Updated: 2023/05/25 19:30:57 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_begin_no_par_idx(char *cmd_ln, int pars_cnt)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (c < pars_cnt)
	{
		while (cmd_ln[i] != '(')
		{
			i++;
		}
		i++;
		c++;
	}
	return (i);
}

int	ft_end_no_par_idx(char *cmd_ln, int pars_cnt)
{
	int	j;
	int	c;

	c = 0;
	j = ft_strlen(cmd_ln) - 1;
	while (c < pars_cnt)
	{
		while (cmd_ln[j] != ')')
		{
			j--;
		}
		j--;
		c++;
	}
	return (j + 1);
}

/**
 * TODO: Check to the end searching more characters
 * @param cmd_ln Command text
 * @param i index of the bar
 * @param open_cnt Number of redundant bar found
 * @return 0 -> Character no valid found, 1 -> All good
 * */
static int	ft_check_to_the_end(char *cmd_ln, int i, int open_cnt)
{
	while (cmd_ln[++i] != 0)
	{
		if (!ft_isspace(cmd_ln[i]))
		{
			if (cmd_ln[i] == ')' && open_cnt)
				open_cnt--;
			else
				return (0);
		}
	}
	return (1);
}

/**
 * TODO: Check if one bar is redundant searching the other bar
 * @param cmd_ln Command text
 * @param i index of the bar
 * @param open_cnt Number of redundant bar found
 * @return 0 -> No is redundant, 1 -> Is redundant
 * */
int	ft_is_redundant_bar(char *cmd_ln, int i, int open_cnt)
{
	int	count_bars;

	count_bars = 0;
	while (cmd_ln[i] != 0)
	{
		if (cmd_ln[i] == '(')
			count_bars++;
		if (cmd_ln[i] == ')')
		{
			count_bars--;
			if (count_bars == 0)
				return (ft_check_to_the_end(cmd_ln, i, open_cnt));
		}
		i++;
	}
	return (1);
}
