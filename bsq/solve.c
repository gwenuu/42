#include "bsq.h"

void help(char *str, char **cmap, int ind[5])
{
	int	i;
	int	j;

	i = -1;
	while (++i < ind[1])
	{
		cmap[i] = malloc(sizeof(char) * (ind[2] + 1));
		if (!(cmap[i]))
			{
				while (--i >= 0)
					free(cmap[i]);
				free(cmap);
				return ;
			}
		j = -1;
		while (++j < ind[2])
			cmap[i][j] = str[ind[0] + i * (ind[2] + 1) + j];
		cmap[i][ind[2]] = '\0';
	}
	return ;
}
char	**char_map(char *str, int h, int w)
{
	char	**cmap;
	int ind[3];

	ind[0] = 0;
	while (str[ind[0]] != '\n')
	{
		++ind[0];
	}
	ind[0] = ind[0] + 1;
	cmap = malloc(sizeof(char *) * h);
	if (!cmap)
		return (0);
	ind[1] = h;
	ind[2] = w;
	help(str, cmap, ind);
	return (cmap);
}

void	print_and_free(char **cmap, int h, int w)
{
	int	i;

	i = -1;
	while (++i < h)
	{
		write(1, cmap[i], w);
		write(1, "\n", 1);
		free(cmap[i]);
	}
	free(cmap);
	return ;
}

int	solve_map(char *str, char *params, int h, int w)
{
	int	**bin;
	int	i;
	int	res[3];
	char	**cmap;

	res[0] = 0;
	res[1] = 0;
	res[2] = 0;
	i = 0;
	while (str[i] != '\n')
		i++;
	h = get_nbr(str, i);
	w = width(str, i + 1);
	bin = map_to_binary(str, params);
	if (!bin)
		return (0);
	solu(bin, h, w, res);
	cmap = char_map(str, h, w);
	if (!cmap)
		return (0);
	paint(res, cmap, params[2]);
	print_and_free(cmap, h, w);
	free_bin(bin, h);
	return (1);
}
