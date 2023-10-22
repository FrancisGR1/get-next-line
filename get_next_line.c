/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:14:29 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/22 23:42:33 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

typedef struct s_buffer
{
	int	fd;
	char	*str;
} t_buffer;

int result = 0;
int i = 0;
char	*get_next_line(int fd)
{
	static t_buffer	file;
	char	tmp[BUFFER_SIZE];
	//static int call = 0;
	char	*p;

	if (!file.str)
		file.str = NULL;
	p = NULL;
	while (read(fd, tmp, BUFFER_SIZE) > 0)
	{
		file.str = concatenate(file.str, tmp, '\0');
		printf("%s\n",file.str);
		//call++;	
		if (check_newline(file.str))
		{
			p = concatenate(p, file.str, '\n');
			clean(&file.str);
			return (p);
		}
	}
	while (file.str)
	{
		if (check_newline(file.str))
		{
			p = concatenate(p, file.str, '\n');	
			clean(&file.str);
			return (p);
		}
	}
	p = file.str;
	free(file.str);
	return (p);
}

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	// int fd2 = open("test2.txt", O_RDONLY);
	printf("fd = %d\n", fd);
	char *p;
	// char *p2;
	while (i < 18)
	{
		p = get_next_line(fd);
		printf("\t%d:%s\n",i,p);
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

