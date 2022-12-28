/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:23:31 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/10/29 19:48:44 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_n(char const *s, char c)
{
	int	i;
	int	cnt;
	int	wrd;

	cnt = 0;
	i = 0;
	wrd = 0;
	while (s[i])
	{
		if ((s[i] != c) && (wrd == 0))
		{
			wrd = 1;
			cnt += 1;
		}
		else if (s[i] == c)
			wrd = 0;
		i++;
	}
	return (cnt);
}

static int	wrd_len(char *s, int *i, char c)
{
	int	x;
	int	i2;

	x = 0;
	while ((s[*i] == c) && s[*i])
	{
		*i += 1;
	}
	i2 = *i;
	while (s[i2] && (s[i2] != c))
	{
		i2++;
		x++;
	}
	return (x);
}

static int	wrt_wrds(char *s, char **p, int *i, char c)
{
	int		wrd_sz;
	int		j;
	int		ip;
	char	*pw;

	wrd_sz = wrd_len(s, i, c);
	ip = 0;
	while (wrd_sz != 0)
	{
		pw = (char *)ft_calloc(sizeof(char), (wrd_sz + 1));
		if (!pw)
			return (1);
		j = 0;
		while (j < wrd_sz)
		{
			pw[j++] = s[*i];
			*i += 1;
		}
		pw[j] = '\0';
		p[ip] = pw;
		ip++;
		wrd_sz = wrd_len(s, i, c);
	}
	p[ip] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**sol;
	int		i;
	int		error;

	if (!s)
		return (NULL);
	count = words_n(s, c);
	sol = (char **)ft_calloc(sizeof(char *), count + 1);
	if (!sol)
		return (NULL);
	i = 0;
	error = wrt_wrds((char *)s, sol, &i, c);
	if (error)
	{
		i = 0;
		while (sol[i])
		{
			free(sol[i]);
			i++;
		}
		free(sol);
		return (NULL);
	}
	return (sol);
}
