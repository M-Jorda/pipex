/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_esc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:19:32 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/22 12:12:42 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strcpy_esc(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[i])
	{
		if (src[i] == '\n')
		{
			dest[j++] = '\\';
			dest[j++] = 'n';
			i++;
		}
		else if (ft_isesc(src[i]))
		{
			if (src[i + 1])
				i++;
			else
				break ;
		}
		dest[j++] = src[i++];
	}
	dest[j] = '\0';
	return (dest);
}

/* int	main(int argc, char **argv)
{
	char	*str;

	(void) argc;
	str = malloc(3);
	str = ft_strcpy_esc(str, argv[1]);
	printf("%s", str);
	free(str);
	return (0);
} */