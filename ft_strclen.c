/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:08:58 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/24 18:45:07 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strclen(const char *s, char c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i++] != c)
		;
	return (i);
}
/*
   int	main(int c, char **v)
   {
		char *str = "hello\nfr"; 
		int result = ft_strclen(str, '\n');
		printf("%d\n", result);
   }
*/
