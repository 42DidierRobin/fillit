/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cread_tris.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:48:16 by adespond          #+#    #+#             */
/*   Updated: 2015/12/03 11:49:30 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tris	*init_tris(char name)
{
	t_tris	*tris;
	t_point	*coord;
	int		i;
	
	i = -1;
	tris = (t_tris*)malloc(sizeof(t_tris));
	tris->name = name;
	while (++i < 4)
	{
		coord = (t_point*)malloc(sizeof(t_point));
		coord->x = -1;
		coord->y = -1;
		tris->coord[i] = *coord;
	}
	return (tris);
}

char	create_tris(char *str, char name)
{
	t_tris	*tris;
	int		i;
	int		nbr;

	i = 0;
	nbr = -1;
	tris = init_tris(name);
	while (i < 20)
	{
		if (str[i] == '\n' && (i + 1) % 5 != 0)
			return (0);
		if (str[i] == '.' || str[i] == '#' || str[i] == '\n')
		{
			if (str[i] == '#')
			{
				if(++nbr < 4)
					create_tris_coord(tris, nbr, i);
				else
					return (0);
			}
		}
		else
			return (0);
		i++;
	}
	return (check_tris(tris));
}

void	create_tris_coord(t_tris *tris, int nbr, int i)
{
	t_point		point;

	point.x = i % 5;
	point.y = i / 5;
	point.next = NULL;
	tris->coord[nbr] = point;
}

char	check_tris(t_tris *tris)
{
	int		i;
	t_point	*coord;

	coord = tris->coord;
	i = -1;
	while (++i < 4)
	{
		if (coord[i].x < 0 || coord[i].x > 4 || coord[i].y < 0 || coord[i].y > 4)
			return (0);
		if (ckeck_tris_form(tris) == 0)
			return (0);
	}
	return (1);
}

char	check_tris_form(t_tris *tris)
{

}
