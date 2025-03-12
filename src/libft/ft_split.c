/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolet-l <msolet-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:47:57 by msolet-l          #+#    #+#             */
/*   Updated: 2024/01/22 18:51:08 by msolet-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(const char *s, char c)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') && s[i] != c)
			nb++;
		i++;
	}
	return (nb);
}

static int	ft_wordsize(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

static void	*free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char	**ft_malloc_tab(char const *s, char c)
{
	char	**tab;
	int		size;

	if (!s)
		return (NULL);
	size = ft_countwords(s, c) + 1;
	tab = (char **)malloc(sizeof(char *) * size);
	if (!tab)
		return (NULL);
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	tab = ft_malloc_tab(s, c);
	if (!tab)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			tab[j] = (char *)malloc(sizeof(char) * (ft_wordsize(&s[i], c) + 1));
			if (!tab[j])
				return (free_tab(tab));
			ft_strlcpy(tab[j], (char *)&s[i], ft_wordsize(&s[i], c) + 1);
			i = i + ft_wordsize(&s[i], c);
			j++;
		}
		else
			i++;
	}
	tab[j] = NULL;
	return (tab);
}
