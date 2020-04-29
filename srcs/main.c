/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:47:52 by tchardat          #+#    #+#             */
/*   Updated: 2020/04/29 17:09:05 by tchardat         ###   ########.fr       */
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

void	ft_get_h_and_w(t_data *data)
{
	char *line;

	ft_get_next_line(0, &line);
	data->height = ft_atoi(&line[8]);
data->width = ft_atoi(&line[11]);
}

void	ft_get_info(t_data *data)
{
	ft_get_numplayer(data);
	ft_get_letter(data);
	ft_get_h_and_w(data);
}

static void		init_struct(t_data *data, t_piece *piece)
{
	data->playernum = 0;
	data->height = 0;
	data->width = 0;
	piece->heightpiece = 0;
	piece->widthpiece = 0;
	piece->x = 0;
	piece->y = 0;
	piece->workedp = NULL;
}

int		main(void)
{
	t_data data;
	t_piece	piece;

	init_struct(&data, &piece);
	ft_get_info(&data);
	/*ft_putnbr_fd(data.playernum, 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(data.height, 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(data.width, 2);
	ft_putchar_fd('\n', 2);*/
//	ft_putchar_fd('a', 2);
		player1(&data, &piece);
	write(0, "0 0\n", 4);
}
