/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:00:00 by jjorda            #+#    #+#             */
/*   Updated: 2024/12/08 15:26:16 by jjorda           ###   ########.fr       */
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
static inline char	*ft_getenv(char *name, t_list *args)
{
	char	*sub;
	char	**env;
	int		i;
	int		j;

	env = ft_lstlast(args)->env;
	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (!sub)
			ft_bns_ppx_err(ERR_MALL_M, ERR_MALL_N, ENOMEM, args);
		if (ft_strcmp(sub, name) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
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
static inline char	*ft_loop(char **allpath, char **s_cmd, t_list *args)
{
	char	*path_part;
	char	*exec;
	int		i;

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
char	*ft_bns_getpath(char *cmd, t_list *args)
{
	char	*exec;
	char	**allpath;
	char	**s_cmd;

	allpath = ft_split(ft_getenv("PATH", args), ':');
	if (!allpath)
		ft_bns_ppx_err(ERR_MALL_M, ERR_MALL_N, ENOMEM, args);
	s_cmd = ft_split_arg(cmd);
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
	ft_printerr("ACCESS KO\n");
	return (NULL);
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

char	*ft_delimiter(char *str)
{
	char	*new;
	size_t	i;
	size_t	size;

	if (!str)
		return (NULL);
	i = 0;
	size = ft_strlen(str);
	new = (char *) malloc((size + 2) * sizeof(char));
	if (!new)
		return (NULL);
	while (i++ < size)
		new[i] = str[i];
	new[i] = '\n';
	new[++i] = '\0';
	free(str);
	return (new);
}

TODO:compare the delimiters

/* int	ft_iscmd_ok(char *cmd, t_list *arg)
{
	char	*temp;
	int		size_cmd;

	temp = NULL;
	size_cmd = ft_strlen(cmd);
	if (size_cmd > ARG_MAX)
		ft_bns_ppx_err(CMD_TOO_L, ft_freecpy(temp, cmd), E2BIG, arg);
	return (0);
} */
