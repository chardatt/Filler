/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 15:10:09 by tchardat          #+#    #+#             */
/*   Updated: 2020/07/06 19:30:31 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	ft_strat1(t_data *data, t_piece *piece)
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
	return (0);
}

int	ft_strat2(t_data *data, t_piece *piece)
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
	return (0);
}
