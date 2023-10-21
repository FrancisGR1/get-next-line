/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_newline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:15:52 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/21 23:05:25 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_newline(const char *s, int size)
{
	int	i;

	i = 0;
	while (s[i] && i <= size)
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
/*
int main (void)
{
	char *str = "h\n";
	int result = locate_newline(str, 1);
	printf("%d\n", result);
	return 0;
}
*/
