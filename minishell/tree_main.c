/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:23:54 by atalaver          #+#    #+#             */
/*   Updated: 2023/06/06 17:18:28 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

//TODO: (")")
//(()ignore)
//(\))
//"()"
//(a) c  && b
//prog "(" && ( a && b)
//("\)") && b

static int	ft_tree_type(char *cmd, int op_idx)
{
	if (op_idx == -1)
		return (T_LEAF);
	else if (cmd[op_idx] == '|')
		return (T_OR);
	else if (cmd[op_idx] == '&')
		return (T_AND);
	else
	{
		printf("%c%c is not a valid operator!\n", cmd[op_idx], cmd[op_idx + 1]);
		return (T_ERROR);
	}
}

/*
int	ft_malloc_children(t_cmdtree *tree)
{
	tree->left = malloc(sizeof(t_cmdtree));
	if (tree->left == NULL)
		return (1);
	tree->right = malloc(sizeof(t_cmdtree));
	if (!tree->right)
	{
		free (tree->left);
		tree->left = NULL;
		return (1);
	}
	return (0);
}
*/

t_cmdtree	*ft_build_cmdtree(char *cmd_ln)
{
	t_cmdtree	*tree;
	char		*left_cmd;
	char		*right_cmd;
	int			op_idx;

	tree = malloc(sizeof(t_cmdtree));
	tree->cmd = ft_cpy_cmd_clean(cmd_ln);
	free(cmd_ln);
	op_idx = ft_find_op_idx(tree->cmd);
	tree->type = ft_tree_type(tree->cmd, op_idx);
	if (tree->type == T_LEAF)
		return (tree);
	left_cmd = ft_strcpy_range(tree->cmd, 0, op_idx);
	tree->left = ft_build_cmdtree(left_cmd);
	right_cmd = ft_strcpy_range(tree->cmd, op_idx + 2, ft_strlen(tree->cmd));
	tree->right = ft_build_cmdtree(right_cmd);
	return (tree);
}

/**
 * TODO: Execute commands of the tree
 * @param tree Tree with the commands and operators
 * */
void	ft_exec_cmdtree(t_cmdtree *tree)
{
	if (tree->type == T_LEAF)
		tree->rc = ejecutor_i(tree->cmd);
	else
	{
		if (tree->type == T_AND)
		{
			ft_exec_cmdtree(tree->left);
			if (tree->left->rc == 0)
				ft_exec_cmdtree(tree->right);
		}
		else if (tree->type == T_OR)
		{
			ft_exec_cmdtree(tree->left);
			if (tree->left->rc != 0)
				ft_exec_cmdtree(tree->right);
		}
		if (tree->left->rc || tree->right->rc)
			tree->rc = 1;
		else
			tree->rc = 0;
	}
}

/**
 * TODO: Free tree
 * @param tree Tree with the commands and operators
 * */
void	ft_free_cmdtree(t_cmdtree *tree)
{
	if (tree->type != T_LEAF)
	{
		ft_free_cmdtree(tree->left);
		ft_free_cmdtree(tree->right);
	}
	free(tree->cmd);
	free(tree);
}
