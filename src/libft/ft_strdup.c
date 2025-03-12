/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolet-l <msolet-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:48:12 by msolet-l          #+#    #+#             */
/*   Updated: 2024/01/22 18:51:04 by msolet-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;

	dup = ft_calloc(ft_strlen(src) + 1, 1);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, src, ft_strlen(src) + 1);
	return (dup);
}
