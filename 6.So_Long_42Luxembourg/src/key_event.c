/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:38:47 by ancardos          #+#    #+#             */
/*   Updated: 2024/08/13 13:38:49 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_wall(int x, int y, t_data *data)
{
	int	map_x;
	int	map_y;

	map_x = x / TILE_SIZE;
	map_y = y / TILE_SIZE;
	if (map_x >= 0 && map_x < data->map_width && map_y >= 0
		&& map_y < data->map_height)
	{
		return (data->map[map_y][map_x] == 1);
	}
	return (1);
}

void	update_position_and_image(int keycode, t_data *data, int *new_x,
		int *new_y)
{
	if (keycode == 97)
	{
		*new_x -= TILE_SIZE;
		data->img_player_current = data->img_player_left[data->frame];
	}
	else if (keycode == 100)
	{
		*new_x += TILE_SIZE;
		data->img_player_current = data->img_player_left[data->frame];
	}
	else if (keycode == 119)
	{
		*new_y -= TILE_SIZE;
		data->img_player_current = data->img_player_left[data->frame];
	}
	else if (keycode == 115)
	{
		*new_y += TILE_SIZE;
		data->img_player_current = data->img_player_left[data->frame];
	}
}

int	key_event(int keycode, t_data *data)
{
	int	new_x;
	int	new_y;

	new_x = data->x;
	new_y = data->y;
	handle_exit(keycode);
	update_position_and_image(keycode, data, &new_x, &new_y);
	if (!is_wall(new_x, new_y, data))
	{
		data->move_count++;
		ft_putstr_fd("movements: ", 1);
		ft_putnbr_fd(data->move_count, 1);
		mlx_put_image_to_window(data->mlx, data->win, data->img_floor, data->x,
			data->y);
		data->x = new_x;
		data->y = new_y;
		update_collectibles(data, new_x, new_y);
		check_victory(data, new_x, new_y);
		mlx_put_image_to_window(data->mlx, data->win, data->img_player_current,
			data->x, data->y);
		data->frame = (data->frame + 1) % 3;
	}
	return (0);
}
