/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_for_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 15:05:35 by tchardat          #+#    #+#             */
/*   Updated: 2020/06/22 17:46:28 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/* Problème sur superpose_adverse
** return 0, pourquoi? à régler sinon ne doit pas être posé.
*/

int		check_place(t_data *data, t_piece *piece, int x, int y)
{
//	ft_putnbr_fd(data->widht, 2);
	if (x > data->width || x < 0)
	{
		ft_putchar_fd('W', 2);
		return (0);
	}
//	ft_putnbr_fd(data->widht, 2);
	if (y > data->height || y < 0)
	{
		ft_putchar_fd('V', 2);
		return (0);
	}
//	ft_putnbr_fd(data->widht, 2);
	if (x + piece->widthpiece > data->width)
	{
		ft_putchar_fd('U', 2);
		return (0);
	}
//	ft_putnbr_fd(data->widht, 2);
	if (y + piece->heightpiece > data->height)
	{
		ft_putchar_fd('T', 2);
		return (0);
	}
	return (1);
}

int		check_superpose(t_data *data, t_piece *piece, int x, int y)
{
	int		i;
	int		j;
	int		tmpx;
	int		compt;

	i = -1;
	tmpx = x;
	compt = 0;
	while (++i < piece->heightpiece)
	{
		j = -1;
		x = tmpx;
		while (++j < piece->widthpiece)
		{
			if (data->playernum == 1)
				if (piece->piece[i][j] == '*' && data->map[y][x] == 'O')
					compt++;
			if (data->playernum == 2)
				if (piece->piece[i][j] == '*' && data->map[y][x] == 'X')
					compt++;
			x++;
		}
		y++;
	}
	return ((compt > 1) ? 0 : 1);
}

int		check_superpose_adverse(t_data *data, t_piece *piece, int x, int y)
{
	int		i;
	int		j;
	int		tmpx;

	i = 0;
	tmpx = x;
	while (i < piece->heightpiece)
	{
		j = 0;
		x = tmpx;
		while (j < piece->widthpiece)
		{
			if (data->playernum == 1)
				if (piece->piece[i][j] == '*' && data->map[y][x] == 'X')
					return (0);
			if (data->playernum == 2)
				if (piece->piece[i][j] == '*' && data->map[y][x] == 'O')
					return (0);
			j++;
			x++;
		}
		i++;
		y++;
	}
	return (1);
}

int		ft_look_for_place(t_data *data, t_piece *piece)
{
	int		x;
	int		y;

	x = data->x - piece->x;
	y = data->y - piece->y;
	if (check_place(data, piece, x, y) == 0)
	{
		ft_putchar_fd('5', 2);
		return (0);
	}
	if (check_superpose(data, piece, x, y) == 0)
	{
		ft_putchar_fd('6', 2);
		return (0);
	}
	if (check_superpose_adverse(data, piece, x, y) == 0)
	{
		ft_putchar_fd('7', 2);
		return (0);
	}
	return (1);
}
