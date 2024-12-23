/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:40:08 by ancardos          #+#    #+#             */
/*   Updated: 2024/08/13 13:40:09 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_game_window(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->map_width * TILE_SIZE,
			data->map_height * TILE_SIZE, "So Long");
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	data.map = load_map(argv[1], &data);
	if (!data.map)
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	data.move_count = 0;
	start_game(&data);
	free_resources(&data);
	return (0);
}
