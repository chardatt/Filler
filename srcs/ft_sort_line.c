/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 16:46:31 by tchardat          #+#    #+#             */
/*   Updated: 2020/05/05 16:01:10 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

char	*destroy_fline(t_piece piece, int dstr)
{
	int		i;
	char	*str;
	char	*src;

	if (dstr == 0)
		src = piece.piece;
	if (dstr == 1)
		src = piece.workedp;
	str = ft_strnew((piece.heightpiece - 1) * piece.widthpiece + 1);
	i = 0;
	while (src[i + piece.widthpiece + 1])
	{
		str[i] = src[i + piece.widthpiece + 1];
		i++;
	}
	return (str);
}

char	*destroy_lline(t_piece piece, int dstr)
{
	int		i;
	char	*str;
	char	*src;

	if (dstr == 0)
		src = piece.piece;
	if (dstr == 1)
		src = piece.workedp;
	str = ft_strnew((piece.heightpiece - 1) * piece.widthpiece + 1);
	i = ft_strlen(piece.piece) - piece.widthpiece - 2;
	while (src[i])
	{
		str[i] = src[i];
		i--;
	}
	return (str);
}

char	*ft_sort_line2(t_piece piece, int dstr, int first, int block, int i)
{
	while (piece.piece[i])
	{
		if (piece.piece[i] == '*')
			block = 1;
		if (block == 1)
			first = 1;
		if (piece.piece[i] == '\n')
		{
			if (block == 0)
			{
				ft_putnbr_fd(first, 2);
				if (first == 0)
					piece.workedp = destroy_fline(piece, dstr);
				if (first == 1)
					piece.workedp = destroy_lline(piece, dstr);
				dstr = 1;
			}
			block = 0;
		}
		i++;
	}
	return (piece.workedp);
}

char	*ft_sort_line(t_piece piece)
{
	int		i;
	int		block;
	int		first;
	int		dstr;

	dstr = 0;
	first = 0;
	block = 0;
	i = 0;
	piece.workedp = ft_sort_line2(piece, dstr, first, block, i);
/*	while (piece.piece[i])
	{
		if (piece.piece[i] == '*')
			block = 1;
		if (block == 1)
			first = 1;
		if (piece.piece[i] == '\n')
		{
			if (block == 0)
			{
				if (first == 0)
					piece.workedp = destroy_fline(piece, dstr);
				if (first == 1)
					piece.workedp = destroy_lline(piece, dstr);
				dstr = 1;
			}
			block = 0;
		}
		i++;
	}*/
	if (piece.workedp == NULL)
		return (piece.piece);
	return (piece.workedp);
}
