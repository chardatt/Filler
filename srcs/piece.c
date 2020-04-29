/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 17:18:16 by tchardat          #+#    #+#             */
/*   Updated: 2020/04/29 16:58:51 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_piece	*take_piece(t_piece *piece);

t_piece	*read_piece(t_piece *piece)
{
	char	*line = "MERDE";

	while (line[0] != 'P')
	{
//		ft_putchar_fd('a', 2);
		ft_get_next_line(0, &line);
	}
//	ft_putchar_fd('a', 2);
	piece->heightpiece = ft_atoi(&line[6]);
	piece->widthpiece =	ft_atoi(&line[8]);
	ft_putnbr_fd(piece->heightpiece, 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(piece->widthpiece, 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);
	take_piece(piece);
	piece->workedp = ft_sort(*piece);
	ft_putstr_fd(piece->workedp, 2);
	ft_putchar_fd('\n', 2);
	return (piece);
}

t_piece	*take_piece(t_piece *piece)
{
	char	*line;
	char	*endline;
	int		i;

	endline = "\n\0";
	i = piece->heightpiece;
	while (i)
	{
		ft_get_next_line(0, &line);
		if (i == piece->heightpiece)
			piece->piece = line;
		else
			piece->piece = ft_strjoin(piece->piece, line);
		piece->piece = ft_strjoin(piece->piece, endline);
		i--;
	}
	ft_putchar_fd('\n', 2);
	ft_putstr_fd(piece->piece, 2);
	return (piece);
}
