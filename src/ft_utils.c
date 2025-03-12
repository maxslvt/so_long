/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolet-l <msolet-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:40:57 by msolet-l          #+#    #+#             */
/*   Updated: 2025/03/06 16:22:00 by msolet-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

size_t	ft_strlennl(char *s)
{
	int	i;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	return (i);
}

int	ft_countchr(char *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			n++;
		i++;
	}
	return (n);
}

char	**ft_doubletabdup(char **tab, int size)
{
	char	**dest;
	int		i;
	int		j;

	dest = malloc(size * sizeof(char *));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < size)
	{
		j = 0;
		dest[i] = malloc(ft_strlen(tab[i]) + 1 * sizeof(char));
		if (!dest[i])
			return (ft_freetab(dest, j), NULL);
		while (tab[i][j])
		{
			dest[i][j] = tab[i][j];
			j++;
		}
		dest[i][j] = '\0';
		i++;
	}
	return (dest);
}
