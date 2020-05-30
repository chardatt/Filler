/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 17:07:32 by tchardat          #+#    #+#             */
/*   Updated: 2020/05/30 21:36:19 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

char	*place_piece(t_data *data, t_piece *piece)
{
	int		x;
	int		block;
	int		y;
	char	*ret;

	x = 0;
	y = 0;
	piece->y = 0;
	piece->h = 0;
	while (data->map[y] && data->map[y][x] != data->letter)
	{
		x = 0;
		y++;
		while (data->map[y][x] && data->map[y][x] != data->letter)
		{
			x++;
		}
	}
	while (piece->piece[piece->y])
	{
		block = 0;
		piece->x = 0;
		while (piece->piece[piece->y][piece->x])
		{
			if (piece->piece[piece->y][piece->x] == '*')
				block++;
			if (piece->piece[piece->y][piece->x] == '.')
			{
				if (block > piece->h)
					piece->h = block;
				block = 0;
			}
			piece->x++;
		}
		if (block > piece->h)
			piece->h = block;
		piece->y++;
	}
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(piece->h, 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);
	ret = ft_strjoin(ft_itoa(y), " ");
	ret = ft_strjoin(ret, ft_itoa(x));
	ret = ft_strjoin(ret, "\n");
	return (ret);
}

char	*player1(t_data *data, t_piece *piece)
{
	char	*ret;

	
//	ft_putchar_fd('a', 2);
	data = read_map(data);
	piece = read_piece(piece, data);
	ft_putchar_fd('b', 2);
	ret = place_piece(data, piece);
/*	ft_putchar_fd('a', 2);
	ft_putnbr_fd(piece->heightpiece, 2);
	ft_putchar_fd('a', 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('a', 2);
	ft_putnbr_fd(piece->widthpiece, 2);
	ft_putchar_fd('a', 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('a', 2);*/
	return (ret);
}
