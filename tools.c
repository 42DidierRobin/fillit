/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 14:35:56 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/18 13:58:11 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

t_point		*ft_new_element(short i, short j)
{
	t_point		*element;

	element = (t_point*)malloc(sizeof(t_point));
	element->next = NULL;
	element->x = i;
	element->y = j;
	return (element);
}

void		ft_add_list(t_point *list, t_point *element)
{
	t_point		*list2;

	list2 = list;
	while (list2->next)
	{
		list2 = list2->next;
	}
	list2->next = element;
}

void		ft_print_list(t_point *list)
{
	int			i;
	t_point		*lst;

	lst = list;
	i = 0;
	while (lst->next)
	{
		ft_putstr("Element numero ");
		ft_putnbr(i);
		ft_putstr(" ---> (");
		ft_putnbr(lst->x);
		ft_putchar(';');
		ft_putnbr(lst->y);
		ft_putstr(")\n");
		lst = lst->next;
		i++;
	}
	ft_putstr("Element numero ");
	ft_putnbr(i);
	ft_putstr(" ---> (");
	ft_putnbr(lst->x);
	ft_putchar(';');
	ft_putnbr(lst->y);
	ft_putstr(")\n");
}
