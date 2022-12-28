/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:11:42 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/05/01 18:07:14 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if ((size >= SIZE_MAX && count > 1) || (count >= SIZE_MAX && size > 1))
		return (NULL);
	p = (void *)malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, size * count);
	return (p);
}
