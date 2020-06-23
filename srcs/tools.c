/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 16:32:53 by tchardat          #+#    #+#             */
/*   Updated: 2020/06/23 15:39:36 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	last_column(t_data *data, char c)
{
	int	y;
	int x;

	x = data->width - 1;
	y = 0;
	while (data->map[x][y] != c && y < data->height)
		y++;
	if (y == data->height)
		return (0);
	return (1);
}

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
