/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:55:15 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/11/18 00:50:53 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n >= -9 && n <= 9)
		ft_putchar_fd(ft_abs(n) + '0', fd);
	else
	{
		ft_putnbr_fd(ft_abs(n / 10), fd);
		c = ft_abs(n % 10) + '0';
		write(fd, &c, 1);
	}
}
