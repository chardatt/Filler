/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 17:18:16 by tchardat          #+#    #+#             */
/*   Updated: 2020/06/01 16:32:53 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*int		v_piece(t_piece piece)
{
	int	i;
	int j;
	int count;
	int max;

	max = 0;
	count = 0;
	i = 0;
	j = piece.widthpiece + 1;
	while (piece.piece[i])
	{
		if (piece.piece[i] == '*')
		{
			while (piece.piece[i + j] == '*')
			{
				j += piece.widthpiece + 1;
				count++;
			}
			if (max < count)
				max = count;
		}
		i++;
	}
	return (max);
}

int		v_h_piece(t_piece piece)
{
	int	i;
	int	h;
	int	j;
	int v;

	i = 0;
	j = 0;
	h = 0;
	while (piece.piece[i])
	{
		if (piece.piece[i] != '*')
		{
			if (h > j)
				j = h;
			h = 0;
		}
		if (piece.piece[i] == '*')
			h++;
		i++;
	}
	v = v_piece(piece);
	if (j > v)
		return (0);
	return (1);
}*/

t_piece	*take_piece(t_piece *piece)
{
	char	*line;
//	char	*endline;
	int		i;

//	endline = "\n\0";
	piece->x = 0;
	i = piece->heightpiece;
	if (!(piece->piece = malloc(sizeof(char*) * piece->heightpiece + 1)))
		return (NULL);
	piece->piece[piece->heightpiece + 1] = "\0";
	while (i)
	{
//		ft_putchar_fd('a', 2);
		ft_get_next_line(0, &line);
		if (!(piece->piece[piece->x] = malloc(sizeof(char) * piece->widthpiece + 1)))
			return (NULL);
		piece->piece[piece->x] = line;
		piece->x++;
/*		if (i == piece->heightpiece)
			piece->piece = line;
		else
			piece->piece = ft_strjoin(piece->piece, line);
		piece->piece = ft_strjoin(piece->piece, endline);
*/		i--;
	}
	return (piece);
}

t_piece	*read_piece(t_piece *piece, t_data *data)
{
	while (data->line[0] != 'P')
	{
		ft_putchar_fd('a', 2);
		ft_get_next_line(0, &data->line);
	}
//	ft_putchar_fd('a', 2);
	piece->heightpiece = ft_atoi(&data->line[6]);
	piece->widthpiece =	ft_atoi(&data->line[8]);
	ft_putnbr_fd(piece->heightpiece, 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(piece->widthpiece, 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);
	take_piece(piece);
//	ft_printtab(piece->piece);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('b', 2);
/*	piece->v_h = v_h_piece(*piece);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(piece->v_h, 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);*/
	return (piece);
}
