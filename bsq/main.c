#include "bsq.h"

void	process_map(char *str)
{
	char	*params;

	if (!validate_map(str))
	{
		write(1, "map error\n", 10);
		return ;
	}
	params = validate_first_line(str, under_strlen(str));
	if (!solve_map(str, params,0,0))
		write(1, "map error\n", 10);
	return ;
}

void	handle_stdin(void)
{
	char	*str;

	str = input_to_str(0);
	if (str)
	{
		process_map(str);
		free(str);
	}
	else
		write(1, "map error\n", 10);
}

void	process_file(char *filename)
{
	int		fd;
	char	*str;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(1, "map error\n", 10);
		return ;
	}
	str = input_to_str(fd);
	close(fd);
	if (str)
	{
		process_map(str);
		free(str);
	}
	else
		write(1, "map error\n", 10);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		handle_stdin();
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		process_file(argv[i]);
		if (i < argc - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
