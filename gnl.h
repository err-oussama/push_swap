/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oerrami <oerrami@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 05:14:08 by oerrami           #+#    #+#             */
/*   Updated: 2025/12/19 05:14:10 by oerrami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>

char	*check_line_in_save_area(char **save_area);

char	*join(char *s1, char *s2, size_t ss1, size_t ss2);

char	*get_line_in_save_area(char **save_area);

int		reach_eof_nl(int fd, char **save_area, char *buff);

char	*extract_line(char **save_area);

char	*get_next_line(int fd);

#endif
