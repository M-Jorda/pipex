/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_esc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:24:34 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/22 11:07:04 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
* The strlen() function calculates the length of the string pointed to by s,
* excluding the terminating null byte ('\0').
*/
size_t	ft_strlen_esc(const char *s)
{
	size_t	length;
	size_t	i;

	i = 0;
	length = 0;
	while (s[i])
	{
		if (!ft_isesc(s[i++]))
			length++;
	}
	return (length);
}

/* int	main(int argc, char **argv)
{
	ft_printerr("size: %d", ft_strlen_esc(argv[1]));
	return (0);
} */