/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:50:54 by ancardos          #+#    #+#             */
/*   Updated: 2024/03/15 15:50:57 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	convert_num(unsigned int nb)
{
	if (nb > 9)
		print_unsigned(nb / 10);
	if (nb <= 9)
	{
		ft_putchar_fd(nb + 48, 1);
		return ;
	}
	ft_putchar_fd((nb % 10) + 48, 1);
}

int	print_unsigned(unsigned int nb)
{
	unsigned int	i;

	convert_num(nb);
	i = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}
