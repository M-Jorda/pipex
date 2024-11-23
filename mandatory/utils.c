/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:00:33 by decortejohn       #+#    #+#             */
/*   Updated: 2024/11/23 15:45:06 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	ft_waitpid(pid_t pid, int status)
{
	waitpid(pid, &status, 0);
	if (!WIFEXITED(status) && !WEXITSTATUS(status))
		return (status);
	return (status);
}

int	ft_cmd_ok(char *cmd, t_arg *arg)
{
	int	size_cmd;

	size_cmd = ft_strlen(cmd);
	if (size_cmd > ARG_MAX)
		ft_ppx_err("Argument too long", ft_freecpy(cmd), E2BIG, arg);
	if (!access(cmd, X_OK))
		return (0);
	ft_ppx_err("Argument too long", ft_freecpy(cmd), E2BIG, arg);
	return (-1);
}