/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:59:38 by helneff           #+#    #+#             */
/*   Updated: 2023/03/09 12:55:57 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

#include "ast.h"

t_node	*create_node(t_token *token, t_node *left, t_node *right)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->token = token;
	node->left = left;
	node->right = right;
	node->type = 0;
	node->args = NULL;
	return (node);
}

void	free_ast(t_node	*ast)
{
	if (!ast)
		return ;
	free_ast(ast->args);
	free_ast(ast->left);
	free_ast(ast->right);
	free_token(ast->token);
	free(ast);
}
