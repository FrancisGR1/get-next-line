/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:19:10 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/26 10:19:04 by frmiguel         ###   ########.fr       */
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

int	check_newline(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

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

void	clean(char **src)
{
	int		i;
	int		j;
	char	*p;

	if (!src || !*src)
		return ;
	i = 0;
	j = ft_strclen(*src, '\n');
	p = (char *)malloc(ft_strclen(*src, '\0') - j);
	if (!p)
		return ;
	while ((*src)[i + j])
	{
		p[i] = (*src)[i + j];
		i++;
	}
	p[i] = '\0';
	free(*src);
	*src = p;
}

char	*ft_strddup(char **src)
{
	int		len;
	int		i;
	char	*p;

	if (!src ||!*src)
		return (0);
	len = ft_strclen(*src, '\0');
	if (len == 1)
		return (0);
	p = malloc(len);
	if (!p)
		return (0);
	i = -1;
	while ((*src)[++i])
		p[i] = (*src)[i];
	p[len] = '\0';
	free(*src);
	*src = 0;
	if (*p == '\0')
		return (0);
	return (p);
}
