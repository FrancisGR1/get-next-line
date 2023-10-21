/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:14:29 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/21 19:24:02 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
/*
typedef struct s_buffer
{
	int	fd;
	char	*str;
	char	*temp;
} t_buffer;
*/
int result = 0;
int i = 0;
char	*get_next_line(int fd)
{
	char		*p;
	char		buffer[BUFFER_SIZE];

	p = malloc(BUFFER_SIZE + 1);
	if (!p)
		return (0);
	while ((read(fd, buffer, BUFFER_SIZE) > 0))
	{
		p = concatenate(p, buffer);
		//printf("%s\n", buffer);
		if (locate_newline(buffer, BUFFER_SIZE))
			break ; 
	}
	return (p);
}

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	// int fd2 = open("test2.txt", O_RDONLY);
	printf("fd = %d\n", fd);
	char *p;
	// char *p2;
	p = NULL;
	while (i < 2)
	{
		p = get_next_line(fd);
		printf("%d:%s", i, p);
		i++;
	}
	//p2 = get_next_line(fd2);
	//printf("%s", p2);
	//p = get_next_line(fd);
	//printf("%s", p);

	//test empty
	//int empty = open("empty.txt", O_RDONLY);
	//char *p3 = get_next_line(empty);
	//printf("%s", p3);
}

