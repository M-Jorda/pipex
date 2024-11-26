/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_freemall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:26:33 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/11 21:34:13 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../../header/pipex.h"

void	ft_lst_freemall(t_mall *head, void *mall)
{
	t_mall	*next;

	if (!head && !mall)
		return (NULL);
	while (head)
	{
		if (head->mall == mall)
		{
			free(mall);
		}
		next = head->next;
	}
}
