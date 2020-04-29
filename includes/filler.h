/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 17:24:34 by tchardat          #+#    #+#             */
/*   Updated: 2020/04/29 16:53:02 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_data
{
	int		height;
	int		width;
	int		playernum;
	char	letter;
}				t_data;

typedef struct	s_piece
{
	int		heightpiece;
	int		widthpiece;
	int		x;
	int		y;
	char	*piece;
	char	*workedp;
}				t_piece;

char	*ft_sort(t_piece piece);
t_piece	*read_piece(t_piece *piece);
char	**player1(t_data *data, t_piece *piece);
#endif
