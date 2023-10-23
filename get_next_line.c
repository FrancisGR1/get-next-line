/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:14:29 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/23 21:54:15 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//fazer lista
//norminettar

t_list	*find_fd(t_list *head, int fd)
{
	t_list	*p;

	p = head;
	while (p != NULL)
	{
		if (p -> fd == fd)
			return (p);
		p = p -> next;
	}
	p = malloc(sizeof(t_list));
	p -> fd = fd;
	p -> next = NULL;
	return (p);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}

char	*get_next_line(int fd)
{
	t_list			*file;
	static t_list	*head;
	char			*p;
	ssize_t			bytes_read;

	if (!head)
		head = NULL;
	file = find_fd(head, fd);
	ft_lstadd_front(&head, file);
	if (!file->str)
		file->str = NULL;
	p = NULL;
	while (1)
	{
		if (file->str && check_newline(file->str))
		{
			p = concatenate(p, file->str, '\n');
			clean(&file->str);
			return (p);
		}
		bytes_read = read(fd, file->tmp, BUFFER_SIZE);
		if (file->str && bytes_read <= 0)
		{
			p = file->str;
			file->str = NULL;
			return (p);
		}
		if (!file->str && bytes_read <= 0)
			return (NULL);
		file->tmp[bytes_read] = '\0';
		file->str = concatenate(file->str, file->tmp, '\0');
	}
}
/*
int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	int i = 0;
	char *p;
	char *p2;
	while (i < 18)
	{
		p = get_next_line(fd);
		printf("\t%s\n",p);
		p2 = get_next_line(fd2);
		printf("\t%d:%s\n",i,p2);
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
*/
