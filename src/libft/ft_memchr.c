/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolet-l <msolet-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:46:38 by msolet-l          #+#    #+#             */
/*   Updated: 2024/01/22 18:51:33 by msolet-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	letter;
	size_t			i;

	str = (unsigned char *)s;
	letter = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == letter)
			return (str + i);
		i++;
	}
	return (NULL);
}
