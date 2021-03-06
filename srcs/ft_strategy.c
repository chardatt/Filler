/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strategy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 16:32:06 by tchardat          #+#    #+#             */
/*   Updated: 2020/08/30 16:33:54 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

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
	while (data->x >= 0)
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
	while (data->y < data->height)
	{
		data->x = 0;
		while (data->x < data->width)
		{
			if (data->map[data->y][data->x] == data->letter)
				if (take_piece_right(data, piece) == 1
					|| take_piece_left(data, piece))
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
		if (ft_strat1(data, piece) == 0)
			return (0);
	}
	else if (data->playernum == 2)
	{
		if (ft_strat2(data, piece) == 0)
			return (0);
	}
	return (-1);
}
