/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 16:32:53 by tchardat          #+#    #+#             */
/*   Updated: 2020/06/22 19:58:57 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	first_height(t_data *data, char c)
{
	int y;
	int x;

	y = 0;
	x = 0;
	ft_putchar_fd('Z', 2);
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			x++;
			if (data->map[y][x] == ft_tolower(c) || data->map[y][x] == c)
			{
				ft_putchar_fd('\n', 2);
				ft_putchar_fd('\n', 2);
				ft_putchar_fd('>', 2);
				ft_putnbr_fd(y, 2);
				ft_putchar_fd('<', 2);
				ft_putchar_fd('\n', 2);
				ft_putchar_fd('\n', 2);
				return (y);
			}
		}
		y++;
	}
	return (y);
}
