/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:01:20 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/10/29 19:47:47 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	pas_spa(char *p, int *i, int *sign)
{
	while (((p[*i] >= 9) && (p[*i] <= 13)) || (p[*i] == ' '))
		*i += 1;
	if ((p[*i] == '+') || (p[*i] == '-'))
	{
		if (p[*i] == '-')
			*sign = -1;
		*i += 1;
	}
}

int	ft_atoi(const char *str)
{
	int		num;
	int		i;
	int		sign;
	char	*p;

	num = 0;
	i = 0;
	p = (char *)str;
	sign = 1;
	pas_spa(p, &i, &sign);
	while ((p[i] >= '0') && (p[i] <= '9'))
	{
		num = (num * 10) + (p[i] - '0');
		i++;
	}
	num = num * sign;
	if ((sign == 1) && (num < 0))
		return (-1);
	if ((sign == -1) && (num > 0))
		return (0);
	return (num);
}
