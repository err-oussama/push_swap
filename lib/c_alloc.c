/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_alloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oerrami <oerrami@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 21:03:28 by oerrami           #+#    #+#             */
/*   Updated: 2025/12/05 21:03:29 by oerrami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	*c_alloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	total;

	if (!nmemb || !size)
		return (NULL);
	if (nmemb > (((size_t)-1) / size))
		return (NULL);
	total = nmemb * size;
	mem = malloc(total);
	if (!mem)
		return (NULL);
	while (total--)
		((char *)mem)[total] = 0;
	return (mem);
}
