#include "bsq.h"

int	mini(int a, int b, int c)
{
	if ((a <= b) && (a <= c))
		return (a);
	if ((b <= a) && (b <= c))
		return (b);
	return (c);
}

void	finder(int **map, int res[3], int i, int j)
{
	int	cand;

	if ((i > 0) && (j > 0))
	{
		map[i][j] = map[i][j] + mini(map[i - 1][j - 1], map[i][j - 1],
				map[i - 1][j]);
	}
	cand = map[i][j];
	if (cand > res[0])
	{
		res[0] = cand;
		res[1] = i;
		res[2] = j;
	}
}

void	solu(int **map, int h, int w, int res[3])
{
	int	i;
	int	j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			if (map[i][j] == 1)
				finder(map, res, i, j);
			j++;
		}
		i++;
	}
}

void	paint(int res[3], char **map, char c)
{
	int	i;
	int	j;

	i = res[1];
	while (res[1] - i < res[0])
	{
		j = res[2];
		while (res[2] - j < res[0])
		{
			map[i][j] = c;
			j--;
		}
		i--;
	}
}
