/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:29:34 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/11/02 13:33:00 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		i;
	int		start;
	int		end;

	if (!s1)
		return (NULL);
	end = ft_strlen(s1);
	start = 0;
	while ((start < end) && ft_strchr(set, s1[start]))
		start++;
	while ((start < end) && ft_strchr(set, s1[end - 1]))
		end--;
	p = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (start < end)
		p[i++] = s1[start++];
	p[i] = '\0';
	return (p);
}
