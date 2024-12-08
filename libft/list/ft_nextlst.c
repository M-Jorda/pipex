/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nextlst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:38:11 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/28 16:42:21 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_nextlst(t_list *head, int i)
{
	t_list	*next;
	int		j;

	if (!head)
		return (NULL);
	next = head;
	j = -1;
	while (++j < i && next)
	{
		if (!next->content || !next->env)
			break ;
		next = next->next;
	}
	if (j < i)
		return (NULL);
	return (next);
}
