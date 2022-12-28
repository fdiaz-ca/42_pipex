/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:32:35 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/04/28 23:32:49 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*c1;
	char	*c2;

	c1 = (char *)s1;
	c2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (c1[i] != c2[i])
			return ((unsigned char)c1[i] - (unsigned char)c2[i]);
		i++;
	}
	return (0);
}
