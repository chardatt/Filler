/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 17:18:16 by tchardat          #+#    #+#             */
/*   Updated: 2020/07/12 18:12:34 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		take_piece_left(t_data *data, t_piece *piece)
{
	piece->y = 0;
	while (piece->y < piece->heightpiece)
	{
		piece->x = 0;
		while (piece->x < piece->widthpiece)
		{
			if (piece->piece[piece->y][piece->x] == '*')
			{
				if (ft_look_for_place(data, piece))
				{
					ft_putnbr(data->y - piece->y);
					ft_putchar(' ');
					ft_putnbr(data->x - piece->x);
					ft_putchar('\n');
					return (1);
				}
			}
			piece->x++;
		}
		piece->y++;
	}
	return (0);
}

int		take_piece_right(t_data *data, t_piece *piece)
{
	piece->y = piece->heightpiece - 1;
	while (piece->y >= 0)
	{
		piece->x = piece->widthpiece - 1;
		while (piece->x >= 0)
		{
			if (piece->piece[piece->y][piece->x] == '*')
			{
				if (ft_look_for_place(data, piece))
				{
					ft_putnbr(data->y - piece->y);
					ft_putchar(' ');
					ft_putnbr(data->x - piece->x);
					ft_putchar('\n');
					return (1);
				}
			}
			piece->x--;
		}
		piece->y--;
	}
	return (0);
}

t_piece	*take_piece(t_piece *piece)
{
	char	*line;
	int		i;
	int		x;

	piece->x = 0;
	i = piece->heightpiece;
	if (!(piece->piece = malloc(sizeof(char*) * piece->heightpiece + 1)))
		return (NULL);
	while (i)
	{
		x = piece->x;
		ft_get_next_line(0, &line);
		if (!(piece->piece[x] = malloc(sizeof(char) * piece->widthpiece + 1)))
			return (NULL);
		piece->piece[piece->x] = line;
		piece->x++;
		i--;
	}
	return (piece);
}

t_piece	*read_piece(t_piece *piece, t_data *data)
{
	while (data->line[0] != 'P')
		ft_get_next_line(0, &data->line);
	piece->heightpiece = ft_atoi(&data->line[6]);
	piece->widthpiece = ft_atoi(&data->line[8]);
	take_piece(piece);
	return (piece);
}
