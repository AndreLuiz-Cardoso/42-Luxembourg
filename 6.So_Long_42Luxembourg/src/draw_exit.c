/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:20:30 by ancardos          #+#    #+#             */
/*   Updated: 2024/08/13 14:20:31 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_exit(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map[y][x] == 3)
				mlx_put_image_to_window(data->mlx, data->win, data->img_exit, x
					* TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}
