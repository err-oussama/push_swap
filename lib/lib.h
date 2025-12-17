/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oerrami <oerrami@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 06:22:43 by oerrami           #+#    #+#             */
/*   Updated: 2025/12/05 06:22:49 by oerrami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include "../push_swap.h"
# include <stdlib.h>

int		clear_array(char **array, size_t i);
char	*sub_str(char const *s, unsigned int start, size_t len);
size_t	str_lcpy(char *dst, const char *src, size_t size);
void	*c_alloc(size_t nmemb, size_t size);
char	**split(char const *s, size_t *n);
size_t	str_len(const char *s);
long	a_to_l(const char *str);
int		str_cmp(const char *s1, const char *s2);
#endif
