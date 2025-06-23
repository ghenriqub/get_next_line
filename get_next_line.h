/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:11:06 by ghenriqu          #+#    #+#             */
/*   Updated: 2025/05/09 17:10:35 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// macros:
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// includes:
//# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

// prototypes:
char	*get_next_line(int fd);
char	*ft_join_free(char *line, char *buffer);
void	ft_memmove_nl(char *buffer);
char	*ft_handle_nl(char *buffer, char *new_line);
char	*ft_read_loop(char *buffer, char *new_line, int fd);
ssize_t	ft_locate_nl(char *str);
size_t	ft_strlen(char *str);

#endif
