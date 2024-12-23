/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_util2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:36:23 by ancardos          #+#    #+#             */
/*   Updated: 2024/08/16 17:36:24 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	funcao1(t_data *data, int i)
{
	mlx_destroy_image(data->mlx, data->img_player_down[i]);
	data->img_player_down[i] = NULL;
}

void	funcao2(t_data *data, int i)
{
	mlx_destroy_image(data->mlx, data->img_player_left[i]);
	data->img_player_left[i] = NULL;
}

void	funcao3(t_data *data, int i)
{
	mlx_destroy_image(data->mlx, data->img_player_right[i]);
	data->img_player_right[i] = NULL;
}

void	funcao4(t_data *data, int i)
{
	mlx_destroy_image(data->mlx, data->img_player_up[i]);
	data->img_player_up[i] = NULL;
}

void	funcao5(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img_floor);
	data->img_floor = NULL;
}
