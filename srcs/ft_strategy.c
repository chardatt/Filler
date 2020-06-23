/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strategy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 16:32:06 by tchardat          #+#    #+#             */
/*   Updated: 2020/06/23 16:42:00 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

			//	if (ft_look_for_place(data, piece, x, y) == 1)

int		place_left(t_data *data, t_piece *piece)
{
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('B', 2);
	ft_putchar_fd('\n', 2);
	data->y = 0;
	data->x = 0;
	ft_putchar_fd('F', 2);
	while (data->map[data->y][data->x])
	{
		ft_putchar_fd('Z', 2);
		while (data->y < data->height)
		{
			ft_putchar_fd('Q', 2);
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
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('A', 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);
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
		if (first_height(data, 'X') <= first_height(data, 'O'))
		{
			if (place_top(data, piece) == -1)
				return (-1);
		}
		else
		{
			if (place_left(data, piece) == -1)
				return (-1);
		}
	}
	return (0);
}
