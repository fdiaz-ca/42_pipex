/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:05:50 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/04/28 23:35:15 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hays, const char *ndle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*ndle)
		return ((char *)hays);
	i = 0;
	while ((hays[i] != '\0') && (i < len))
	{
		j = 0;
		if (hays[i] == ndle[j])
		{
			while ((ndle[j] == hays[i + j]) && (i + j < len))
			{
				if (ndle[j + 1] == '\0')
					return ((char *)hays + i);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
