#include "bsq.h"

char	*input_to_str(int fd)
{
	char	buffer[BUF_SIZE];
	char	*str;
	int		bytes;

	str = malloc(1);
	if (!str)
		return (0);
	str[0] = '\0';
	bytes = read(fd, buffer, BUF_SIZE);
	while (bytes > 0)
	{
		str = str_join(str, buffer, bytes);
		if (!str)
			return (0);
		bytes = read(fd, buffer, BUF_SIZE);
	}
	if (bytes < 0)
	{
		free(str);
		return (0);
	}
	return (str);
}
