/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:44:17 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/22 20:37:30 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

/**
 * Handles the exit when the number of arguments is invalid.
 */
void	ft_exit_handler(void)
{
	ft_printerr("Shellchior: Invalid number of arguments");
	exit(1);
}

/**
 * Frees a null-terminated array of strings.
 *
 * @param tab The array of strings to free.
 */
void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

/**
 * Prints an error message based on the provided error code and function name.
 *
 * @param name The name of the function where the error occurred.
 * @param ext The error code that determines if the program should exit.
 */
void	ft_ppx_err(char *err, char *name, int ext, t_arg *arg)
{
	(void) name;
	ft_printerr("Shellchior: %s: %s\n", err, name);
	if (arg)
		ft_free_arg(arg);
	if (ext)
		exit(ext);
}

t_arg	*ft_free_arg(t_arg *arg)
{
	if (arg->cmd1)
		free(arg->cmd1);
	if (arg->cmd2)
		free(arg->cmd2);
	if (arg->file1)
		free(arg->file1);
	if (arg->file2)
		free(arg->file2);
	if (arg)
		free(arg);
	return (NULL);
}

int	ft_waitpid(pid_t pid, int status)
{
	waitpid(pid, &status, 0);
	if (!WIFEXITED(status) && !WEXITSTATUS(status))
		return (status);
	return (status);
}
