/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 21:32:34 by tchardat          #+#    #+#             */
/*   Updated: 2020/04/13 21:32:35 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst2;
	unsigned char	*src2;
	size_t			i;
	unsigned char	c2;

	i = 0;
	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	c2 = (unsigned char)c;
	while (i < n)
	{
		dst2[i] = src2[i];
		if (src2[i] == c2)
			return ((unsigned char *)dst2 + i + 1);
		i++;
	}
	return (NULL);
}
