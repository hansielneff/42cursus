/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:58:47 by helneff           #+#    #+#             */
/*   Updated: 2023/03/09 16:22:06 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "../../lexer/lexer.h"
# include "../../lexer/tokens/token.h"
# include "../../state.h"

typedef enum s_node_type
{
	invalid_node,
	expression_node,
	command_node,
	term_node,
	expansion_node,
	expand_str_node,
	raw_str_node,
	word_node,
	separator_node,
	pipe_node,
	redirect_node
}	t_node_type;

typedef struct s_node
{
	t_node_type		type;
	t_token			*token;
	struct s_node	*left;
	struct s_node	*right;
	struct s_node	*args;
}	t_node;

t_node	*create_node(t_token *token, t_node *left, t_node *right);
void	free_ast(t_node	*ast);

t_node	*parse_expression(t_lexer *lexer, t_state *state);
t_node	*parse_command(t_lexer *lexer, t_state *state);
t_node	*parse_term(t_lexer *lexer, t_state *state);
t_node	*parse_option(t_lexer *lexer);
t_node	*parse_separator(t_lexer *lexer);
t_node	*parse_expansion(t_lexer *lexer, t_state *state);
t_node	*parse_question_mark(t_lexer *lexer);
t_node	*parse_word(t_lexer *lexer, t_state *state);
t_node	*parse_raw_str(t_lexer *lexer, t_state *state);
t_node	*parse_expand_str(t_lexer *lexer, t_state *state);
t_node	*parse_pipe(t_lexer *lexer, t_state *state);
t_node	*parse_redirect(t_lexer *lexer, t_state *state);

#endif
