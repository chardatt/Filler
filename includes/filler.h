/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 17:24:34 by tchardat          #+#    #+#             */
/*   Updated: 2020/06/01 16:14:52 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <fcntl.h>

typedef struct	s_data
{
	int		height;
	int		width;
	int		playernum;
	int		x;
	int		y;
	char	letter;
	char	*line;
	char	**map;
}				t_data;

typedef struct	s_piece
{
	int		heightpiece;
	int		widthpiece;
	int		x;
	int		y;
	int		h;
	int		v;
	char	v_h;
	char	**piece;
}				t_piece;

char	*ft_sort_line(t_piece piece);
char	*ft_sort_column(t_piece piece);
t_piece	*read_piece(t_piece *piece, t_data *data);
char	*player1(t_data *data, t_piece *piece);
t_data	*read_map(t_data *data);
#endif
