/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:39:41 by ancardos          #+#    #+#             */
/*   Updated: 2024/08/13 13:39:43 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (i < data->map_height)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
}

void	free_images(t_data *data)
{
	if (data->img_floor)
		mlx_destroy_image(data->mlx, data->img_floor);
	if (data->img_wall)
		mlx_destroy_image(data->mlx, data->img_wall);
	if (data->img_collectible)
		mlx_destroy_image(data->mlx, data->img_collectible);
	if (data->img_exit)
		mlx_destroy_image(data->mlx, data->img_exit);
}

void	free_player_images(t_data *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (data->img_player_down[i])
			mlx_destroy_image(data->mlx, data->img_player_down[i]);
		if (data->img_player_left[i])
			mlx_destroy_image(data->mlx, data->img_player_left[i]);
		if (data->img_player_right[i])
			mlx_destroy_image(data->mlx, data->img_player_right[i]);
		if (data->img_player_up[i])
			mlx_destroy_image(data->mlx, data->img_player_up[i]);
		i++;
	}
}

void	free_mlx_resources(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

void	free_resources(t_data *data)
{
	free_map(data);
	free_images(data);
	free_player_images(data);
	free_mlx_resources(data);
}
