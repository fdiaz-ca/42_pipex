/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:26:05 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/11/02 12:21:31 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_imp_char(int *cnt, char c)
{
	write(1, &c, 1);
	*cnt += 1;
}

void	ft_imp_nb(int *cnt, char *base, int bsize, unsigned long long num)
{
	if (num >= (unsigned long long)bsize)
	{
		ft_imp_nb(cnt, base, bsize, (num / bsize));
		ft_imp_char(cnt, base[num % bsize]);
	}
	else
		ft_imp_char(cnt, base[num]);
}
