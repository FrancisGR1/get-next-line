/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:06:31 by frmiguel          #+#    #+#             */
/*   Updated: 2023/11/03 14:24:06 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_newline(const char *str)
{
	if (!str)
		return (0);
	while (*str && *str != '\n')
		++str;
	if (*str == '\n')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	const char	*start;

	if (!str)
		return (0);
	start = str;
	while (*str)
		++str;
	return (str - start);
}
