/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:42:34 by eperperi          #+#    #+#             */
/*   Updated: 2024/03/28 12:45:38 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 25
# endif

char	*get_next_line(int fd)
{
	int read_num;
	char	*buffer;

	buffer = (char *)malloc ((BUFFER_SIZE + 1) * sizeof(char *));
	if (buffer == NULL)
		return (NULL);
	read_num = read(fd, buffer, BUFFER_SIZE);
	if (read_num == 0)
		return (free (buffer), NULL);
		return (buffer);
}
int main (void)
{
	int 	fd;
	char	*new_line;
	int		counter;
	int		i;

	counter = 0;
	fd = open("test.txt", O_RDONLY);
	i = 0;
	while (1)
	{
		new_line = get_next_line(fd);
		
		counter++;
		printf("%d : %s\n", counter, new_line);
		if (new_line == NULL)
			break;
		new_line = NULL;
	}
	close(fd);
	return (0);
}
