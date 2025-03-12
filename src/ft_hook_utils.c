/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolet-l <msolet-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:34:57 by msolet-l          #+#    #+#             */
/*   Updated: 2025/03/06 15:51:59 by msolet-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player_addon(t_vars *data, char direction)
{
	if (direction == 'L')
		ft_print_mlx(data, data->mc->texture_left->img, data->mc->y
			* data->mc->texture_left->lenght, data->mc->x
			* data->mc->texture_left->height);
	else if (direction == 'R')
		ft_print_mlx(data, data->mc->texture_right->img, data->mc->y
			* data->mc->texture_right->lenght, data->mc->x
			* data->mc->texture_right->height);
	else if (direction == 'U')
		ft_print_mlx(data, data->mc->texture_up->img, data->mc->y
			* data->mc->texture_up->lenght, data->mc->x
			* data->mc->texture_up->height);
	else if (direction == 'D')
		ft_print_mlx(data, data->mc->texture_down->img, data->mc->y
			* data->mc->texture_down->lenght, data->mc->x
			* data->mc->texture_down->height);
}

void	ft_freetextures_addon(t_vars *data)
{
	if (data->mc->texture_left)
		mlx_destroy_image(data->mlx_ptr, data->mc->texture_left->img);
	free(data->mc->texture_left);
	if (data->mc->texture_right)
		mlx_destroy_image(data->mlx_ptr, data->mc->texture_right->img);
	free(data->mc->texture_right);
	if (data->mc->texture_up)
		mlx_destroy_image(data->mlx_ptr, data->mc->texture_up->img);
	free(data->mc->texture_up);
	if (data->mc->texture_down)
		mlx_destroy_image(data->mlx_ptr, data->mc->texture_down->img);
	free(data->mc->texture_down);
	free(data->mc);
}
