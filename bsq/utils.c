/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 16:15:22 by dkrot             #+#    #+#             */
/*   Updated: 2026/07/29 20:49:38 by dkrot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*str_join(char *old, char *chunk, int n)
{
	int		old_len;
	int		i;
	char	*new;

	old_len = ft_strlen(old);
	new = malloc(old_len + n + 1);
	if (!new)
		return (0);
	i = -1;
	while (++i < old_len)
		new[i] = old[i];
	i = -1;
	while (++i < n)
		new[old_len + i] = chunk[i];
	new[old_len + n] = '\0';
	free(old);
	return (new);
}

int	ft_atoi(char *str)
{
	int		i;
	long	nbr;

	i = 0;
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		if (nbr > 2147483647)
			return (-1);
		i++;
	}
	return (nbr);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	under_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}
