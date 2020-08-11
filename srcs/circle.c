/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 23:34:20 by tchardat          #+#    #+#             */
/*   Updated: 2020/07/12 17:34:59 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	ft_diff_x(t_data *data, char ennemyletter)
{
	int	x;
	int y;
	int	x1;
	int y1;

	x = 0;
	x1 = 0;
	while (data->map[x] && data->map[x][y] != data->letter)
	{
		y = 0;
		while (data->map[x][y] && data->map[x][y] != data->letter)
			y++;
		x++;
	}
	while (data->map[x1] && data->map[x1][y1] != ennemyletter)
	{
		y1 = 0;
		while (data->map[x1][y1] && data->map[x1][y1] != ennemyletter)
			y1++;
		x1++;
	}
	return (x - x1);
}

int	ft_diff_y(t_data *data, char ennemyletter)
{
	int	x;
	int y;
	int	x1;
	int y1;

	x = 0;
	x1 = 0;
	while (data->map[x] && data->map[x][y] != data->letter)
	{
		y = 0;
		while (data->map[x][y] && data->map[x][y] != data->letter)
			y++;
		x++;
	}
	while (data->map[x1] && data->map[x1][y1] != ennemyletter)
	{
		y1 = 0;
		while (data->map[x1][y1] && data->map[x1][y1] != ennemyletter)
			y1++;
		x1++;
	}
	return (y - y1);
}

int	ft_cirlce_ennemy(t_data *data, t_piece *piece)
{
	char	ennemyletter;
	int		diffx;
	int		diffy;

	if (data->letter == 'O')
		ennemyletter = 'X';
	else
		ennemyletter = 'O';
	ft_putchar_fd('j', 2);
	diffx = ft_diff_x(data, ennemyletter);
	ft_putchar_fd('j', 2);
	diffy = ft_diff_y(data, ennemyletter);
	ft_putchar_fd('j', 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(diffx, 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(diffy, 2);
	if (diffx != 0 || diffy != 0)
	{
		ft_putchar_fd('f', 2);
		if (diffx > 0)
			place_left(data, piece);
		else if (diffy > 0)
			place_top(data, piece);
		else if (diffy < 0)
			place_down(data, piece);
		else if (diffx < 0)
			place_right(data, piece);
		else
			data->aggr = 0;
		//diff de x et y reçu, maintenant comment gérer cette donnée?
	}
	return (0);
}
