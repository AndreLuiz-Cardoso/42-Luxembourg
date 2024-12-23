/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:32:05 by ancardos          #+#    #+#             */
/*   Updated: 2024/08/16 17:32:06 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	cleanup_images(t_data *data, int num_sprites)
{
	int		i;

	i = 0;
	while (i < num_sprites)
	{
		if (data->img_player_down[i])
			funcao1(data, i);
		if (data->img_player_left[i])
			funcao2(data, i);
		if (data->img_player_right[i])
			funcao3(data, i);
		if (data->img_player_up[i])
			funcao4(data, i);
		i++;
	}
	if (data->img_floor)
		funcao5(data);
	if (data->img_wall)
		funcao6(data);
	if (data->img_collectible)
		funcao7(data);
	if (data->img_exit)
		funcao8(data);
}
