/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolet-l <msolet-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:42:25 by msolet-l          #+#    #+#             */
/*   Updated: 2025/03/06 16:13:49 by msolet-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_Bool	ft_check_filename(char *dir)
{
	int	i;

	i = 0;
	while (dir[i])
		i++;
	if (i >= 4)
		return (ft_strncmp(dir + i - 4, ".ber", 4) == 0);
	return (False);
}

t_Bool	ft_check(t_map *data)
{
	size_t	i;
	char	**temp;

	i = 0;
	if (!ft_check3(data->map[i]))
		return (False);
	while (i < data->size)
	{
		if (!ft_check1(data->map[i]) || !ft_check2(data, data->map[i], False)
			|| !ft_check4(data->map[i]))
			return (False);
		if (data->lenght != ft_strlennl(data->map[i]))
			return (ft_printerror(ERROR0));
		i++;
	}
	if (!ft_check2(data, data->map[i - 1], True) || !ft_check3(data->map[i
				- 1]))
		return (False);
	temp = ft_doubletabdup(data->map, data->size);
	if (!temp)
		return (ft_printerror(ERROR14), False);
	if (!ft_floodfill_check(temp, data->size, data->c))
		return (ft_freetab(temp, data->size), False);
	return (ft_freetab(temp, data->size), True);
}
