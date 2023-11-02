/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2023/10/18 18:12:23 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/26 10:54:48 by frmiguel         ###   ########.fr       */
=======
/*   Created: 2023/10/31 15:20:42 by frmiguel          #+#    #+#             */
/*   Updated: 2023/11/02 18:34:11 by frmiguel         ###   ########.fr       */
>>>>>>> gnl3/main
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

<<<<<<< HEAD
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
=======
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <string.h>

# define MAX_FD 1024

char	*get_next_line(int fd);
char	*extract_line(char *str);
char	*clean_line(char *str);
char	*get_txt(char *txt, int fd);
char	*concatenate(char *s1, char *s2);
int	check_newline(const char *str);
size_t	ft_strlen(const char *str);
>>>>>>> gnl3/main

#endif
