/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strategy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 16:32:06 by tchardat          #+#    #+#             */
/*   Updated: 2020/07/02 15:14:29 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int		place_left(t_data *data, t_piece *piece)
{
	data->y = 0;
	data->x = 0;
	while (data->map[data->y][data->x])
	{
		while (data->y < data->height)
		{
			if (data->map[data->y][data->x] == data->letter)
				if (take_piece_left(data, piece) == 1)
					return (0);
			data->y++;
		}
		data->y = 0;
		data->x++;
	}
	return (-1);
}

int		place_right(t_data *data, t_piece *piece)
{
	data->x = data->width - 1;
	data->y = data->height - 1;
	while (data->map[data->y][data->x])
	{
		while (data->y >= 0)
		{
			if (data->map[data->y][data->x] == data->letter)
			{
				if (take_piece_right(data, piece) == 1)
					return (0);
			}
			data->y--;
		}
		data->y = data->height - 1;
		data->x--;
	}
	return (-1);
}

int		place_down(t_data *data, t_piece *piece)
{
	data->y = data->height - 1;
	while (data->y > 0)
	{
		data->x = data->width - 1;
		while (data->x > 0)
		{
			if (data->map[data->y][data->x] == data->letter)
				if (take_piece_left(data, piece) == 1)
					return (0);
			data->x--;
		}
		data->y--;
	}
	return (-1);
}

int		place_top(t_data *data, t_piece *piece)
{
	data->y = 0;
	while (data->map[data->y])
	{
		data->x = 0;
		while (data->map[data->y][data->x])
		{
			if (data->map[data->y][data->x] == data->letter)
				if (take_piece_left(data, piece) == 1)
					return (0);
			data->x++;
		}
		data->y++;
	}
	return (-1);
}

int		ft_strategy(t_data *data, t_piece *piece)
{
	if (data->playernum == 1)
	{
		if (first_height(data, 'X') < first_height(data, 'O'))
		{
			if (place_top(data, piece) == -1)
				return (-1);
		}
		else
		{
			if (place_right(data, piece) == -1)
				if (place_down(data, piece) == -1)
					return (-1);
		}
	}
	else if (data->playernum == 2)
	{
		if (ft_strat2(data, piece) == -1)
			return (-1);
	}
	return (0);
}
