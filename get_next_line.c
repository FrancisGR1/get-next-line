/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:14:29 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/19 22:26:46 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*reallocate_str(char *ptr_dest, char *ptr_src, size_t size)
{
	char	*new_p;
	int	ptr_len;

	ptr_len = ft_strlen(ptr);
	new_p = (char *)malloc((ptr_len + size + 1) * sizeof(char));
	ft_strlcpy(new_p, p, ptr_len);
	return (new_p);
}

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	static char	*p;

	if (BUFFER_SIZE < 1)
		return (NULL);
	i = 0;
	while (read(fd, &buffer[i], BUFFER_SIZE) > 0)
	{
		if (buffer[i] == '\n')
			break ;
		i++;
	}
	//printf("Bytes: %ld||", i);
	if (i < 1)
		return (NULL);
	//usar esta func para cada caratere - por otimizar
	p = (char *)reallocate_str(p, tmp, i);
	if (!p)
		return (NULL);
	return (p);
}

   int main(void)
   {
   int fd = open("test.txt", O_RDONLY);
  // int fd2 = open("test2.txt", O_RDONLY);
   printf("fd = %d\n", fd);
   int i = 0;
   char *p;
  // char *p2;
   while (i < 20)
   {
   p = get_next_line(fd);
   printf("%s", p);
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
 
