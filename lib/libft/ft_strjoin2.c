/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:23:11 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/11/11 03:54:11 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin2(char const *s1, char const *s2)
{
	char	*p;
	int		i;
	int		j;

	p = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!p)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
		p[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		p[j++] = s2[i++];
	p[j] = '\0';
	return (p);
}
