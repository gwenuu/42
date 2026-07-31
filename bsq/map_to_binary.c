#include "bsq.h"

void	free_bin(int **bin, int j)
{
	while (--j >= 0)
		free(bin[j]);
	free(bin);
}

int	fill_row(int *row, char *str, char *params)
{
	int	k;

	k = 0;
	while (str[k] != '\0' && str[k] != '\n')
	{
		if (str[k] == params[0])
			row[k] = 1;
		else
			row[k] = 0;
		k++;
	}
	return (k);
}

int	**do_binary(char *str, char *params, int h, int w)
{
	int	**bin;
	int	j;

	bin = malloc(8 * h);
	if (!bin)
		return (0);
	j = 0;
	while (j < h)
	{
		bin[j] = malloc(4 * w);
		if (!bin[j])
		{
			free_bin(bin, j);
			return (0);
		}
		str += fill_row(bin[j], str, params) + 1;
		j++;
	}
	return (bin);
}

int	**map_to_binary(char *str, char *params)
{
	int	i;
	int	w;
	int	h;

	i = 0;
	while (str[i++] != '\n')
		;
	w = width(str, i);
	h = get_nbr(str, under_strlen(str));
	return (do_binary(str + i, params, h, w));
}
