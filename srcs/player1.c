/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 17:07:32 by tchardat          #+#    #+#             */
/*   Updated: 2020/05/29 17:15:11 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

char	*place_piece(t_data *data, t_piece *piece)
{
	int		x;
	int		y;
	char	*ret;

	x = 0;
	y = 0;
	while (data->map[y] && data->map[y][x] != data->letter)
	{
		x = 0;
		y++;
		while (data->map[y][x] && data->map[y][x] != data->letter)
		{
			x++;
		}
	}
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
