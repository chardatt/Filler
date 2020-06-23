/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 16:32:53 by tchardat          #+#    #+#             */
/*   Updated: 2020/06/23 22:51:12 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int	first_height(t_data *data, char c)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			x++;
			if (data->map[y][x] == ft_tolower(c) || data->map[y][x] == c)
				return (y);
		}
		y++;
	}
	return (y);
}
