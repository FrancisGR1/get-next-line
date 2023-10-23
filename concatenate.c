/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatenate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:23:11 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/23 16:31:29 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*concatenate(char *s1, const char *s2, char s2_c)
{
	char	*p;
	int		i;
	int		j;

	if (!s2)
		return (0);
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	p = malloc(ft_strclen(s1, '\0') + ft_strclen(s2, s2_c) + 1);
	if (!p)
		return (0);
	i = -1;
	while (s1[++i])
		p[i] = s1[i];
	j = -1;
	while (s2[++j] && s2[j] != s2_c)
		p[i + j] = s2[j];
	p[i + j] = '\0';
	return (p);
}
