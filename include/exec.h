/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 22:14:10 by tsishika          #+#    #+#             */
/*   Updated: 2023/09/05 16:17:50 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

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
# include "libft.h"
# include "builtin.h"

// file_access_util.c
int	is_executable(char *command);
int	is_readable(char *command);

// int	exec(char *path, char **env);
int	exec(t_token *token_lst, t_env *env_lst);
char **env_list_to_array(t_env *env_lst);
void	free_two_d_array(char **array);

char **token_lst_to_array(const t_token *command_lst);


#endif
