/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oerrami <oerrami@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 21:03:58 by oerrami           #+#    #+#             */
/*   Updated: 2025/12/05 21:03:59 by oerrami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*sub_str(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*new_str;

	if (!s)
		return (NULL);
	s_len = str_len(s);
	if (start > s_len)
		return (NULL);
	if (start + len > s_len)
		len = s_len - start;
	new_str = (char *)malloc(len + 1);
	if (!new_str)
		return (NULL);
	str_lcpy(new_str, s + start, len + 1);
	return (new_str);
}
