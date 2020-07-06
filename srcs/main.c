/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:47:52 by tchardat          #+#    #+#             */
/*   Updated: 2020/07/06 19:29:41 by tchardat         ###   ########.fr       */
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

	ft_get_next_line(0, &line);
	data->height = ft_atoi(&line[8]);
	data->width = ft_atoi(&line[11]);
	return (data);
}

void	ft_get_info(t_data *data)
{
	ft_get_numplayer(data);
	ft_get_letter(data);
	ft_get_h_and_w(data);
}

int		main(void)
{
	t_data	data;
	t_piece	piece;

	data.first = 0;
	reset_data(&data);
	reset_piece(&piece);
	ft_get_info(&data);
	while (1)
	{
		if (player1(&data, &piece) == -1)
		{
			ft_putnbr(0);
			ft_putchar(' ');
			ft_putnbr(0);
			ft_putchar('\n');
			return (-1);
		}
		reset_data(&data);
		reset_piece(&piece);
		data.first = 1;
	}
	return (1);
}
