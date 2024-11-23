/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:17:40 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/11 21:05:17 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../../header/pipex.h"

/**
 * Frees all elements of the linked list and their associated memory.
 * 
 * @param head The first element of the linked list.
 * This function terminates the program after freeing the memory.
 */
void	ft_lstfree(t_mall *head)
{
	t_mall	*next;

	if (!head)
		return ;
	while (head)
	{
		next = head->next;
		free(head->mall);
		free(head);
		head = next;
	}
	exit(1);
}
