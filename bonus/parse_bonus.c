/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:00:00 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/26 16:29:19 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex_bonus.h"

/**
 * Retrieves the value of an environment variable.
 *
 * ENOMEM: Out of memory error code
 *
 * @param name The name of the environment variable.
 * @param envp The environment variables.
 * @return The value of the environment variable, or NULL if not found.
 */
static inline char	*ft_getenv(char *name, t_arg *args)
{
	char	*sub;
	int		i;
	int		j;

	i = 0;
	while (args->env[i])
	{
		j = 0;
		while (args->env[i][j] && args->env[i][j] != '=')
			j++;
		sub = ft_substr(args->env[i], 0, j);
		if (!sub)
			ft_bns_ppx_err(ERR_MALL_M, ERR_MALL_N, ENOMEM, args);
		if (ft_strcmp(sub, name) == 0)
		{
			free(sub);
			return (args->env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

/* char	*ft_freecpy(char *dest, char *mall)
{
	int		i;

	i = -1;
	while (mall[++i])
		dest[i] = mall[i];
	dest[i] = '\0';
	free(mall);
	return (dest);
} */

/**
 * Searches for the executable path in the given paths.
 *
 * @param allpath The array of paths to search.
 * @param s_cmd The command to find.
 * @return The full path to the executable, or NULL if not found.
 */
static inline char	*ft_loop(char **allpath, char **s_cmd, t_arg *args)
{
	char	*path_part;
	char	*exec;
	char	*temp;
	int		i;

	temp = NULL;
	i = -1;
	while (allpath[++i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		if (!path_part)
			ft_bns_ppx_err(ERR_MALL_M, ERR_MALL_N, ENOMEM, args);
		exec = ft_strjoin(path_part, s_cmd[0]);
		if (!exec)
		{
			free(path_part);
			ft_bns_ppx_err(ERR_MALL_M, ERR_MALL_N, ENOMEM, args);
		}
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_bns_free_tab(s_cmd);
			return (exec);
		}
		// ft_bns_ppx_err(CMD_TOO_L, ft_freecpy(temp, exec), E2BIG, args);
		free(exec);
	}
	return (NULL);
}

/**
 * Retrieves the full path of a command.
 *
 * @param cmd The command to find.
 * @param env The environment variables.
 * @return The full path to the command, or the command itself if not found.
 */
char	*ft_bns_getpath(char *cmd, t_arg *args)
{
	char	*exec;
	char	**allpath;
	char	**s_cmd;

	allpath = ft_split(ft_getenv("PATH", args), ':');
	if (!allpath)
		ft_bns_ppx_err(ERR_MALL_M, ERR_MALL_N, ENOMEM, args);
	s_cmd = ft_split(cmd, ' ');
	if (!s_cmd)
	{
		ft_bns_free_tab(allpath);
		ft_bns_ppx_err(ERR_MALL_M, ERR_MALL_N, ENOMEM, args);
	}
	exec = ft_loop(allpath, s_cmd, args);
	if (exec)
		return (exec);
	ft_bns_free_tab(allpath);
	ft_bns_free_tab(s_cmd);
	return (cmd);
}

char	*ft_bns_escape(char *str)
{
	char	*esc;

	if (!str)
		return (NULL);
	esc = malloc(sizeof(char) * (ft_strlen_esc(str) + 1));
	if (!esc)
		return (NULL);
	ft_strcpy_esc(esc, str);
	return (esc);
}

/* int	ft_iscmd_ok(char *cmd, t_arg *arg)
{
	char	*temp;
	int		size_cmd;

	temp = NULL;
	size_cmd = ft_strlen(cmd);
	if (size_cmd > ARG_MAX)
		ft_bns_ppx_err(CMD_TOO_L, ft_freecpy(temp, cmd), E2BIG, arg);
	return (0);
} */
