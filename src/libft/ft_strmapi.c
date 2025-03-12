/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolet-l <msolet-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:48:57 by msolet-l          #+#    #+#             */
/*   Updated: 2024/01/22 18:50:45 by msolet-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	i;

	if (!s)
		return (NULL);
	result = ft_calloc(ft_strlen(s) + 1, 1);
	if (!result)
		return (NULL);
	i = -1;
	while (s[++i])
		result[i] = f(i, s[i]);
	return (result);
}
