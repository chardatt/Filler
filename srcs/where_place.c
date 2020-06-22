/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 12:47:30 by tchardat          #+#    #+#             */
/*   Updated: 2020/06/19 19:01:58 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	gotoendcolumn(t_piece *piece)
{
	while (piece->piece[piece->yadd + 1][piece->xadd] == '*')
		piece->yadd++;
}

void	gotoendline(t_piece *piece)
{
	while (piece->piece[piece->yadd][piece->xadd] == '*')
		piece->xadd++;
}

void	where_h(t_piece *piece)
{
	int	j;

	j = 0;
	piece->y = 0;
	while (piece->piece[piece->y])
	{
		piece->x = 0;
		while (piece->piece[piece->y][piece->x])
		{
			if (piece->piece[piece->y][piece->x] == '*')
				j++;
			if (j == piece->h)
			{
				while (piece->piece[piece->y][piece->x - 1] == '*' && piece->x > 0)
					piece->x--;
				piece->xadd = piece->x;
				piece->yadd = piece->y;
				return ;
			}	
			piece->x++;
		}
		j = 0;
		piece->y++;
	}
}

void	where_v(t_piece *piece)
{
	int	j;

/*	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(piece->v, 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);*/
	piece->x = 0;
	piece->y = 0;
	j = 0;
//	ft_putchar_fd('z', 2);
//	ft_putchar_fd('\n', 2);
	while (piece->piece[piece->y][piece->x])
	{
//		ft_putchar_fd('y', 2);
//		ft_putchar_fd('\n', 2);
		while (piece->piece[piece->y] && piece->y < piece->heightpiece)
		{
//			ft_putchar_fd('x', 2);
//			ft_putchar_fd('\n', 2);
//			ft_putchar_fd(piece->piece[piece->y][piece->x], 2);
			if (piece->piece[piece->y][piece->x] == '*')
				j++;
			if (j == piece->v)
			{		
//				ft_putchar_fd('w', 2);
//				ft_putchar_fd('\n', 2);
				while (piece->piece[piece->y][piece->x] == '*' && piece->y > 0)
					piece->y--;
				piece->xadd = piece->x;
				piece->yadd = piece->y;
				return ;
			}
/*			ft_putchar_fd('\n', 2);
			ft_putchar_fd('\t', 2);
			ft_putnbr_fd(j, 2);
			ft_putchar_fd('\n', 2);*/
			piece->y++;
		}
		j = 0;
		piece->y = 0;
		piece->x++;
	}
/*	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\t', 2);
	ft_putnbr_fd(j, 2);
	ft_putchar_fd('\n', 2);*/
}

void	ft_where_place(t_piece *piece, t_data *data)
{
	if (piece->v_h == 'h')
	{
		ft_putchar_fd('n', 2);
		where_h(piece);
	}
	else
	{
		ft_putchar_fd('m', 2);
		where_v(piece);
	}
	if (data->aggr == 0 && piece->v_h == 'v')
	{
		ft_putchar_fd('o', 2);
		gotoendcolumn(piece);
	}
	else if (data->aggr == 0 && piece->v_h == 'h')
	{
		ft_putchar_fd('p', 2);
		gotoendline(piece);
	}
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(piece->xadd, 2);
	ft_putchar_fd('\t', 2);
	ft_putnbr_fd(piece->yadd, 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);
}
