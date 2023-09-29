/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:15:38 by tsishika          #+#    #+#             */
/*   Updated: 2023/09/29 13:03:02 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include "builtin.h"
# include "exec.h"
# include "parser.h"

# define HEREDOC "/tmp/.HEREDOC"

void	quote_handle_heredoc(char *end_of_file, t_env *env);
void	handle_heredoc(char *end_of_file);

#endif
