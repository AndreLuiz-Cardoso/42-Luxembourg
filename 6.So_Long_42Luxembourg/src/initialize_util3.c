/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_util3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:53:59 by ancardos          #+#    #+#             */
/*   Updated: 2024/08/19 13:54:00 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	funcao6(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img_wall);
	data->img_wall = NULL;
}

void	funcao7(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img_collectible);
	data->img_collectible = NULL;
}

void	funcao8(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img_exit);
	data->img_exit = NULL;
}
