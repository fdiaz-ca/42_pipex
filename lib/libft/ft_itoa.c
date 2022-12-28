/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:42:47 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/10/29 19:48:03 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_pos(int n)
{
	if (n == -2147483648)
		return (11);
	else if (n < 0)
		return (cnt_pos(n * (-1)) + 1);
	else if (n < 10)
		return (1);
	else
		return (cnt_pos(n / 10) + 1);
}

void	wrt_num(char *sol, int pos, long int num)
{
	sol[pos] = '\0';
	if (num < 0)
	{
		sol[0] = '-';
		num *= -1;
		while (pos > 1)
		{
			sol[pos - 1] = num % 10 + '0';
			num = num / 10;
			pos--;
		}
	}
	else
	{
		while (pos > 0)
		{
			sol[pos - 1] = num % 10 + '0';
			num = num / 10;
			pos--;
		}
	}
}

char	*ft_itoa(int n)
{
	int			pos;
	char		*sol;
	long int	num;

	pos = cnt_pos(n);
	sol = (char *)ft_calloc(pos + 1, sizeof(char));
	if (!sol)
		return (NULL);
	num = (long int)n;
	wrt_num(sol, pos, num);
	return (sol);
}
