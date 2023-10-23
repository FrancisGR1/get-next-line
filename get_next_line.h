/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:12:23 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/23 21:46:04 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_list
{
	int	fd;
	char	*str;
	char	tmp[BUFFER_SIZE];
	struct s_list			*next;
} t_list;

char	*get_next_line(int fd);
int	ft_strlen(const char *s);
int	ft_strclen(const char *s, char c);
char	*concatenate(char *s1, const char *s2, char s2_c);
void	clean(char **src);
int	check_newline(const char *s);
t_list	*find_fd(t_list *head, int fd);

#endif
