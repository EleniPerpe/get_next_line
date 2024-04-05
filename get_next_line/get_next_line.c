/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:42:34 by eperperi          #+#    #+#             */
/*   Updated: 2024/04/05 14:39:39 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 13
#endif

char	*get_next_line(int fd)
{
	int				read_chars;
	char			*buffer;
	char			*temp_buffer;
	static char		*substring;
	int				i;
	int				j;

	temp_buffer = NULL;
	buffer = (char *)malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	while ((read_chars = read(fd, buffer, BUFFER_SIZE)) >= 0)
	{
		if (substring != NULL)
			buffer = ft_strjoin(substring, buffer);
		// buffer[read_chars + 1] = '\0';
		// if (read_chars == 0)
		// 	return (free (buffer), NULL);
		i = 0;
		while (buffer[i] != '\0' && buffer[i] != '\n')
			i++;
		substring = ft_substr(buffer, 0, i);
		temp_buffer = ft_strjoin(temp_buffer, substring);
		if ((i - 1) != read_chars)
		{
			substring = ft_substr(buffer, i, read_chars);
		}
		return (temp_buffer);
	}
	if (read_chars == -1)
		return (free (buffer), NULL);
	return (buffer);
}

int	main(void)
{
	int		fd;
	char	*new_line;
	int		counter;
	int		i;
	int		j;

	counter = 0;
	fd = open("test.txt", O_RDONLY);
	i = 0;
	j = 0;
	while (j < 5)
	{
		new_line = get_next_line(fd);
		counter++;
		printf("%d : %s\n", counter, new_line);
		if (new_line == NULL)
			break ;
		new_line = NULL;
		j++;
	}
	close(fd);
	return (0);
}
