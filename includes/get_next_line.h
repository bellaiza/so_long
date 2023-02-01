#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "stdlib.h"
# include "unistd.h"

# define FD_SIZE 4096
# define BUFFER_SIZE 1024

int		get_next_line(int fd, char **line);

size_t	ft_strlen(const char *s);

char	*ft_strchr(const char *s, int c);

char	*ft_strdup(const char *s1);

char	*ft_strjoin(const char *s1, const char *s2);

void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif