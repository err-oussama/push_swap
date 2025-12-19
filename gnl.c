/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oerrami <oerrami@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 05:13:53 by oerrami           #+#    #+#             */
/*   Updated: 2025/12/19 05:13:56 by oerrami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*get_next_line(int fd)
{
	static char	*save_area;
	char		*line;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = check_line_in_save_area(&save_area);
	if (line)
		return (line);
	buff = malloc(BUFFER_SIZE);
	if (!buff)
		return (NULL);
	while (reach_eof_nl(fd, &save_area, buff))
		;
	free(buff);
	line = extract_line(&save_area);
	return (line);
}
