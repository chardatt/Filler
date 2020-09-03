/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 15:10:09 by tchardat          #+#    #+#             */
/*   Updated: 2020/09/03 11:53:56 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	ft_strat1(t_data *data, t_piece *piece)
{
	if (data->height == 15)
	{
		if (place_right(data, piece) == -1)
			if (place_top(data, piece) == -1)
				if (place_down(data, piece) == -1)
					if (place_left(data, piece) == -1)
						return (-1);
	}
	else if (data->height == 24)
	{
		if (ft_strat101(data, piece) == -1)
			return (-1);
	}
	else
	{
		if (ft_strat102(data, piece) == -1)
			return (-1);
	}
	return (0);
}

int	ft_strat101(t_data *data, t_piece *piece)
{
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
	return (0);
}

int	ft_strat102(t_data *data, t_piece *piece)
{
	if ((piece->count <= 55 && piece->count >= 30)
		|| (piece->count >= 100))
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
		if (place_down(data, piece) == -1)
			if (place_left(data, piece) == -1)
				if (place_right(data, piece) == -1)
					if (place_top(data, piece) == -1)
						return (-1);
	piece->count++;
	return (0);
}
