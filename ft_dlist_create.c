/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 15:33:40 by aemebiku          #+#    #+#             */
/*   Updated: 2014/06/26 15:33:41 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_dlist	*ft_dlst_init(void)
{
	t_dlist	*list;

	if ((list = (t_dlist *)malloc(sizeof(*list))) == NULL)
		return (NULL);
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return (list);
}

t_dnew	*ft_dcreate_elem(void *data)
{
	t_dnew	*new_elem;

	if ((new_elem = (t_dnew *)malloc(sizeof(*new_elem))) != NULL)
	{
		if (data != NULL)
			new_elem->data = data;
		else
			new_elem->data = NULL;
		new_elem->next = NULL;
		new_elem->prev = NULL;
		return (new_elem);
	}
	return (NULL);
}

void	ft_dlstpush_head(t_dlist *list, void *data)
{
	t_dnew	*new_elem;

	if ((new_elem = ft_dcreate_elem(data)))
	{
		if (list->head == NULL)
		{
			list->head = new_elem;
			list->tail = new_elem;
		}
		else
		{
			list->head->prev = new_elem;
			new_elem->next = list->head;
			list->head = new_elem;
		}
		list->size++;
	}
}

void	ft_dlstpush_tail(t_dlist *list, void *data)
{
	t_dnew	*new_elem;

	if ((new_elem = ft_dcreate_elem(data)))
	{
		if (list->tail == NULL)
		{
			list->head = new_elem;
			list->tail = new_elem;
		}
		else
		{
			list->tail->next = new_elem;
			new_elem->prev = list->tail;
			list->tail = new_elem;
		}
		list->size++;
	}
}

void	ft_dlst_push(t_dlist *list, void *data, size_t pos)
{
	t_dnew	*new_elem;
	t_dnew	*temp;
	size_t	i;

	i = -1;
	if (pos == 0)
		ft_dlstpush_head(list, data);
	else if (pos == list->size)
		ft_dlstpush_tail(list, data);
	else
	{
		if ((new_elem = ft_dcreate_elem(data)) != NULL)
		{
			temp = list->head;
			while (++i < pos)
				temp = temp->next;
			temp->prev->next = new_elem;
			new_elem->prev = temp->prev;
			temp->prev = new_elem;
			new_elem->next = temp;
			list->size++;
		}
	}
}
