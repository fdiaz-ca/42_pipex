/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:31:44 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/10/29 20:20:23 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)

{
	char	*p;
	char	*l;
	int		i;

	p = (char *)s;
	l = 0;
	i = 0;
	while (p[i] != '\0')
	{
		if ((unsigned char)p[i] == (unsigned char)c)
			l = &p[i];
		i++;
	}
	if ((unsigned char)c == '\0')
		return (&p[i]);
	return (l);
}
