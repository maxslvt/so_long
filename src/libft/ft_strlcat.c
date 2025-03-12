/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolet-l <msolet-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:48:37 by msolet-l          #+#    #+#             */
/*   Updated: 2024/01/22 18:50:52 by msolet-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (s[i] && i != n)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	srclen;
	size_t	destlen;

	srclen = ft_strlen(src);
	if (!n)
		return (srclen);
	destlen = ft_strnlen(dest, n);
	if (destlen == n)
		return (n + srclen);
	if (srclen < n - destlen)
		ft_memcpy(dest + destlen, src, srclen + 1);
	else
	{
		ft_memcpy(dest + destlen, src, n - destlen - 1);
		dest[n - 1] = '\0';
	}
	return (srclen + destlen);
}
