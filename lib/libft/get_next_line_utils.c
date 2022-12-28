/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 05:11:08 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/11/02 13:24:28 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* With flag 'state' = GOOD, it initializes the 'head' of the structure.     */
/* With flag 'state' = LEAVE, it means there was a memory error, or file was */
/* over. It clears and frees all nods in structure, and then also the 'head'.*/
int	ft_manage_head(t_head **head, int state)
{
	t_gnlnod	*tmp;

	if (state == GOOD)
	{
		*head = (t_head *)malloc(sizeof(t_head));
		if (!(*head))
			return (LEAVE);
		(*head)->n_num = 0;
		(*head)->state = GOOD;
		(*head)->next = NULL;
	}
	else if (state == LEAVE)
	{
		while ((*head)->next)
		{
			tmp = (*head)->next;
			(*head)->next = (*head)->next->next;
			free(tmp);
		}
		free(*head);
		*head = NULL;
	}
	return (GOOD);
}

/* It will count and return the length of next line in structure, that will  */
/* end with a '\n' char or end of structure.                                 */
int	ft_next_line_length(t_head *head)
{
	int			i;
	t_gnlnod	*nodo;

	i = 0;
	nodo = head->next;
	while (nodo && (nodo->let != '\n'))
	{
		i++;
		nodo = nodo->next;
	}
	if (nodo && (nodo->let == '\n'))
		i++;
	return (i);
}
