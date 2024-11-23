/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 08:32:52 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/10 13:57:06 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	how_many(char const *s, char c)
{
	int	i;
	int	counter;
	int	b_check;

	counter = 0;
	i = 0;
	b_check = 0;
	while (s[i])
	{
		if (s[i] != c && b_check == 0)
		{
			b_check = 1;
			counter++;
		}
		else if (s[i] == c)
			b_check = 0;
		i++;
	}
	return (counter);
}

static void	ft_leak(char **str, size_t i)
{
	if (!str)
		return ;
	while (i > 0)
		free(str[--i]);
	free(str);
}

static char	**ft_arrmaker(char const *s, char c)
{
	char	**str;
	int		size_arr;

	if (!s)
		return (NULL);
	size_arr = how_many(s, c);
	str = (char **) malloc((size_arr + 1) * sizeof(char *));
	if (!str)
		return ((char **) ft_mallocfailed("ft_split"));
	str[size_arr] = NULL;
	return (str);
}

static int	ft_splitereate(char const *s, int *i, int len, char c)
{
	if (len == 0)
	{
		while (s[*i] && s[*i] != c)
		{
			len++;
			*i += 1;
		}
		return (len);
	}
	while (s[*i] && s[*i] == c)
		*i += 1;
	return (*i);
}

/**
 * Splits a string into an array of substrings based on the specified delimiter
 * character.
 * 
 * @param s The string to split.
 * @param c The delimiter character.
 * @return A pointer to an array of strings (substrings), or NULL if malloc
 * fails or invalid parameters are provided.
 * 
 * Note: Memory for the array and substrings is allocated using malloc().
 *       If malloc fails, the function returns NULL and cleans up the previously
 * allocated memory.
 */
char	**ft_split(char const *s, char c)
{
	char	**str;
	int		start;
	int		i;
	int		size;

	i = 0;
	size = 0;
	str = ft_arrmaker(s, c);
	if (!str || !s)
		return (NULL);
	while (s[i])
	{
		ft_splitereate(s, &i, 1, c);
		if (s[i] == '\0')
			break ;
		start = i;
		str[size] = ft_substr(s, start, ft_splitereate(s, &i, 0, c));
		if (!str[size])
			return (ft_leak(str, size), NULL);
		size++;
	}
	return (str);
}
