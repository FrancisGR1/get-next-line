/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:16:25 by frmiguel          #+#    #+#             */
/*   Updated: 2023/11/12 20:36:45 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
int main (void)
{
	//int fd = open("test.txt", O_RDONLY);
	//int fd2 = open("test2.txt", O_RDONLY);
	int fd3 = open("shakespeare.txt", O_RDONLY);
	//int fd4 = open("vars_nls.txt", O_RDONLY);
	//int fd5 = open("read_error.txt", O_RDONLY);
	//int fd6 = open("1char.txt", O_RDONLY);
	//int fd7 = open("41_with_nl", O_RDONLY);

	//multiple files
	
	//int i = 0;
	//while (i < 4)
	//{
	//	char	*str = get_next_line(fd);
	//	printf("%s", str);
	//	char	*str2 = get_next_line(fd2);
	//	printf("%s", str2);
	//	char	*str3 = get_next_line(fd3);
	//	printf("%s", str3);
	//	i++;
	//	free(str);
	//	free(str2);
	//	free(str3);	
	//}

	
	char	*s;
	while (1)
	{
		s = get_next_line(fd3);
	      //usleep(50000);
		printf("%s", s);
		if (!s)
		{
			free(s);
			break ;
		}
		free(s);
	}
	//close(fd);
	//close(fd2);
	close(fd3);
	//close(fd4);
	//close(fd5);
	//close(fd6);
	//close(fd7);
}
*/

char	*get_next_line(int fd)
{
	static char	*txt[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
	{
		if (fd > 0 && txt[fd])
			clearbuff(txt[fd]);
		return (0);
	}
	txt[fd] = get_txt(txt[fd], fd);
	line = extract_line(txt[fd]);
	txt[fd] = clean_line(txt[fd]);
	return (line);
}

char	*extract_line(char *str)
{
	int		i;
	int		j;
	char	*line;

	if (!str)
		return (0);
	j = -1;
	while (str[++j] && str[j] != '\n')
		;
	line = malloc(j + 2);
	if (!line)
		return (0);
	i = -1;
	while (++i < j + 1)
		line[i] = str[i];
	line[i] = '\0';
	return (line);
}

char	*clean_line(char *str)
{
	int		i;
	int		j;
	char	*rest;

	if (!str)
		return (0);
	i = -1;
	while (str[++i] && str[i] != '\n')
		;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	rest = malloc(ft_strlen(str) - i + 1);
	if (!rest)
		return (0);
	j = -1;
	while (str[++i])
		rest[++j] = str[i];
	rest[++j] = '\0';
	free(str);
	return (rest);
}

char	*get_txt(char *txt, int fd)
{
	ssize_t	bytes_read;
	char	*tmp;

	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (0);
	while (!check_newline(txt))
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read < 1)
		{
			free(tmp);
			if (bytes_read == 0 && txt && *txt == '\0')
			{
				free(txt);
				return (0);
			}
			return (txt);
		}
		tmp[bytes_read] = '\0';
		txt = concatenate(txt, tmp);
	}
	free(tmp);
	return (txt);
}

char	*concatenate(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*p;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
		return (0);
	i = -1;
	while (s1[++i])
		p[i] = s1[i];
	j = -1;
	while (s2[++j])
		p[i + j] = s2[j];
	p[i + j] = '\0';
	free(s1);
	return (p);
}
