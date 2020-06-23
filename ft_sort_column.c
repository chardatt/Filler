/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_column.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 14:46:13 by tchardat          #+#    #+#             */
/*   Updated: 2020/05/05 15:52:22 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

char	*cut_column(t_piece piece, int j)
{
	int		i;
	int		f;
	char	*str;

	f = 0;
	i = 0;
	ft_putnbr_fd(j, 2);
	ft_putchar_fd('\n', 2);
	str = ft_strnew(piece.heightpiece * piece.widthpiece + 1);
	while (piece.workedp[i + f])
	{
		if (i + f != j)
		{
			str[i] = piece.workedp[i + f];
			ft_putchar_fd(str[i], 2);
		}
		if (piece.workedp[i] == '\n')
			j += piece.widthpiece + 1;
		if (i + f == j)
			f++;
		else
			i++;
	}
	ft_putchar_fd('\n', 2);
	return (str);
}

char	*ft_select_line(t_piece piece, int i)
{
	int	compheight;
	int j;

	j = i;
	compheight = 1;
	while (piece.workedp[i + 1 + piece.widthpiece] && piece.workedp[i] == '.')
	{
		i += piece.widthpiece + 1;
		compheight++;
	}
	if (compheight == piece.heightpiece)
	{
		if (cut_column(piece, j) != NULL)
			return (cut_column(piece, j));
		else
			return (piece.workedp);
	}
	return (piece.workedp);
}

char	*ft_sort_column(t_piece piece)
{
	int i;

	i = 0;
	while (i <= piece.widthpiece)
	{
		piece.workedp = ft_select_line(piece, i);
		i++;
	}
	ft_putstr_fd(piece.workedp, 2);
	return (piece.workedp);
}
