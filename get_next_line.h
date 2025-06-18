/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:11:06 by ghenriqu          #+#    #+#             */
/*   Updated: 2025/06/18 17:32:49 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// macros:
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
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
ssize_t	ft_locate_nl(char *str);

#endif
