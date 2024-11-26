/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 18:31:27 by jdecorte          #+#    #+#             */
/*   Updated: 2024/11/26 17:05:55 by jjorda           ###   ########.fr       */
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

/* ***************************** ERROR MESSAGES ***************************** */

# define ERR_MALL_M	"Cannot allocate memory"
# define PERMISSION	"Permission denied"
# define BAD_FD		"Bad file descriptor"
# define NOT_A_FILE	"No such file or directory"
# define NOT_A_CMD	"command not found"
# define CMD_TOO_L	"command too long"

/* ******************************* ERROR NAME ******************************* */

# define ERR_MALL_N	"malloc failed"
# define STD_IN		"STDIN"
# define STD_OUT	"STDOUT"
# define FORK_FAIL	"fork failed"

/* ################################# UTILS_C ################################ */

char	*ft_bns_getpath(char *cmd, t_arg *args);
char	*ft_bns_escape(char *str);
int		ft_bns_pidmaker(t_arg *args, int ac);

/* ################################# ERROR_C ################################ */

void	ft_bns_free_tab(char **tab);
void	ft_bns_exit_handler(void);
void	ft_bns_ppx_err(char *err, char *name, int ext, t_arg *arg);
t_arg	*ft_bns_free_arg(t_arg *arg);

#endif