/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:14:29 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/19 18:26:20 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*p;
	ssize_t	i;

	if (BUFFER_SIZE < 1)
		return (NULL);
	i = 0;
	while (i < BUFFER_SIZE && read(fd, &buffer[i], 1) > 0)
	{
		if (buffer[i] == '\n')
			break ;
		i++;
	}
	if (i < 1)
		return (NULL);
	p = (char *)malloc(i + 1);
	if (!p)
		return (NULL);
	p[i + 1] = '\0';
	while (i >= 0)
	{
		p[i] = buffer[i];
		i--;
	}
	return (p);
}
/*
int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	printf("fd = %d\n", fd);
	int i = 0;
	char *p;
	char *p2;
	while (i < 2)
	{
		p = get_next_line(fd);
		printf("%s", p);
		i++;	
	}
	p2 = get_next_line(fd2);
	printf("%s", p2);
	p = get_next_line(fd);
	printf("%s", p);

	//test empty
	int empty = open("empty.txt", O_RDONLY);
	char *p3 = get_next_line(empty);
	printf("%s", p3);

}*/
