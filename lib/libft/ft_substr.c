/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:13:09 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/04/28 23:46:33 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*sol;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_calloc(1, 1));
	if (len > slen)
		len = slen - start;
	sol = (char *)ft_calloc(sizeof(*s), (len + 1));
	if (!sol)
		return (NULL);
	i = 0;
	while (s[start] && (i < len) && (start < slen))
	{
		sol[i] = s[start];
		start++;
		i++;
	}
	return (sol);
}
