/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:19:46 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/26 17:11:24 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex_bonus.h"

/**
 * Creates and initializes an argument structure.
 *
 * @param av The argument vector.
 * @param env The environment variables.
 * @return A pointer to the initialized argument structure, or NULL on error.
 */
static inline t_arg	*ft_getstruct(char **av, char **env)
{
	t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	if (!arg)
		return (NULL);
	arg->file1 = ft_bns_escape(av[1]);
	if (!arg->file1)
	{
		free(arg);
		return (NULL);
	}
	arg->cmd1 = ft_bns_escape(av[2]);
	if (!arg->cmd1)
		return (ft_bns_free_arg(arg));
	arg->cmd2 = ft_bns_escape(av[3]);
	if (!arg->cmd2)
		return (ft_bns_free_arg(arg));
	arg->file2 = ft_bns_escape(av[4]);
	if (!arg->file2)
		return (ft_bns_free_arg(arg));
	arg->env = env;
	return (arg);
}

/**
 * The main function of the program.
 *
 * @param ac The argument count.
 * @param av The argument vector.
 * @param env The environment variables.
 * @return Always returns 0.
 */
int	main(int ac, char **av, char **env)
{
	t_arg	*args;

	if (ac <= 5 || !av[1][0] || !av[2][0] || !av[3][0] || !av[4][0])
		ft_bns_exit_handler();
	args = ft_getstruct(av, env);
	if (!args)
		ft_bns_ppx_err(ERR_MALL_M, ERR_MALL_N, ENOMEM, NULL);
	ft_bns_pidmaker(args, ac - 3);
	ft_bns_free_arg(args);
	return (0);
}
