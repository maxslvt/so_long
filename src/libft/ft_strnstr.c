/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolet-l <msolet-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:49:08 by msolet-l          #+#    #+#             */
/*   Updated: 2024/01/22 18:50:40 by msolet-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	if (!len)
		return (NULL);
	i = ft_strlen(little);
	j = 0;
	while (ft_strncmp(&big[j], little, i))
	{
		if (!big[j] || j >= (len - i))
			return (NULL);
		j++;
	}
	if (i > len)
		return (NULL);
	return ((char *)&big[j]);
}
