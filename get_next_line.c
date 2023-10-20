/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:14:29 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/20 17:23:55 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

typedef struct s_buffer
{
	int	fd;
	char	*str;
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
/*
int     ft_strclen(char *s, char c)
{
        int     i;

        i = 0;
        while (*s && *s != c)
        {
                s++;
                i++;
        }
        return (i);
}
*/

char	*get_next_line(int fd)
{
	static t_buffer total_buffer;
	char		*p;
	char		buffer[BUFFER_SIZE];
	total_buffer.fd = fd;
	read(fd, buffer, BUFFER_SIZE);
	

	//copiar ate \n para total_buffer.str
	int i = 0;
	int j = strlen(char)
	while(buffer[i])
		total_buffer.str[i] = buffer[i++];	
		(char *)malloc(ft_strclen(total_buffer.str, '\n') * sizeof(char));
	memcpy(p, total_buffer.str, ft_strclen(total_buffer.str, '\n'));
	//problemas com o codigo acima:
	//	Exemplo:
	//		Ficheiro:
	//			Exemplo abc_abc_abc\n
	//			buffer size =4
	//			1a copia = abc_    p = abc_0
	//			2a copia = abc_    p= abc_abc_0
	//			3a copia = abc\n   p= abc_abc_abc\n0	
	//	//Passos
	//		1. Alocar mem para p + str recebida
	//		2. Copiar str para p
	//		3. Se chegarmos a \n ou ao fim da linha
	//			Retornar p
	//		4. Caso contrario
	//			Voltar para 1.
	//
	//		-----
	//		Vou fazer o codigo depois considero o que esta abaixo
	//		Isto nao esta a ter as seguintes consideracoes:
	//		- se copiar depois de \n
	//		- por ex. ab\nc
	//		- 
	//
	//
	//	Tenho de copiar o ficheiro ate chegar a \n
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
 
