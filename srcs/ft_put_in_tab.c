#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "ft_header.h"

char     *ft_put_in_tab(int size, char *text) 
{
	int		fd;
	char	*buf;
	int		ret;
	int		i;

	if (!(buf = malloc(sizeof(char)* size + 1)))	
		return (0);
	fd = open(text, O_RDONLY);
	if (fd == -1)
	{
		write(2, "open error\n", 11);
		return (0);
	}
	ret = read(fd, buf, size);
		buf[ret] = '\0';
	i = 0;
	printf("%s\n", buf);
	close(fd);
	return (buf);
}
