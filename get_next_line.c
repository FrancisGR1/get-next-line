/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:14:29 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/26 18:37:52 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*find_fd(t_list *head, int fd)
{
	t_list	*p;

	if (!head)
		head = NULL;
	p = NULL;
	p = head;
	while (p != NULL)
	{
		if (p -> fd == fd)
			return (p);
		p = p -> next;
	}
	p = malloc(sizeof(t_list));
	if (!p)
	{
		free(p);
		return (NULL);
	}
	p -> next = NULL;
	p -> str = NULL;
	p -> fd = fd;
	return (p);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}

char	*extract_line(char **src)
{
	char	*p;

	p = NULL;
	p = concatenate(p, *src, '\n');
	clean(&(*src));
	return (p);
}

void	copy(char **dest, char *src)
{
	int		i;

	*dest = malloc(ft_strclen(*dest, '\0') + ft_strclen(&(*src), '\0') + 1);
	if (!*dest)
		return ;
	i = -1;
	while (src[++i])
		(*dest)[i] = src[i];
	printf("copied %d\n", i);
	(*dest)[i] = '\0';
}

char	*get_next_line(int fd)
{
	t_list			*file;
	static t_list	*head;
	ssize_t			bytes_read;

	if (!head)
		head = NULL;
	file = find_fd(head, fd);
	ft_lstadd_front(&head, file);
	if (fd <= 0)
		return (NULL);
	while (1)
	{
		if (file->str && check_newline(file->str))
		{
			//printf("file->str: %s\n", file->str);
			//printf("extract_line\n");
			return (extract_line(&file->str));
		}
		bytes_read = read(fd, file->tmp, BUFFER_SIZE);
		if (file->str && bytes_read <= 0)
		{
			//printf("ft_sstrddup\n");
			return (ft_strddup(&file->str));
		}
		if (!file->str && bytes_read <= 0)
			return (NULL);
		file->tmp[bytes_read] = '\0';
		file-> str = concatenate(file->str, file->tmp, '\0');
		//printf("conc\n");
		printf("%s\n", file->str);
	}
}
int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	int fd3 = open("test3.txt", O_RDONLY);
	int i = 1;
	char *p = NULL;
	char *p2 = NULL;
	char *p3 = NULL;
	while (i < 3)
	{
		printf("\n\tLINE %d\n", i);
		printf("\t----\n");

		p = get_next_line(fd);
		printf("\tfd1: %s\n",p);

		p2 = get_next_line(fd2);
		printf("\tfd2: %s\n",p2);

		p3 = get_next_line(fd3);
		printf("\tfd3: %s\n",p3);
		i++;
	}

	//test empty
	//int empty = open("empty.txt", O_RDONLY);
	//char *p3 = get_next_line(empty);
	//printf("%s", p3);

	//extract_line
	//char *source ="a\nb\nc\n";
	//char *src = strdup(source); 
	//char *line1 = extract_line(&src);
	//printf("Line 1: %s\n", line1);
	//printf("src : %s\n", src);
	close(fd);
	close(fd2);
	close(fd3);
	if (p)
		free(p);
	if (p2)
		free(p2);
	if (p3)
		free(p3);

}
