/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:47:52 by tchardat          #+#    #+#             */
/*   Updated: 2020/06/21 17:54:33 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_get_numplayer(t_data *data)
{
	char	*line;

	ft_get_next_line(0, &line);
	data->playernum = ft_atoi(&line[10]);
}

void	ft_get_letter(t_data *data)
{
	if (data->playernum == 1)
		data->letter = 'O';
	else
		data->letter = 'X';
}

t_data	*ft_get_h_and_w(t_data *data)
{
	char *line;

	ft_putchar_fd('t', 2);
	ft_get_next_line(0, &line);
	ft_putstr_fd(line, 2);
	ft_putchar_fd('t', 2);
	ft_putstr_fd(line, 2);
	data->height = ft_atoi(&line[8]);
	data->width = ft_atoi(&line[11]);
//	data->first = 1;
	return (data);
}

void	ft_get_info(t_data *data)
{
	ft_get_numplayer(data);
	ft_get_letter(data);
	ft_get_h_and_w(data);
	data->aggr = 1;
}

/*static void		init_struct(t_data *data, t_piece *piece)
{
	data->playernum = 0;
	data->height = 0;
	data->width = 0;
	piece->heightpiece = 0;
	piece->widthpiece = 0;
	piece->x = 0;
	piece->y = 0;
	piece->v_h = 0;
}*/

int		main(void)
{
	t_data	data;
	t_piece	piece;
	char	*ret;
	int	i;

	i = 0;
	data.first = 0;
	reset_data(&data);
	reset_piece(&piece);
	ft_get_info(&data);
	/*ft_putnbr_fd(data.playernum, 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(data.height, 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(data.width, 2);
	ft_putchar_fd('\n', 2);*/
//	ft_putchar_fd('a', 2);
	while (1)
	{
//		if (i == 0)
//		{*/
//			i++;
			/*ret = */
			if (player1(&data, &piece) == -1)
				return (-1);
/*			ft_putchar_fd(piece.v_h, 2);
			ft_putchar_fd('\n', 2);
			ft_putchar_fd(data.letter, 2);
			ft_putchar_fd('\n', 2);*/
/*			ft_putchar_fd('\n', 2);
			ft_putchar_fd('\n', 2);
			ft_putstr_fd(ret, 2);
			ft_putchar_fd('\n', 2);
			ft_putchar_fd('\n', 2);
			ft_putendl(ret);
			ft_putnbr_fd(piece.xadd, 2);
			ft_putnbr_fd(piece.xadd, 2);
			ft_putnbr_fd(piece.xadd, 2);*/
			reset_data(&data);
			reset_piece(&piece);
			ft_putnbr_fd(piece.xadd, 2);
			ft_putnbr_fd(piece.xadd, 2);
			ft_putnbr_fd(piece.xadd, 2);
			ft_putnbr_fd(piece.xadd, 2);
			ft_putnbr_fd(piece.xadd, 2);
			ft_putnbr_fd(piece.xadd, 2);
			ft_putnbr_fd(piece.xadd, 2);
			ft_putnbr_fd(piece.xadd, 2);
			ft_putnbr_fd(piece.xadd, 2);
			ft_putnbr_fd(piece.xadd, 2);
			ft_putnbr_fd(piece.xadd, 2);
			ft_putchar_fd('\n', 2);
			data.first = 1;
//			ft_strdel(&ret);
//		}
	}
	return (1);
}
