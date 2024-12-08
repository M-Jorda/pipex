/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:19:46 by jjorda            #+#    #+#             */
/*   Updated: 2024/12/08 15:14:51 by jjorda           ###   ########.fr       */
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
static inline t_list	*ft_getstruct(char **av, char **envp, int args)
{
	t_list	*head;
	t_list	*env;
	int		i;

	i = 1;
	head = ft_lstnew(av[i]);
	while (++i < args)
		ft_lstadd_back(&head, ft_lstnew((void *) av[i]));
	env = (t_list *) malloc(sizeof(t_list));
	env->env = envp;
	env->next = NULL;
	ft_lstadd_back(&head, env);
	return (head);
}

static inline void	here_doc_in(t_list *head, int *p_fd)
{
	char	*str;
	char	*delimiter;

	close(p_fd[0]);
	delimiter = ft_delimiter(head->next->content);
	while (1)
	{
		str = get_next_line(STDIN_FILENO);
		ft_printerr("%s\n", delimiter);
		ft_printerr("%s\n", str);
		if (ft_strncmp(str, delimiter, ft_strlen(str)) == 0)
		{
			free(str);
			ft_lstfree(&head);
			exit(0);
		}
		ft_putstr_fd(str, p_fd[1]);
		free(str);
	}
}

static inline void	here_doc(t_list *head)
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		ft_bns_ppx_err(ERR_MALL_M, ERR_MALL_N, ENOMEM, head);
	pid = fork();
	if (pid == -1)
		ft_bns_ppx_err(ERR_MALL_M, FORK_FAIL, ENOMEM, head);
	if (pid == 0)
	{
		here_doc_in(head, p_fd);
		return ;
	}
	close(p_fd[1]);
	if (dup2(p_fd[0], STDIN_FILENO) != STDIN_FILENO)
		ft_bns_ppx_err(BAD_FD, STD_IN, 1, head);
	wait(0);
}

/**
 * The main function of the program.
 *
 * @param ac The argument count.
 * @param av The argument vector.
 * @param env The environment variables.
 * @return Returns 0 if good.
 */
int	main(int ac, char **av, char **env)
{
	t_list	*head;
	int		fd_in;
	int		i;
	int		status;

	if (ac < 5 || !av[1][0] || !av[2][0] || !av[3][0] || !av[4][0])
		ft_bns_exit_handler(NULL);
	head = ft_getstruct(av, env, ac);
	if (!head)
		ft_bns_ppx_err(ERR_MALL_M, ERR_MALL_N, ENOMEM, NULL);
	i = 0;
	if (ft_strncmp(head->content, "here_doc", ft_strlen(head->content)) == 0)
	{
		if (ac < 6)
			ft_bns_exit_handler(head);
		fd_in = ft_open_file(head->content, 2);
		if (fd_in == -1)
			ft_bns_ppx_err(BAD_FD, "fd_in", 1, head);
		here_doc(head);
		unlink("here_doc");
		i = 1;
	}
	status = ft_bns_pidmaker(head, ac - 3, i);
	ft_lstfree(&head);
	return (status);
}
