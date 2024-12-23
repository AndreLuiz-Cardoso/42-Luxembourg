/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:39:56 by ancardos          #+#    #+#             */
/*   Updated: 2024/08/13 13:39:57 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_element(t_data *data, int x, int y, void *img)
{
	mlx_put_image_to_window(data->mlx, data->win, img, x * TILE_SIZE, y
		* TILE_SIZE);
}

void	draw_player(t_data *data, int x, int y)
{
	draw_element(data, x, y, data->img_floor);
	draw_element(data, x, y, data->img_player_current);
	data->x = x * TILE_SIZE;
	data->y = y * TILE_SIZE;
}

void	draw_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map[y][x] == 1)
				draw_element(data, x, y, data->img_wall);
			else if (data->map[y][x] == 0)
				draw_element(data, x, y, data->img_floor);
			else if (data->map[y][x] == 2)
				draw_element(data, x, y, data->img_collectible);
			else if (data->map[y][x] == 4)
				draw_player(data, x, y);
			x++;
		}
		y++;
	}
}
