/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:53:26 by tchardat          #+#    #+#             */
/*   Updated: 2020/06/23 22:51:05 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

void	reset_piece(t_piece *piece)
{
	piece->heightpiece = 0;
	piece->widthpiece = 0;
	piece->x = 0;
	piece->y = 0;
	piece->piece = NULL;
}

void	reset_data(t_data *data)
{
	data->x = 0;
	data->y = 0;
	data->map = NULL;
}
