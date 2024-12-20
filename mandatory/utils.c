/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:00:33 by decortejohn       #+#    #+#             */
/*   Updated: 2024/12/08 13:30:56 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

/**
 * Executes a command using execve.
 *
 * @param cmd The command to execute.
 * @param env The environment variables.
 */
static void	ft_exec(char *cmd, t_arg *args)
{
	char	**s_cmd;
	char	*path;
	char	err_cmd[64];

	s_cmd = ft_split_arg(cmd);
	if (!s_cmd)
		ft_ppx_err(ERR_MALL_M, ERR_MALL_N, ENOMEM, args);
	path = ft_getpath(s_cmd[0], args);
	if (!path)
	{
		ft_free_tab(s_cmd);
		ft_ppx_err(ERR_MALL_M, ERR_MALL_N, ENOMEM, args);
	}
	ft_strlcpy(err_cmd, s_cmd[0], 64);
	if (execve(path, s_cmd, args->env) == -1)
	{
		ft_free_tab(s_cmd);
		ft_ppx_err(NOT_A_CMD, err_cmd, 127, args);
	}
}

/**
 * Opens a file with the specified mode.
 *
 * @param file The file to open.
 * @param in_or_out 0 for read mode, 1 for write mode.
 * @return The file descriptor, or -1 on error.
 */
static int	ft_open_file(char *file, int in_or_out)
{
	int	ret;

	if (in_or_out == 0 && (access(file, R_OK) == 0))
		ret = open(file, O_RDONLY);
	else if (in_or_out == 1)
	{
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (!(access(file, W_OK) == 0))
			return (-1);
	}
	else
		return (-1);
	return (ret);
}

/**
 * Handles the child process execution.
 *
 * @param args The arguments structure.
 * @param p_fd The pipe file descriptors.
 */
static inline void	ft_child(t_arg *args, int *p_fd)
{
	int		fd;

	fd = ft_open_file(args->file1, 0);
	if (fd < 0)
		ft_ppx_err(NOT_A_FILE, args->file1, 1, args);
	if (dup2(fd, STDIN_FILENO) != STDIN_FILENO)
		ft_ppx_err(BAD_FD, STD_IN, 1, args);
	if (dup2(p_fd[1], STDOUT_FILENO) != STDOUT_FILENO)
		ft_ppx_err(BAD_FD, STD_OUT, 1, args);
	close(p_fd[0]);
	ft_exec(args->cmd1, args);
}

/**
 * Handles the parent process execution.
 *
 * @param args The arguments structure.
 * @param p_fd The pipe file descriptors.
 */
static inline void	ft_parent(t_arg *args, int *p_fd)
{
	int		fd;

	fd = ft_open_file(args->file2, 1);
	if (fd == -1)
		ft_ppx_err(PERMISSION, args->file2, EACCES, args);
	if (dup2(fd, STDOUT_FILENO) != STDOUT_FILENO)
		ft_ppx_err(BAD_FD, STD_OUT, 1, args);
	if (dup2(p_fd[0], STDIN_FILENO) != STDIN_FILENO)
		ft_ppx_err(BAD_FD, STD_IN, 1, args);
	close(p_fd[1]);
	ft_exec(args->cmd2, args);
}

pid_t	ft_pidmaker(t_arg *args, int *p_fd)
{
	pid_t	pid;
	pid_t	pid2;
	int		status;

	pid = fork();
	if (pid == -1)
		ft_ppx_err(ERR_MALL_M, FORK_FAIL, ENOMEM, args);
	if (!pid)
		ft_child(args, p_fd);
	pid2 = fork();
	if (pid2 == -1)
		ft_ppx_err(ERR_MALL_M, FORK_FAIL, ENOMEM, args);
	if (!pid2)
		ft_parent(args, p_fd);
	waitpid(0, &status, WUNTRACED);
	return (status);
}
