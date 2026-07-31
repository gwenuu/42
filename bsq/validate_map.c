/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrot <dkrot@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 13:34:59 by dkrot             #+#    #+#             */
/*   Updated: 2026/07/29 21:03:35 by dkrot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*validate_first_line(char *str, int n)
{
	int			i;
	static char	params[3];

	if (n < 4)
		return (0);
	if (!('9' >= str[0] && str[0] >= '0'))
		return (0);
	if (str[0] == '0' && str[1] >= '0' && str[1] <= '9')
		return (0);
	i = 0;
	while ('9' >= str[i] && str[i] >= '0' && i < n - 3)
		i++;
	if (str[i] == '\0' || str[i + 1] == '\0' || str[i + 2] == '\0'
		|| str[i + 3] != '\n' || str[i] < 32 || str[i] > 126
		|| str[i + 1] < 32 || str[i + 1] > 126 || str[i + 2] < 32
		|| str[i + 2] > 126 || str[i] == str[i + 1]
		|| str[i] == str[i + 2] || str[i + 1] == str[i + 2])
		return (0);
	params[0] = str[i];
	params[1] = str[i + 1];
	params[2] = str[i + 2];
	return (params);
}

int	get_nbr(char *str, int n)
{
	int		i;
	int		j;
	char	nbr[11];

	i = 0;
	while (str[i] >= '0' && str[i] <= '9' && i < n - 3)
		i++;
	if (i > 10)
		return (-1);
	j = 0;
	while (j < i)
	{
		nbr[j] = str[j];
		j++;
	}
	nbr[j] = '\0';
	return (ft_atoi(nbr));
}

int	width(char *str, int i)
{
	int	j;

	j = 0;
	while (str[i + j] && str[i + j] != '\n')
		j++;
	return (j);
}

int	check_rows(char *str, int i, int width, char *p)
{
	int	col;
	int	rows;

	rows = 0;
	while (str[i])
	{
		col = 0;
		while (str[i] && str[i] != '\n')
		{
			if (str[i] != p[0] && str[i] != p[1])
				return (-1);
			col++;
			i++;
		}
		if (col != width)
			return (-1);
		rows++;
		if (str[i] == '\n')
			i++;
	}
	return (rows);
}

int	validate_map(char *str)
{
	char	*params;
	int		nbr;
	int		i;
	int		w;

	params = validate_first_line(str, under_strlen(str));
	if (params == 0)
		return (0);
	nbr = get_nbr(str, under_strlen(str));
	if (nbr <= 0)
		return (0);
	i = 0;
	while (str[i] != '\n')
		i++;
	i++;
	w = width(str, i);
	if (w == 0)
		return (0);
	if (check_rows(str, i, w, params) != nbr)
		return (0);
	return (1);
}
