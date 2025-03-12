/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printables.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolet-l <msolet-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:42:04 by msolet-l          #+#    #+#             */
/*   Updated: 2025/03/06 15:21:39 by msolet-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_Bool	ft_printerror(char *error_msg)
{
	ft_printf("Error\n%s", error_msg);
	return (False);
}

void	ft_win(t_vars *data)
{
	ft_printf("\r [END GAME] You Won !                                \n ");
	ft_printf("[STATS] Movements: %i / Score: %d", data->cpt * 1, data->mc->c);
	on_destroy(data);
}

void	ft_print_mlx(t_vars *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, ft_min(x,
			data->map->lenght * 80), ft_min(y, data->map->size * 80));
}
