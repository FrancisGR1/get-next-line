/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:08:58 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/20 11:10:54 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//retorna ate que index ir
int	ft_strclen(char *s, char c)
{
	int	i;

	i = 0;
	while (*s && *s != c)
	{
		s++;
		i++;
	}
	return (i);
}
/*
   int	main(int c, char **v)
   {
		char *str = "olaola\n"; 
		int result = ft_strclen(str, '\n');
		printf("%d\n", result);
   }
*/
