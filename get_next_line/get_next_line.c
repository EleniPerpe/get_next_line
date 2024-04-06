/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:42:34 by eperperi          #+#    #+#             */
/*   Updated: 2024/04/06 20:20:53 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*get_next_line(int fd)
{
	int				read_chars;
	char			*buffer;
	char			*next_line;
	static char		*substring;
	char			*copy;
	int				i;
	int				j;

	next_line = NULL;
	copy = NULL;
	buffer = (char *)malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	read_chars = read(fd, buffer, BUFFER_SIZE);
	while (read_chars > 0)
	{
		copy = buffer;
		if (substring != NULL)
			copy = ft_strjoin(substring, copy);
		printf("Copy : %s\n", copy);
		printf("%d : (buffer) %s\n", read_chars, buffer);
		i = 0;
		while (copy[i] != '\0' && copy[i] != '\n')
			i++;
		printf("..%c..\n", buffer[i - 1]);
		// printf("i : %d\n", i);
		// substring = ft_substr(copy, 0, i + 1);
		// printf("Sub : %s\n", substring);
		if (copy[i] == '\n' || copy[i] == '\0')
		{
			printf("Next line : %s\n", copy);
			next_line = ft_strjoin(next_line, copy);
		}
		// copy = ft_strjoin(copy, substring);
		printf("Temp : %s\n", next_line);
		if ((i - 1) != read_chars)
		{
			substring = ft_substr(buffer, i + 1, read_chars + 1);
			printf("Sub : %s\n", substring);
		}
		else
		{
			substring = copy;
		}
		printf("Second part sub : %s\n", substring);
		read_chars = read(fd, buffer, BUFFER_SIZE);
		printf("read_chars : %d : %s\n\n\n", read_chars, buffer);
	}
	if (read_chars == -1)
		return (free (buffer), NULL);
	return (copy);
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
		free(new_line);
		j++;
	}
	close(fd);
	return (0);
}
