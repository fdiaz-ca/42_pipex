/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:50:33 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/04/29 10:53:08 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*sol;
	unsigned int	i;

	if (!s)
		return (NULL);
	sol = (char *)ft_calloc(sizeof(*s), ft_strlen(s) + 1);
	if (!sol)
		return (NULL);
	i = 0;
	while (s[i])
	{
		sol[i] = f(i, (char)s[i]);
		i++;
	}
	return (sol);
}
