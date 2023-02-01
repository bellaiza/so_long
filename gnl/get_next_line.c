#include "../includes/get_next_line.h"

static int	line_new(char *save)
{
	int	i;

	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

static int	line_split(char **save, char **line)
{
	char	*temp;
	int		len;

	len = line_new(*save);
	if ((*save)[len] == '\0')
	{
		*line = ft_strdup(*save);
		free (*save);
		*save = 0;
		return (0);
	}
	(*save)[len] = '\0';
	*line = ft_strdup(*save);
	temp = ft_strdup((*save) + len + 1);
	free(*save);
	*save = temp;
	return (1);
}

static int	all_cases(char **save, char **line, int reader)
{
	if (reader < 0)
		return (-1);
	else if (reader == 0 && *save == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (line_split(save, line));
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buffer;
	char		*temp;
	int			reader;

	buffer = malloc((sizeof(char) * BUFFER_SIZE + 1));
	reader = read(fd, buffer, BUFFER_SIZE);
	while (reader > 0)
	{
		buffer[reader] = '\0';
		if (save == NULL)
			save = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(save, buffer);
			free(save);
			save = temp;
		}
		if (ft_strchr(save, '\n'))
			break ;
		reader = read(fd, buffer, BUFFER_SIZE);
	}
	free (buffer);
	return (all_cases(&save, line, reader));
}
