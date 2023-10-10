/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:42:36 by tsishika          #+#    #+#             */
/*   Updated: 2023/10/10 13:30:55 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

void	str_expander(char **str, t_context *ctx)
{
	char	*buf_str;
	char	*sub;
	char	*first;
	char	*ans;
	size_t	i;

	buf_str = *str;
	i = 0;
	first = ft_strdup("");
	while (buf_str[i])
	{
		if (buf_str[i] == SINGLE_QUOTE)
			sub = single_quote_expander(*str, &i);
		else if (buf_str[i] == DOUBLE_QUOTE)
			sub = double_quote_expander(*str, &i, ctx);
		else
			sub = no_quote_expander(*str, &i, ctx);
		ans = ft_strjoin(first, sub);
		free(first);
		free(sub);
		first = ans;
		i++;
	}
	free(buf_str);
	*str = first;
}

void	expand_environ(t_context *ctx)
{
	t_ast *ast;

	if (ctx->sys_error)
		return;
	ast = ctx->ast;
	env_var_expander(ast, ctx);
}

void	env_var_expander(t_ast *ast, t_context *ctx)
{
	t_token	*tmp;

	if (!ast)
		return ;
	env_var_expander(ast->right, ctx);
	env_var_expander(ast->left, ctx);
	tmp = ast->argv;
	while (tmp)
	{
		str_expander(&tmp->word, ctx);
		tmp = tmp->next;
	}
}

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q a.out");
// }
