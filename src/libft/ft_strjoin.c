/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolet-l <msolet-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:48:28 by msolet-l          #+#    #+#             */
/*   Updated: 2024/01/22 18:50:54 by msolet-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	dest = malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		dest[j++] = s2[i];
		i++;
	}
	dest[j] = 0;
	return (dest);
}
