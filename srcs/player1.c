/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 17:07:32 by tchardat          #+#    #+#             */
/*   Updated: 2020/06/01 17:06:48 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	check_v(t_piece	*piece)
{
	int	block;

	piece->x = 0;
	piece->y = 0;
	while (piece->piece[piece->y][piece->x])
	{
		ft_putchar_fd('\n', 2);
		ft_putchar_fd('c', 2);
		ft_putchar_fd('\n', 2);
		block = 0;
		while (piece->piece[piece->y] && piece->y < piece->heightpiece)
		{
			ft_putchar_fd('\n', 2);
			ft_putchar_fd('z', 2);
			ft_putchar_fd('\n', 2);
			if (piece->piece[piece->y][piece->x] == '*')
				block++;
			if (piece->piece[piece->y][piece->x] == '.')
			{
				if (block > piece->v)
					piece->v = block;
				block = 0;
			}
			ft_putchar_fd('\n', 2);
			ft_putchar_fd('z', 2);
			piece->y++;
			ft_putchar_fd('z', 2);
		}
		piece->y = 0;
		if (block > piece->v)
			piece->v = block;
		piece->x++;
	}
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(piece->v, 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);
}

void	check_h(t_piece *piece)
{
	int	block;

	piece->y = 0;
	while (piece->piece[piece->y] && piece->y < piece->heightpiece)
	{
		ft_putchar_fd('a', 2);
		block = 0;
		piece->x = 0;
		ft_putchar_fd('a', 2);
		while (piece->piece[piece->y][piece->x])
		{
			ft_putchar_fd('b', 2);
			if (piece->piece[piece->y][piece->x] == '*')
				block++;
			ft_putchar_fd('b', 2);
			if (piece->piece[piece->y][piece->x] == '.')
			{
				ft_putchar_fd('\n', 2);
				ft_putchar_fd('c', 2);
				if (block > piece->h)
					piece->h = block;
				block = 0;
				ft_putchar_fd('c', 2);
				ft_putchar_fd('\n', 2);
			}
			ft_putchar_fd('b', 2);
			piece->x++;
			ft_putchar_fd('b', 2);
		}
		ft_putchar_fd('a', 2);
		if (block > piece->h)
			piece->h = block;
		ft_putchar_fd('m', 2);
		piece->y++;
		ft_putchar_fd('n', 2);
		ft_putchar_fd('\n', 2);
		ft_putnbr_fd(piece->y, 2);
		ft_putchar_fd('\n', 2);
	}
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(piece->h, 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);
}

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
	ft_putchar_fd('j', 2);
	while (data->map[y] && data->map[y][x] != data->letter)
	{
		ft_putchar_fd('k', 2);
		x = 0;
		y++;
		while (data->map[y][x] && data->map[y][x] != data->letter)
		{
			ft_putchar_fd('l', 2);
			x++;
		}
		ft_putchar_fd('\n', 2);
	}
	check_h(piece);
	check_v(piece);
//	if (piece->v > piece->h)
//		piece->v_h = 'v';
//	else
//		piece->v_h = 'h';
/*	while (piece->piece[piece->y])
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
	}*/
/*	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('a', 2);
	ft_putnbr_fd(piece->h, 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);*/
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
