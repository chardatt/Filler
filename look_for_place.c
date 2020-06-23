/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_for_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 15:05:35 by tchardat          #+#    #+#             */
/*   Updated: 2020/06/23 22:50:19 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int		check_place(t_data *data, t_piece *piece, int x, int y)
{
	if (x > data->width || x < 0)
		return (0);
	if (y > data->height || y < 0)
		return (0);
	if (x + piece->widthpiece > data->width)
		return (0);
	if (y + piece->heightpiece > data->height)
		return (0);
	return (1);
}

int		check_superpose(t_data *data, t_piece *piece, int x, int y)
{
	int		i;
	int		j;
	int		tmpx;
	int		compt;

	i = -1;
	tmpx = x;
	compt = 0;
	while (++i < piece->heightpiece)
	{
		j = -1;
		x = tmpx;
		while (++j < piece->widthpiece)
		{
			if (data->playernum == 1)
				if (piece->piece[i][j] == '*' && data->map[y][x] == 'O')
					compt++;
			if (data->playernum == 2)
				if (piece->piece[i][j] == '*' && data->map[y][x] == 'X')
					compt++;
			x++;
		}
		y++;
	}
	return ((compt > 1) ? 0 : 1);
}

int		check_superpose_adverse(t_data *data, t_piece *piece, int x, int y)
{
	int		i;
	int		j;
	int		tmpx;

	i = 0;
	tmpx = x;
	while (i < piece->heightpiece)
	{
		j = 0;
		x = tmpx;
		while (j < piece->widthpiece)
		{
			if (data->playernum == 1)
				if (piece->piece[i][j] == '*' && data->map[y][x] == 'X')
					return (0);
			if (data->playernum == 2)
				if (piece->piece[i][j] == '*' && data->map[y][x] == 'O')
					return (0);
			j++;
			x++;
		}
		i++;
		y++;
	}
	return (1);
}

int		ft_look_for_place(t_data *data, t_piece *piece)
{
	int		x;
	int		y;

	x = data->x - piece->x;
	y = data->y - piece->y;
	if (check_place(data, piece, x, y) == 0)
		return (0);
	if (check_superpose(data, piece, x, y) == 0)
		return (0);
	if (check_superpose_adverse(data, piece, x, y) == 0)
		return (0);
	return (1);
}
