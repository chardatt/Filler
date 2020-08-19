/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 22:17:40 by tchardat          #+#    #+#             */
/*   Updated: 2020/08/19 23:28:38 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	ft_strat2(t_data *data, t_piece *piece)
{
	if (data->height == 15)
	{
		if (ft_strat200(data, piece) == -1)
			return (-1);
	}
	else if (data->height == 24)
	{
		if (ft_strat201(data, piece) == -1)
		{
			piece->count++;
			return (-1);
		}
	}
	else
	{
		if (ft_strat202(data, piece) == -1)
		{
			piece->count++;
			return (-1);
		}
	}
	return (0);
}

int	ft_strat200(t_data *data, t_piece *piece)
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

int	ft_strat201(t_data *data, t_piece *piece)
{
	if (piece->count < 5)
	{
		if (place_down(data, piece) == -1)
			if (place_right(data, piece) == -1)
				if (place_left(data, piece) == -1)
					if (place_top(data, piece) == -1)
						return (-1);
	}
	else if (first_height(data, 'X') >= first_height(data, 'O'))
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
			if (place_top(data, piece) == -1)
				if (place_down(data, piece) == -1)
					if (place_right(data, piece) == -1)
						return (-1);
	}
	return (0);
}

int	ft_strat202(t_data *data, t_piece *piece)
{
	if (piece->count >= 45 && piece->count < 70)
	{
		if (place_top(data, piece) == -1)
			if (place_right(data, piece) == -1)
				if (place_left(data, piece) == -1)
					if (place_down(data, piece) == -1)
						return (-1);
	}
	else if (piece->count < 45)
	{
		if (place_down(data, piece) == -1)
			if (place_left(data, piece) == -1)
				if (place_right(data, piece) == -1)
					if (place_top(data, piece) == -1)
						return (-1);
	}
	else
	{
		if (place_right(data, piece) == -1)
			if (place_top(data, piece) == -1)
				if (place_down(data, piece) == -1)
					if (place_left(data, piece) == -1)
						return (-1);
	}
	return (0);
}
