/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatenate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:23:11 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/21 19:14:25 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*concatenate(const char *s1, const char *s2)
{
	char	*p;
	int		i;
	int		j;
	

	if (!s1 || !s2)
		return (0);
	//tamanho total;
	//tamanho ate \n
	//p = tamanho ate \n
	//temp = tamanho de s2 - tamanho ate \n
	p = malloc(ft_strlen(s1) + ft_strclen(s2, '\n') + 1);
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
		if (s2[j++] == '\n')
			break ;
	}
	p[i + j] = '\0';
	return (p);
}
