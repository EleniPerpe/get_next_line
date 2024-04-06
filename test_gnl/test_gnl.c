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
	char			*temp;
	int				i;

	next_line = NULL;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	read_chars = read(fd, buffer, BUFFER_SIZE);
	while (read_chars > 0)
	{
		buffer[read_chars] = '\0'; // Null-terminate buffer after reading
		temp = ft_strjoin(substring, buffer);
		free(substring); // Free previous substring
		substring = temp;
		i = 0;
		while (substring[i] != '\0' && substring[i] != '\n')
			i++;
		if (substring[i] == '\n')
		{
			next_line = ft_substr(substring, 0, i);
			temp = ft_substr(substring, i + 1, ft_strlen(substring) - i - 1);
			free(substring);
			substring = temp;
			return (next_line);
		}
		read_chars = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer); // Free buffer after reading
	free(substring); // Free remaining substring
	if (read_chars == -1)
		return (NULL);
	return (next_line);
}

int	main(void)
{
	int		fd;
	char	*new_line;
	int		counter;

	counter = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while (counter < 5)
	{
		new_line = get_next_line(fd);
		counter++;
		if (new_line == NULL)
			break ;
		printf("%d : %s\n", counter, new_line);
		free(new_line);
	}
	close(fd);
	return (0);
}