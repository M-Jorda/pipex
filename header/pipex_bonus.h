/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:42:33 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/22 20:42:46 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

// ENOMEM: Out of memory error code
// 127: Command not found error code
// ENOENT: No such file or directory error code
// EACCES: Permission denied
// STDIN_FILENO: Standard in
// STDOUT_FILENO: Standard out
// STDERR_FILENO: Standard Error

# include "../libft/libft.h"
# include "struct.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>  
# include <stdlib.h>
# include <errno.h>
# include <string.h>

/* ################################# UTILS_C ################################ */

char	*ft_getpath(char *cmd, t_arg *args);
char	*ft_escape(char *str);
int		ft_pidmaker(t_arg *args, int *p_fd);

/* ################################# ERROR_C ################################ */

void	ft_free_tab(char **tab);
void	ft_exit_handler(void);
void	ft_ppx_err(char *err, char *name, int ext, t_arg *arg);
t_arg	*ft_free_arg(t_arg *arg);
int	ft_waitpid(pid_t pid, int status);

#endif