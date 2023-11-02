/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:20:42 by frmiguel          #+#    #+#             */
/*   Updated: 2023/11/02 18:34:11 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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

#endif
