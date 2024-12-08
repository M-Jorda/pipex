/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:00:10 by jjorda            #+#    #+#             */
/*   Updated: 2024/12/08 13:26:25 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex_bonus.h"

/**
 * Handles the exit when the number of arguments is invalid.
 */
void	ft_bns_exit_handler(t_list *head)
{
	if (head)
		ft_lstfree(&head);
	ft_printerr("Shellchior: Invalid number of arguments");
	exit(1);
}

/**
 * Frees a null-terminated array of strings.
 *
 * @param tab The array of strings to free.
 */
void	ft_bns_free_tab(char **tab)
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
void	ft_bns_ppx_err(char *err, char *name, int ext, t_list *head)
{
	ft_printerr("Shellchior: %s: %s\n", err, name);
	ft_lstfree(&head);
	if (ext)
		exit(ext);
}

void	ft_bns_ppx_stop(int ext, t_list *head)
{
	ft_lstfree(&head);
	exit(ext);
}

/* t_list	*ft_bns_free_arg(t_list *arg)
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
} */
