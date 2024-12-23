/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:45:12 by ancardos          #+#    #+#             */
/*   Updated: 2024/02/20 14:48:44 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int z)
{
	if ((z >= 'a' && z <= 'z')
		|| (z >= 'A' && z <= 'Z')
		|| (z >= '0' && z <= '9'))
	{
		return (1);
	}
	return (0);
}
/* 
int main(int argc, char **argv)
{
	(void)argc;
	
	printf("\n\t>>> USING isalnum() <<<\n\n");
	printf("Sending \'%c\'\n", argv[1][0]);
	
	if (isalnum(argv[1][0]))
		printf("The char \'%c\' is alphanumeric.\n", argv[1][0]);
	else
		printf("The char \'%c\' is not alphanumeric.\n", argv[1][0]);
	
	printf("\n\t>>> USING ft_isalnum() <<<\n\n");
	printf("Sending \'%c\'\n", argv[1][0]);
	
	if (ft_isalnum(argv[1][0]))
		printf("The char \'%c\' is alphanumeric.\n", argv[1][0]);
	else
		printf("The char \'%c\' is not alphanumeric.\n", argv[1][0]);
} */
