/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolet-l <msolet-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:42:08 by msolet-l          #+#    #+#             */
/*   Updated: 2025/03/06 18:25:16 by msolet-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_read_map(char **map, int fd, int nline, t_map *tmap)
{
	int		i;

	i = 0;
	map[i++] = get_next_line(fd);
	if (map[0] == NULL)
		(free(map), close(fd), ft_freeandexit(tmap, ERROR14));
	while (i < nline)
	{
		map[i++] = get_next_line(fd);
		if (map[i - 1] == NULL)
		{
			ft_freetab(map, ft_min(0, i - 2));
			close(fd);
			ft_freeandexit(tmap, ERROR14);
		}
	}
	close(fd);
}

char	**ft_copymap(t_map *tmap, char *path)
{
	char	**map;
	int		nline;
	int		fd;

	nline = ft_count_line(tmap, path);
	if (nline == -1)
		ft_freeandexit(tmap, ERROR10);
	map = (char **)malloc(nline * sizeof(char *));
	if (!map)
		ft_freeandexit(tmap, ERROR14);
	fd = open(path, O_RDWR);
	if (fd == -1)
		(free(map), ft_freeandexit(tmap, ERROR9));
	ft_read_map(map, fd, nline, tmap);
	tmap->size = nline;
	return (map);
}

t_map	*ft_convmap(char *path)
{
	t_map	*tmap;

	tmap = (t_map *)malloc(sizeof(t_map));
	if (!tmap)
	{
		ft_printerror(ERROR14);
		exit(0);
	}
	tmap->map = ft_copymap(tmap, path);
	if (tmap->map)
		tmap->lenght = ft_strlennl(tmap->map[0]);
	tmap->c = 0;
	tmap->e = 0;
	tmap->p = 0;
	if (!tmap->map || !ft_check(tmap))
	{
		ft_freetab(tmap->map, tmap->size);
		ft_freeandexit(tmap, "");
	}
	return (tmap);
}

void	ft_mapflags(t_vars *data, char c, int i, int j)
{
	if (c == '1')
		ft_print_mlx(data, data->wall->img, i * data->wall->height, j
			* data->wall->lenght);
	else if (c == 'C')
		ft_print_mlx(data, data->coin->img, i * data->floor->height, j
			* data->floor->lenght);
	else if (c == 'E')
		ft_print_mlx(data, data->exit->img, i * data->wall->height, j
			* data->exit->lenght);
	else if (c == '0')
		ft_print_mlx(data, data->floor->img, i * data->floor->height, j
			* data->floor->lenght);
	else if (c == 'P')
	{
		ft_print_mlx(data, data->mc->texture_down->img,
			i * data->mc->texture_down->height,
			j * data->mc->texture_down->lenght);
		data->mc->x = j;
		data->mc->y = i;
	}
}

void	ft_create_map(t_vars *data)
{
	int		i;
	size_t	j;

	j = 0;
	while (j < data->map->size)
	{
		i = 0;
		while (data->map->map[j][i] != '\0' && data->map->map[j][i] != '\n')
		{
			ft_mapflags(data, data->map->map[j][i], i, j);
			i++;
		}
		j++;
	}
}
