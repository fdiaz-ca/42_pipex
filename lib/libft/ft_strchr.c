/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:39:14 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/10/29 20:19:28 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	int		i;

	p = (char *)s;
	i = 0;
	while (p[i])
	{
		if ((unsigned char)p[i] == (unsigned char)c)
			return (&p[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return (&p[i]);
	return (NULL);
}
