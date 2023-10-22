/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatenate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:23:11 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/22 18:17:48 by frmiguel         ###   ########.fr       */
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
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		p[i + j] = s2[j];
		if (s2[j++] == s2_c)
			break ;
	}
	p[i + j] = '\0';
	return (p);
}
