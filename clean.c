/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:31:59 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/22 16:03:17 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
char	*clean(char *tmp)
{
	char	*p;
	int		i;
	int		j;

	if (!tmp)
		return (NULL);
	p = (char *)malloc((ft_strclen(tmp, '\0') - ft_strclen(tmp, '\n')));
	if (!p)
		return (NULL);
	i = ft_strclen(tmp, '\n');
	j = 0;
	while (tmp[i + j])
	{
		p[j] = tmp[i + j];
		j++;
	}
	p[j] = '\0';
	return (p);
	
}
*/
void clean(char **src) {
    if (!src || !*src) {
        return;
    }

    int i = 0;
    int j = ft_strclen(*src, '\n');
    
    // Allocate new memory for p
    char *p = (char *)malloc(ft_strclen(*src, '\0') - j);

    if (!p) {
        return;
    }

    while ((*src)[i + j]) {
        p[i] = (*src)[i + j];
        i++;
    }

    p[i] = '\0';
    
    // Free the old memory pointed to by *src
    free(*src);

    // Update *src to point to the newly allocated memory
    *src = p;
}

/*
int main (void)
{	
	char *s = "a\nb\nc\nd\n";
	char *p = clean(s);
	printf("%s\n", p);
}
*/
