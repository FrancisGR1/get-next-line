/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:14:29 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/20 09:49:46 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

typedef struct s_buffer
{
	int	fd;
	char	str[BUFFER_SIZE];
	char	*temp;
} t_buffer;
/*
char	*reallocate_str(char *ptr_dest, char *ptr_src, size_t size)
{
	int	ptr_len;

	ptr_len = ft_strlen(ptr_dest);
	ptr_dest = (char *)malloc((ptr_len + size + 1) * sizeof(char));
	ft_strlcpy(ptr_dest, p, ptr_src, size);
	return (ptr_dest);
}
*/

//transformar static em estrutura com:
	//fd
	//str total
	//temp
//dentro do str total, passar tudo ate \n
	//O que e que preciso de fazer passo por passo?
		//medir tudo ate \n - ft_strclen
		//criar malloc com dado tamanho
		//passar tudo para ai
		//passar o resto para temp
		//libertar total_buffer.str
//se restar, passar para temp
char	*get_next_line(int fd)
{
	static t_buffer total_buffer;

	total_buffer.fd = fd;
	read(fd, total_buffer.str, BUFFER_SIZE);
	char *p = (char *)malloc(ft_strclen(total_buffer.str, '\n') * sizeof(char));
	//char *p = total_buffer.str;
	return (p);
}

   int main(void)
   {
   int fd = open("test.txt", O_RDONLY);
  // int fd2 = open("test2.txt", O_RDONLY);
   printf("fd = %d\n", fd);
   char *p;
  // char *p2;
   p = get_next_line(fd);
   printf("%s", p);
  //p2 = get_next_line(fd2);
   //printf("%s", p2);
   //p = get_next_line(fd);
   //printf("%s", p);

//test empty
//int empty = open("empty.txt", O_RDONLY);
//char *p3 = get_next_line(empty);
//printf("%s", p3);
}
 
