/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:33:13 by tkuramot          #+#    #+#             */
/*   Updated: 2023/09/03 19:35:22 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

static void	print_minishell(void)
{
	ft_dprintf(STDERR_FILENO, "                                   __              ___    ___\n");
	ft_dprintf(STDERR_FILENO, "           __          __         /\\ \\            /\\_ \\  /\\_ \\\n");
	ft_dprintf(STDERR_FILENO, "  ___ ___ /\\_\\    ___ /\\_\\    ____\\ \\ \\___      __\\//\\ \\ \\//\\ \\\n");
	ft_dprintf(STDERR_FILENO, "/' __` __`\\/\\ \\ /' _ `\\/\\ \\  /',__\\\\ \\  _ `\\  /'__`\\\\ \\ \\  \\ \\ \\\n");
	ft_dprintf(STDERR_FILENO, "/\\ \\/\\ \\/\\ \\ \\ \\/\\ \\/\\ \\ \\ \\/\\__, `\\\\ \\ \\ \\ \\/\\  __/ \\_\\ \\_ \\_\\ \\_\n");
	ft_dprintf(STDERR_FILENO, "\\ \\_\\ \\_\\ \\_\\ \\_\\ \\_\\ \\_\\ \\_\\/\\____/ \\ \\_\\ \\_\\ \\____\\/\\____\\/\\____\\\n");
	ft_dprintf(STDERR_FILENO, " \\/_/\\/_/\\/_/\\/_/\\/_/\\/_/\\/_/\\/___/   \\/_/\\/_/\\/____/\\/____/\\/____/\n\n");
}

int	main(void)
{
	extern char	**environ;
	char		*line;
	t_token		*lst;
	t_token		*buf;
	t_env		*env_lst;

	print_minishell();
	env_lst = env_lst_init();
	rl_outstream = stderr;
	while (true)
	{
		line = readline("\x1b[32mminishell$ \x1b[0m");
		if (!line)
			return (1);
		if (*line)
			add_history(line);
		lst = tokenize(line);
		buf = lst;
		while (lst)
		{
			//printf("[%s]\n", lst->word);
			lst = lst->next;
		}
		if (buf)
			mini_handle_command(buf, env_lst);
		free(line);
	}
	return (0);
}

// int main(void)
// {
// 	t_env	*env_lst;
// 	env_lst = env_lst_init();
// 	mini_env(env_lst);
// 	free_all_env_lst(env_lst);
// 	return (0);
// }

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q minishell");
// }
