/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_a_to_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oerrami <oerrami@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 05:14:28 by oerrami           #+#    #+#             */
/*   Updated: 2025/12/19 05:14:29 by oerrami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

long	a_to_l(const char *str)
{
	long	n;
	long	s;

	n = 0;
	s = 0;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			s = 1;
	if (!*str)
		return (INVALID_INPUT);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (INVALID_INPUT);
		n = (n * 10) + (*str - '0');
		str++;
	}
	if (s)
		n = -n;
	if (n > MAX || n < MIN)
		return (INVALID_INPUT);
	return (n);
}
