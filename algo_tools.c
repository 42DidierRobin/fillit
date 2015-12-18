/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:29:16 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/18 14:16:17 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int				ft_is_start(char **grid, short x, short y)
{
	short		i;
	short		j;

	if (grid[y][x] != '.')
		return (0);
	i = -1;
	while (i < 2)
	{
		j = -1;
		while (j < 2)
		{
			if (((x + j) >= 0) && ((y + i) >= 0)
					&& grid[y + i][x + j] != '.')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_point			*ft_give_starts(char **grid, t_point *p)
{
	t_point		*starts;
	short		i;
	short		j;
	short		max;

	starts = ft_new_element(-1, -1);
	max = ft_find_len(grid) + 1;
	i = p->y;
	j = p->x;
	while (i < max)
	{
		while (j < max)
		{
			if (ft_is_start(grid, j, i))
			{
				ft_add_list(starts, ft_new_element(j, i));
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (starts->next)
		return (starts->next);
	return (NULL);
}

short			ft_is_putable(char **grid, t_point *start, t_tris *piece)
{
	short	l;

	l = 0;
	while (4 - l)
	{
		if (((start->y + piece->coord[l].y >= 0)
			|| (start->x + piece->coord[l].x >= 0))
			&& (grid[start->y + (piece->coord[l]).y]
				[start->x + (piece->coord[l]).x] != '.'))
			return (0);
		l++;
	}
	return (1);
}

void			ft_put_piece(char **grid, t_point *start, t_tris *piece)
{
	short	l;

	l = 0;
	while (4 - l)
	{
		grid[start->y + (piece->coord[l]).y]
			[start->x + (piece->coord[l]).x] = piece->name;
		l++;
	}
}

char			ft_grid_isfull(char **tab)
{
	int		i;
	int		j;
	int		c;

	c = 0;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '.')
				c++;
			j++;
		}
		i++;
	}
	if (c < 4)
		return (1);
	return (0);
}
