/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cread_tris.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:48:16 by adespond          #+#    #+#             */
/*   Updated: 2015/12/09 14:29:56 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tris	*check_tris(t_tris *tris)
{
	int		i;
	t_point	*coord;

	coord = tris->coord;
	i = -1;
	while (++i < 4)
	{
		if (coord[i].x < 0 || coord[i].x > 4 || coord[i].y < 0 || coord[i].y > 4)
			return (0);
	}
	if (check_tris_form(tris) == 0)
		return (NULL);
	if ((tris = order_tris(tris)) == 0)
		return (NULL);
	return (tris);
}

//pour savoir si une piece est juste, je calcule le nombre de borde qu'elle as, si elle a moins de 11, c'est bingo, sinon c'est faux !
char	check_tris_form(t_tris *tris)
{
	char	border;
	t_point *coord;
	int		i;
	int		j;

	i = -1;
	coord = tris->coord;
	border = 16;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (i != j)
			{
				if ((coord[i].x + 1 == coord[j].x && coord[i].y == coord[j].y) ||
					(coord[i].x - 1 == coord[j].x && coord[i].y == coord[j].y) ||
					(coord[i].x == coord[j].x && coord[i].y + 1 == coord[j].y) ||
					(coord[i].x == coord[j].x && coord[i].y - 1 == coord[j].y))
					border--;
			}
		}
	}
	if (border <= 10)
		return (1);
	return (0);
}

//cette fonction permet de mettre le point le plus en haut a gauche en possition 0,0
t_tris		*order_tris(t_tris *tris)
{
	t_point		*coord;
	int			i;

	coord = tris->coord;
	i = -1;
	while (++i < 4)
	{
		coord[i].x = coord[i].x - coord[0].x;
		coord[i].y = coord[i].y - coord[0].y;
	}
	return (tris);
}

/*t_tris	*order_tris(t_tris *tris)
{
	t_point	*coord;
	int		i;
	char	minx;
	char	miny;
	
	minx = 4;
	miny = 4;
	coord = tris->coord;
	i = -1;
	while (++i < 4)
	{
		if (coord[i].x < minx)
			minx = coord[i].x;
		if (coord[i].y < miny)
			miny = coord[i].y;
	}
	i = -1;
	while (++i < 4)
	{
		coord[i].x = coord[i].x - minx;
		coord[i].y = coord[i].y - miny;
	}
	return (tris);
}*/

