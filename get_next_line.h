/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:19:04 by ghenriqu          #+#    #+#             */
/*   Updated: 2025/05/03 18:13:11 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*str_buffer;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	ft_create_list(t_list **list, int fd);
void	ft_append_list(t_list **list, char *buffer);
char	*ft_get_line(t_list *list);
int		ft_new_line(t_list *list);
t_list	*ft_last_node(t_list *list);
void	ft_polish_list(t_list **list);
void	ft_copy_str(t_list *list, char *str);
int		ft_len_newline(t_list *list);
void	ft_dealloc_list(t_list **list, t_list *clean_node, char *buffer);

#endif
