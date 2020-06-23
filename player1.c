/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 17:07:32 by tchardat          #+#    #+#             */
/*   Updated: 2020/06/23 22:50:57 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int		place_piece(t_data *data, t_piece *piece)
{
	if (ft_strategy(data, piece) == -1)
		return (-1);
	return (0);
}

int		player1(t_data *data, t_piece *piece)
{
	data = read_map(data);
	piece = read_piece(piece, data);
	if (place_piece(data, piece) == -1)
		return (-1);
	return (0);
}
