/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_mall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:50:21 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/11 21:49:41 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Adds a new element at the end of the linked list.
 * 
 * @param head The first element of the linked list.
 * @param mall Data to be stored in the new element.
 * @param name A string associated with the new element.
 * @return "head" of the linked list is th elist was empty.
 * 
 * Note: Memory for the new node is allocated using malloc(). 
 *       If malloc fails, the function returns NULL.
 */
t_mall	*ft_lstnew_back_mall(t_mall *head, void *mall, char *name)
{
	t_mall	*new;
	t_mall	*temp;

	if (!mall)
		return (NULL);
	new = (t_mall *) malloc(sizeof(t_mall));
	if (!new)
		return (NULL);
	new->mall = mall;
	new->name = name;
	new->next = NULL;
	if (!head)
		return (new);
	temp = head;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return (head);
}
