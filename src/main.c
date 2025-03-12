/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolet-l <msolet-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:40:31 by msolet-l          #+#    #+#             */
/*   Updated: 2025/03/06 16:24:14 by msolet-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_vars	data;

	ft_bzero(&data, sizeof(data));
	if (ac != 2)
		return (ft_printerror(ERROR8));
	if (!ft_check_filename(av[1]))
		return (ft_printerror(ERROR11));
	data.map = ft_convmap(av[1]);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		on_destroy(&data);
	ft_texture_init(&data);
	ft_texture_chara_init(&data);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.map->lenght
			* data.wall->lenght, data.map->size * data.wall->lenght, WIN_NAME);
	if (!data.win_ptr)
		on_destroy(&data);
	ft_create_map(&data);
	data.mc->c = 0;
	data.cpt = 0;
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy,
		&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
