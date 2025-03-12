/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolet-l <msolet-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:41:43 by msolet-l          #+#    #+#             */
/*   Updated: 2025/03/06 15:21:36 by msolet-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_Bool	ft_check_texture(t_vars *data)
{
	if (data->wall->height == data->wall->lenght
		&& data->wall->height == data->coin->height
		&& data->wall->height == data->coin->lenght
		&& data->wall->height == data->exit->height
		&& data->wall->height == data->exit->lenght
		&& data->wall->height == data->mc->texture_left->height
		&& data->wall->height == data->mc->texture_left->lenght
		&& data->wall->height == data->mc->texture_right->height
		&& data->wall->height == data->mc->texture_right->lenght
		&& data->wall->height == data->mc->texture_up->height
		&& data->wall->height == data->mc->texture_up->lenght
		&& data->wall->height == data->mc->texture_down->height
		&& data->wall->height == data->mc->texture_down->lenght)
		return (True);
	return (False);
}

t_data	*ft_load_texture(t_vars *data, t_data **image, char *direction)
{
	t_data	*e;
	int		a;
	int		b;

	e = (t_data *)malloc(sizeof(*e));
	if (!e)
		return (NULL);
	e->img = mlx_xpm_file_to_image(data->mlx_ptr, direction, &a, &b);
	if (!e->img)
		return (free(e), NULL);
	*image = e;
	(*image)->height = a;
	(*image)->lenght = b;
	return (e);
}

void	ft_texture_init(t_vars *data)
{
	if (!(ft_load_texture(data, &data->wall, "assets/wall.xpm")
			&& ft_load_texture(data, &data->floor, "assets/floor.xpm")
			&& ft_load_texture(data, &data->coin, "assets/coins.xpm")
			&& ft_load_texture(data, &data->exit, "assets/exit.xpm")))
	{
		ft_printerror(ERROR12);
		on_destroy(data);
	}
}

void	ft_texture_chara_init(t_vars *data)
{
	t_mc	*mc;

	mc = (t_mc *)malloc(sizeof(*mc));
	if (!mc)
		on_destroy(data);
	data->mc = mc;
	data->mc->texture_left = NULL;
	data->mc->texture_right = NULL;
	data->mc->texture_up = NULL;
	data->mc->texture_down = NULL;
	if (!(ft_load_texture(data, &data->mc->texture_left, "assets/L.xpm")
			&& ft_load_texture(data, &data->mc->texture_right, "assets/R.xpm")
			&& ft_load_texture(data, &data->mc->texture_up, "assets/U.xpm")
			&& ft_load_texture(data, &data->mc->texture_down, "assets/D.xpm")))
	{
		ft_printerror(ERROR12);
		on_destroy(data);
	}
	if (!ft_check_texture(data))
	{
		ft_printerror(ERROR12);
		on_destroy(data);
	}
}
