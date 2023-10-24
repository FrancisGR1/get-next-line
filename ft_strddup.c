/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strddup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:36:23 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/24 19:01:29 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strddup(char **src)
{
	int	len;
	int	i;
	char		*p;

	if (!src || !*src)
		return (NULL);
	len = ft_strclen(*src, '\0');
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	i = -1;
	while ((*src)[++i])
		p[i] = (*src)[i];
	p[len] = '\0';
	free(*src);
	*src = NULL;
	return (p);	
}
