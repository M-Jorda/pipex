/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:03:17 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/07 15:44:57 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_posneg(const char *nptr, int i)
{
	if (nptr[i] == 43)
		return (0);
	return (1);
}

/**
 * Converts a string to an integer, handling optional whitespace and signs.
 * 
 * @param nptr The string to convert.
 * @return The converted integer value.
 */
int	ft_atoi(const char *nptr)
{
	int	i;
	int	atoi;
	int	neg;

	i = 0;
	atoi = 0;
	if (nptr[i] == 92)
		return (atoi);
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		neg = ft_posneg(nptr, i);
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		atoi *= 10;
		atoi += nptr[i] - '0';
		i++;
	}
	if (neg == 1)
		atoi *= -1;
	return (atoi);
}
