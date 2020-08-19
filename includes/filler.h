/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 17:24:34 by tchardat          #+#    #+#             */
/*   Updated: 2020/08/19 17:24:02 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_data
{
	int			height;
	int			width;
	int			playernum;
	int			first;
	int			x;
	int			y;
	int			aggr;
	char		letter;
	char		*line;
	char		**map;
}				t_data;

typedef struct	s_piece
{
	int			heightpiece;
	int			widthpiece;
	int			x;
	int			y;
	int			count;
	char		**piece;
}				t_piece;

char			*ft_sort_line(t_piece piece);
char			*ft_sort_column(t_piece piece);
t_piece			*read_piece(t_piece *piece, t_data *data);
int				player1(t_data *data, t_piece *piece);
t_data			*read_map(t_data *data);
void			ft_where_place(t_piece *piece, t_data *data);
void			reset_piece(t_piece *piece);
void			reset_data(t_data *data);
t_data			*ft_get_h_and_w(t_data *data);
int				ft_look_for_place(t_data *data, t_piece *piece);
int				ft_strategy(t_data *data, t_piece *piece);
int				take_piece_right(t_data *data, t_piece *piece);
int				first_height(t_data *data, char c);
int				take_piece_left(t_data *data, t_piece *piece);
int				last_column(t_data *data, char c);
int				ft_strat2(t_data *data, t_piece *piece);
int				ft_strat1(t_data *data, t_piece *piece);
int				place_down(t_data *data, t_piece *piece);
int				place_top(t_data *data, t_piece *piece);
int				place_left(t_data *data, t_piece *piece);
int				place_right(t_data *data, t_piece *piece);
#endif
