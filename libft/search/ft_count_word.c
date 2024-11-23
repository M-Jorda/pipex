/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:33:18 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/11 15:58:20 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Counts the number of words in a string separated by the delimiter character c.
 * 
 * @param s The string to count words in.
 * @param c The delimiter character.
 * @return The number of words in the string.
 */
int	ft_count_word(char const *s, char c)
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
