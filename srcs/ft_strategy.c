/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strategy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 16:32:06 by tchardat          #+#    #+#             */
/*   Updated: 2020/06/22 21:04:28 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

			//	if (ft_look_for_place(data, piece, x, y) == 1)

int		place_right(t_data *data, t_piece *piece)
{
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('G', 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);
	data->x = data->width - 1;
	data->y = data->height - 1;
	while (data->map[data->y][data->x])
	{
		ft_putchar_fd('G', 2);
		while (/*data->map[data->y][data->x]*/ data->y >= 0)
		{
			ft_putchar_fd('H', 2);
			if (data->map[data->y][data->x] == data->letter)
			{
				ft_putchar_fd('J', 2);
				if (take_piece_right(data, piece) == 1)
					return (0);
			}
			data->y--;
			ft_putchar_fd('L', 2);
		}
		ft_putchar_fd('K', 2);
		data->y = data->height - 1;
		ft_putchar_fd('M', 2);
		data->x--;
	}
	return (-1);
}

int		place_down(t_data *data, t_piece *piece)
{
	data->y = data->height - 1;
	while (data->map[data->y])
	{
		data->x = data->width - 1;
		while (data->map[data->y][data->x])
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
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('E', 2);
	ft_putchar_fd('\n', 2);
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
		ft_putchar_fd('a', 2);
//		if (data->first == 0)
//			place_left(data, piece, 'o');
		if (first_height(data, 'X') < first_height(data, 'O'))
			place_top(data, piece);
//		A SUPPR
		else
			place_right(data, piece);
/*		if (last_column(data, 'o'))
			if (place_down(data, piece, 'o') == "FALSE")
				place_up(data, piece, 'o', 1);*/
	}/*
	else if (data->playernum == 2)
	{
		if (first_height('x') < first_height('o'))
			place_top(data, piece, 'x');
		else
			place_left(data, piece, 'x');
	}*/
	return (0);
}
