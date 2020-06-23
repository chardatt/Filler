/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 17:07:32 by tchardat          #+#    #+#             */
/*   Updated: 2020/06/23 16:42:46 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*void	check_v(t_piece	*piece)
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
//			ft_putchar_fd('z', 2);
		}
		piece->y = 0;
		if (block > piece->v)
			piece->v = block;
		piece->x++;
	}
//	ft_putchar_fd('\n', 2);
//	ft_putchar_fd('\n', 2);
//	ft_putnbr_fd(piece->v, 2);
//	ft_putchar_fd('\n', 2);
//	ft_putchar_fd('\n', 2);
}

void	check_h(t_piece *piece)
{
	int	block;

	piece->y = 0;
	while (piece->piece[piece->y] && piece->y < piece->heightpiece)
	{
//		ft_putchar_fd('a', 2);
		block = 0;
		piece->x = 0;
//		ft_putchar_fd('a', 2);
		while (piece->piece[piece->y][piece->x])
		{
//			ft_putchar_fd('b', 2);
			if (piece->piece[piece->y][piece->x] == '*')
				block++;
//			ft_putchar_fd('b', 2);
			if (piece->piece[piece->y][piece->x] == '.')
			{
//				ft_putchar_fd('\n', 2);
//				ft_putchar_fd('c', 2);
				if (block > piece->h)
					piece->h = block;
				block = 0;
//				ft_putchar_fd('c', 2);
//				ft_putchar_fd('\n', 2);
			}
//			ft_putchar_fd('b', 2);
			piece->x++;
//			ft_putchar_fd('b', 2);
		}
//		ft_putchar_fd('a', 2);
		if (block > piece->h)
			piece->h = block;
//		ft_putchar_fd('m', 2);
		piece->y++;
//		ft_putchar_fd('n', 2);
//		ft_putchar_fd('\n', 2);
//		ft_putnbr_fd(piece->y, 2);
//		ft_putchar_fd('\n', 2);
	}
//	ft_putchar_fd('\n', 2);
//	ft_putchar_fd('\n', 2);
//	ft_putnbr_fd(piece->h, 2);
//	ft_putchar_fd('\n', 2);
//	ft_putchar_fd('\n', 2);
}*/

/* TAF A FAIRE SUR PLACE PIECE
** Le rendre modulable pour continuer la partie normalement en fonction du player
** Le rendre adaptable à la strat et le faire contourner les pièces ennemis
** faire une fonction "la piece peut elle être posé?" 
*/

int		place_piece(t_data *data, t_piece *piece)
{
	int		x;
	int		block;
	int		y;
	char	*ret;

	x = data->width - 1;
	y = data->height - 1;
//	piece->y = 0;
//	piece->h = 0;
	ft_putchar_fd('j', 2);
//	check_h(piece);
//	check_v(piece);
//	if (piece->h >= piece->v)
//		piece->v_h = 'h';
//	else
//		piece->v_h = 'v';
//	ft_where_place(piece, data);

	ft_strategy(data, piece);

/*	while (data->map[y] && (data->map[y][x] != data->letter))
	{
		ft_putchar_fd('k', 2);
		x = data->width - 1;
		y--;
		while (data->map[y][x] && (data->map[y][x] != data->letter)) 
		{
			ft_putchar_fd('l', 2);
			x--;
		}
		ft_putchar_fd('\n', 2);
	}
*/
	
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\t', 2);
	ft_putchar_fd('\t', 2);
	ft_putchar_fd('<', 2);
	ft_putchar_fd('\n', 2);

/* Tester avec un x++ ou un y++
*/
//	if (ft_look_for_place(data, piece, x, y) == 0)
//		return (-1);

/*	check_h(piece);
	check_v(piece);
	if (piece->h >= piece->v)
		piece->v_h = 'h';
	else
		piece->v_h = 'v';
	if (piece->v > piece->h)
		piece->v_h = 'v';
	else
		piece->v_h = 'h';
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
	ft_putchar_fd('a', 2);
	ft_putnbr_fd(piece->h, 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);
	ret = ft_strjoin(ft_itoa(y - piece->yadd), " ");
	ret = ft_strjoin(ret, ft_itoa(x - piece->xadd));
	ret = ft_strjoin(ret, "\n");
	ft_putnbr(y - piece->yadd);
	ft_putchar(' ');
	ft_putnbr(x - piece->xadd);
	ft_putchar('\n');*/
	return (0);
//	ret = ft_strjoin(ret, "\0");
//	return (ret);
}

int		player1(t_data *data, t_piece *piece)
{
	char	*ret;

	data = read_map(data);
	piece = read_piece(piece, data);
	if (place_piece(data, piece) == -1)
		return (-1);
	return (0);
}
