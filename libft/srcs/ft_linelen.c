/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linelen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 21:31:02 by tchardat          #+#    #+#             */
/*   Updated: 2020/04/13 21:31:03 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_linelen(const char *s)
{
	size_t count;

	count = 0;
	if (!s)
		return (-1);
	while (s[count] && s[count] != '\n')
		count++;
	return (count);
}
