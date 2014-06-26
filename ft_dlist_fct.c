/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_fct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 15:34:55 by aemebiku          #+#    #+#             */
/*   Updated: 2014/06/26 15:34:56 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_dnew	*ft_dget_elem(t_dlist *list, size_t pos)
{
	t_dnew	*elem;
	size_t	i;

	i = 0;
	if (list == NULL)
		return (NULL);
	elem = list->head;
	while (i < pos)
	{
		elem = elem->next;
		i++;
	}
	return (elem);
}

void	ft_dlst_swap(t_dlist *list, size_t pos1, size_t pos2)
{
	t_dnew	*temp1;
	t_dnew	*temp2;
	t_dnew	temp3;

	if (list != NULL && list->head != NULL)
	{
		temp1 = ft_dget_elem(list, pos1);
		temp2 = ft_dget_elem(list, pos2);
		temp3.data = temp1->data;
		temp1->data = temp2->data;
		temp2->data = temp3.data;
	}
}

size_t	ft_list_data_len(t_dlist *list)
{
	t_dnew	*elem;
	size_t	len;

	len = 0;
	elem = list->head;
	while (elem != NULL)
	{
		len += ft_strlen(elem->data);
		elem = elem->next;
	}
	return (len);
}

char	*ft_dlst_to_array(t_dlist *list)
{
	t_dnew	*tmp;
	char	*str;
	size_t	len;
	int		i;
	int		j;

	if (list == NULL || list->head == NULL)
		return (NULL);
	i = -1;
	len = ft_list_data_len(list);
	str = (char *)malloc(sizeof(*str) * len + 1);
	while (++i < (int)len + 1)
		str[i] = '\0';
	tmp = list->head;
	i = -1;
	while (tmp != NULL)
	{
		j = -1;
		while (((char *)tmp->data)[++j])
			str[++i] = ((char *)tmp->data)[j];
		tmp = tmp->next;
	}
	return (str);
}

int		ft_get_pos(t_dlist *list, t_dnew *elem)
{
	t_dnew	*tmp;
	int		count;

	count = 0;
	tmp = list->head;
	while (tmp != elem)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
