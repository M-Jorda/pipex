/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:59:44 by jjorda            #+#    #+#             */
/*   Updated: 2024/12/08 13:21:08 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex_bonus.h"

/**
 * Executes a command using execve.
 *
 * @param cmd The command to execute.
 * @param env The environment variables.
 */
static void	ft_exec(char *cmd, t_list *head)
{
	char	**s_cmd;
	char	*path;
	char	err_cmd[64];

	s_cmd = ft_split_arg(cmd);
	if (!s_cmd)
		ft_bns_ppx_err(ERR_MALL_M, ERR_MALL_N, ENOMEM, head);
	path = ft_bns_getpath(s_cmd[0], head);
	if (!path)
	{
		ft_bns_free_tab(s_cmd);
		ft_bns_ppx_err(ERR_MALL_M, ERR_MALL_N, ENOMEM, head);
	}
	ft_strlcpy(err_cmd, s_cmd[0], 64);
	if (execve(path, s_cmd, ft_lstlast(head)->env) == -1)
	{
		ft_bns_free_tab(s_cmd);
		ft_bns_ppx_err(NOT_A_CMD, err_cmd, 127, head);
	}
}

/**
 * Opens a file with the specified mode.
 *
 * @param file The file to open.
 * @param in_or_out 0 for read mode, 1 for write mode.
 * @return The file descriptor, or -1 on error.
 */
int	ft_open_file(char *file, int in_or_out)
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
	else if (in_or_out == 2)
	{
		ret = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
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
 * @param head The arguments structure.
 * @param p_fd The pipe file descriptors.
 */
static inline void	ft_pipein(t_list *head, int i)
{
	pid_t	pid;
	int		p_fd[2];
	int		status;

	if (pipe(p_fd) == -1)
		ft_bns_ppx_err(ERR_MALL_M, ERR_MALL_N, ENOMEM, head);
	pid = fork();
	if (pid == -1)
		ft_bns_ppx_err(ERR_MALL_M, FORK_FAIL, ENOMEM, head);
	if (pid == 0)
	{
		close(p_fd[0]);
		if (dup2(p_fd[1], STDOUT_FILENO) != STDOUT_FILENO)
			ft_bns_ppx_err(BAD_FD, STD_OUT, 1, head);
		ft_exec(ft_nextlst(head, i)->content, head);
		ft_lstfree(&head);
	}
	close(p_fd[1]);
	if (dup2(p_fd[0], STDIN_FILENO) != STDIN_FILENO)
		ft_bns_ppx_err(BAD_FD, STD_IN, 1, head);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		ft_bns_ppx_stop(status, head);
}

/**
 * Handles the parent process execution.
 *
 * @param head The arguments structure.
 * @param p_fd The pipe file descriptors.
 */
static inline int	ft_pipeout(t_list *head, int fd_out)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		ft_bns_ppx_err(ERR_MALL_M, FORK_FAIL, ENOMEM, head);
	if (pid == 0)
	{
		if (dup2(fd_out, STDOUT_FILENO) != STDOUT_FILENO)
			ft_bns_ppx_err(BAD_FD, STD_OUT, 1, head);
		ft_exec(ft_lstn_3(head)->content, head);
		ft_lstfree(&head);
		exit(1);
	}
	waitpid(pid, &status, WUNTRACED);
	return (status);
}

pid_t	ft_bns_pidmaker(t_list *head, int ac, int i)
{
	int		status;
	int		fd_in;
	int		fd_out;

	if (i == 0)
	{
		fd_in = ft_open_file(head->content, 0);
		if (fd_in == -1)
			ft_bns_ppx_err(BAD_FD, "fd_in", 1, head);
		if (dup2(fd_in, STDIN_FILENO) != STDIN_FILENO)
			ft_bns_ppx_err(BAD_FD, STD_IN, 1, head);
	}
	fd_out = ft_open_file(ft_lstn_2(head)->content, 1);
	if (fd_out == -1)
		ft_bns_ppx_err(BAD_FD, "fd_out", 1, head);
	while (++i < ac)
		ft_pipein(head, i);
	status = ft_pipeout(head, fd_out);
	return (status);
}
