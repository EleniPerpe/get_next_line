/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgmelin <tgmelin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:10:56 by tgmelin           #+#    #+#             */
/*   Updated: 2024/03/16 16:38:06 by tgmelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif //BUFFER_SIZE

typedef char	t_bool;
# define FALSE 0
# define TRUE 1

# define MAX_FILE_DESCRIPTORS 1024

typedef struct s_gnl_buffer
{
	char	buffer[MAX_FILE_DESCRIPTORS][BUFFER_SIZE];
	ssize_t	len[MAX_FILE_DESCRIPTORS];
}	t_gnl_buffer;

typedef struct s_gnl_vars
{
	char	*out;
	ssize_t	out_size;
	ssize_t	endl;
	ssize_t	bytes_read;
	ssize_t	bytes_newly_read;
	char	init;
}	t_gnl_vars;

void	ft_memclr(char *_mem, size_t _size);
void	ft_memcpy(char *_dst, char *_src, size_t _size);
char	*get_next_line(int fd);

#endif //GET_NEXT_LINE_BONUS_H