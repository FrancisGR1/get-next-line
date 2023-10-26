/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:12:23 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/26 10:54:25 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_list
{
	int				fd;
	char			*str;
	char			tmp[BUFFER_SIZE];
	struct s_list	*next;
}	t_list;

int		ft_strclen(const char *s, char c);
int		check_newline(const char *s);
char	*get_next_line(int fd);
char	*concatenate(char *s1, const char *s2, char s2_c);
char	*ft_strddup(char **src);
void	clean(char **src);
t_list	*find_fd(t_list *head, int fd);

#endif
