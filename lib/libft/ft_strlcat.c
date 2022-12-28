/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:06:22 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/09/26 19:33:57 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while ((dst[i] != '\0') && (i < dstsize))
		i++;
	while ((dstsize > (i + j + 1)) && (src[j] != '\0'))
	{
		dst[i + j] = ((char *)src)[j];
		j++;
	}
	if ((dstsize != 0) && (i < dstsize))
		dst[i + j] = '\0';
	return (ft_strlen(src) + i);
}
