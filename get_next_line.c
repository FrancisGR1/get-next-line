/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:14:29 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/18 22:11:27 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#define MAX_LINE_LENGTH 1024

char	*get_next_line(int fd)
{
	char	buffer[MAX_LINE_LENGTH];
	char	*p;
	ssize_t		bytes_read;
	ssize_t 	i;
	//ler linha presente em fd com \n incluido (se existir)
	i = 0;
	while ((bytes_read = read(fd, &buffer[i], 1)) > 0 && buffer[i++] != '\n')
			;
	printf("Bytes: %ld||", i);
	//guardar conteudo para memoria
	p = (char *)malloc(i + 1);
	if (!p)
	{
		free(p);
		return (NULL);
	}
	while (i-- >= 0)
		p[i] = buffer[i];
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
	


}*/

