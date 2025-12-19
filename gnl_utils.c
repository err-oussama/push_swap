/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oerrami <oerrami@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 05:14:17 by oerrami           #+#    #+#             */
/*   Updated: 2025/12/19 05:14:19 by oerrami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*check_line_in_save_area(char **save_area)
{
	char	*line;
	char	*tmp;
	size_t	i;
	size_t	j;

	tmp = *save_area;
	if (!tmp)
		return (NULL);
	i = 0;
	while (tmp[i] && '\n' != tmp[i])
		i++;
	if ('\n' == tmp[i])
		i++;
	else
		return (NULL);
	line = join(tmp, NULL, i, 0);
	j = 0;
	while (tmp[i + j])
		j++;
	*save_area = join(tmp + i, NULL, j, 0);
	free(tmp);
	return (line);
}

char	*extract_line(char **save_area)
{
	char	*line;
	char	*tmp;
	size_t	i;
	size_t	j;

	tmp = *save_area;
	if (!tmp)
		return (NULL);
	i = 0;
	while (tmp[i] && '\n' != tmp[i])
		i++;
	if ('\n' == tmp[i])
		i++;
	line = join(tmp, NULL, i, 0);
	j = 0;
	while (tmp[i + j])
		j++;
	*save_area = join(tmp + i, NULL, j, 0);
	free(tmp);
	return (line);
}

char	*join(char *s1, char *s2, size_t ss1, size_t ss2)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	if (!ss1 && !ss2)
		return (NULL);
	tmp = malloc(ss1 + ss2 + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	j = 0;
	while (j < ss1)
		tmp[i++] = s1[j++];
	j = 0;
	while (j < ss2)
		tmp[i++] = s2[j++];
	tmp[ss1 + ss2] = 0;
	return (tmp);
}

int	reach_eof_nl(int fd, char **save_area, char *buff)
{
	ssize_t	br;
	ssize_t	i;
	char	*tmp;
	int		flag;

	i = -1;
	flag = 1;
	tmp = *save_area;
	br = read(fd, buff, BUFFER_SIZE);
	if (br <= 0)
		return (0);
	while (++i < br && flag)
		if ('\n' == buff[i])
			flag = 0;
	if (!tmp)
	{
		*save_area = join(buff, NULL, br, 0);
		return (flag);
	}
	i = 0;
	while (tmp[i])
		i++;
	*save_area = join(tmp, buff, (size_t)i, (size_t)br);
	free(tmp);
	return (flag);
}
