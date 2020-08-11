/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 15:10:09 by tchardat          #+#    #+#             */
/*   Updated: 2020/08/11 19:23:29 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	ft_strat1(t_data *data, t_piece *piece)
{
/*	if (data->aggr != 0)
	{
		ft_putchar_fd('k', 2);
		ft_cirlce_ennemy(data, piece);
	}*/
	if (data->height == 15)
	{
		ft_putchar_fd('c', 2);
		if (place_right(data, piece) == -1)
			if (place_top(data, piece) == -1)
				if (place_down(data, piece) == -1)
					if (place_left(data, piece) == -1)
						return (-1);
	}
	else if (data->height == 24)
	{
		ft_putchar_fd('a', 2);
		if (piece->count >= 50)
			if (place_top(data, piece) == -1)
				if (place_left(data, piece) == -1)
					if (place_right(data, piece) == -1)
						return (-1);
		if (piece->count < 50 && piece->count > 13)
			if (place_down(data, piece) == -1)
				if (place_right(data, piece) == -1)
					if (place_top(data, piece) == -1)
						if (place_left(data, piece) == -1)
							return (-1);
		if (piece->count <= 13)
			if (place_right(data, piece) == -1)
				if (place_down(data, piece) == -1)
					if (place_left(data, piece) == -1)
						if (place_top(data, piece) == -1)
							return (-1);
		piece->count++;
	}
	else
	{
		ft_putchar_fd('b', 2);
/*		if (piece->count < 500 && piece->count > 100)
		{
			if (place_right(data, piece) == -1)
				if (place_down(data, piece) == -1)
					if (place_top(data, piece) == -1)
						if (place_left(data, piece) == -1)
							return (-1);
		}
		if (piece->count < 200 && piece->count > 60)
		{
			if (place_top(data, piece) == -1)
				if (place_right(data, piece) == -1)
					if (place_left(data, piece) == -1)
						if (place_down(data, piece) == -1)
							return (-1);
		}
		else if (piece->count <= 60)
		{
			if (place_left(data, piece) == -1)
				if (place_right(data, piece) == -1)
					if (place_top(data, piece) == -1)
						if (place_down(data, piece) == -1)
							return (-1);
		}
		else
		{
			if (place_down(data, piece) == -1)
				if (place_left(data, piece) == -1)
					if (place_right(data, piece) == -1)
						if (place_top(data, piece) == -1)
							return (-1);
		}*/
		if ((piece->count <= 55 && piece->count >= 30)
			|| (piece->count < 200 && piece->count >= 100))
		{
			if (place_top(data, piece) == -1)
				if (place_right(data, piece) == -1)
					if (place_down(data, piece) == -1)
						if (place_left(data, piece) == -1)
							return (-1);
		}
		else if (piece->count < 30)
		{
			if (place_left(data, piece) == -1)
				if (place_right(data, piece) == -1)
					if (place_down(data, piece) == -1)
						if (place_top(data, piece) == -1)
							return (-1);
		}
		else if (piece->count < 100)
		{
			if (place_down(data, piece) == -1)
				if (place_left(data, piece) == -1)
					if (place_right(data, piece) == -1)
						if (place_top(data, piece) == -1)
							return (-1);		
		}
	/*	else if (piece->count < 200)
		{
			if (place_left(data, piece) == -1)
				if (place_right(data, piece) == -1)
					if (place_top(data, piece) == -1)
						if (place_down(data, piece) == -1)
							return (-1);
		}*/
		else
		{
			if (place_left(data, piece) == -1)
				if (place_right(data, piece) == -1)
					if (place_down(data, piece) == -1)
						if (place_top(data, piece) == -1)
							return (-1);
		}
		piece->count++;
	}
	return (0);
}

int	ft_strat2(t_data *data, t_piece *piece)
{
	if (first_height(data, 'X') >= first_height(data, 'O'))
	{
		if (place_top(data, piece) == -1)
			if (place_left(data, piece) == -1)
				if (place_right(data, piece) == -1)
					if (place_down(data, piece) == -1)
						return (-1);
	}
	else
	{
		if (place_left(data, piece) == -1)
			if (place_right(data, piece) == -1)
				if (place_down(data, piece) == -1)
					if (place_top(data, piece) == -1)
						return (-1);
	}
	return (0);
}
