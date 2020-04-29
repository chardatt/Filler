/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchardat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 21:40:51 by tchardat          #+#    #+#             */
/*   Updated: 2020/04/13 21:40:52 by tchardat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		len--;
		i++;
	}
	if (len < 0)
		len = 0;
	if ((str = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (j < len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
