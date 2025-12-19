/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oerrami <oerrami@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 05:14:56 by oerrami           #+#    #+#             */
/*   Updated: 2025/12/19 05:14:58 by oerrami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static size_t	get_size(char const *s)
{
	size_t	counter;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] && s[i] == ' ')
			i++;
		if (!s[i])
			return (counter);
		while (s[i] && s[i] != ' ')
			i++;
		counter++;
	}
	return (counter);
}

int	clear_array(char **array, size_t i)
{
	while (i--)
		free((array[i]));
	free(array);
	return (0);
}

static int	handle_word(char **array, unsigned int j, char *word)
{
	if (word)
	{
		array[j] = word;
		return (1);
	}
	return (clear_array(array, j));
}

char	**split(char const *s, size_t *n)
{
	unsigned int	i;
	unsigned int	j;
	char			**array;

	*n = get_size(s);
	i = 0;
	j = 0;
	array = c_alloc(*n, sizeof(char *));
	if (!array)
		return (NULL);
	while (*s)
	{
		i = 0;
		while (*s && *s == ' ')
			s++;
		if (!*s)
			break ;
		while (s[i] && s[i] != ' ')
			i++;
		if (!handle_word(array, j++, sub_str(s, 0, i)))
			return (NULL);
		s += i;
	}
	return (array);
}
