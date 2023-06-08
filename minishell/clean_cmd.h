/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_cmd.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atalaver <atalaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:31:51 by jahernan          #+#    #+#             */
/*   Updated: 2023/03/27 13:13:37 by atalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAN_CMD_H
# define CLEAN_CMD_H

int	ft_begin_no_par_idx(char *cmd_ln, int pars_cnt);
int	ft_end_no_par_idx(char *cmd_ln, int pars_cnt);
int	ft_is_redundant_bar(char *cmd_ln, int i, int open_cnt);
#endif
