/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:29:16 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/14 22:50:35 by rdidier          ###   ########.fr       */
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

t_point			*ft_give_starts(char **grid)
{
	t_point		*starts;
	short		i;
	short		j;
	short		max;

	starts = ft_new_element(-1,-1);
	max = ft_find_len(grid) + 1;
	i = 0;
	while (max - i)
	{
		j = 0;
		while (max - j)
		{
			if (ft_is_start(grid, j, i))
			{
				ft_add_list(starts, ft_new_element(j, i));
			}
			j++;
		}
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

void			ft_fill_this_shit(char **grid, t_conf *config, short iter, t_point *starts)
{
	if (iter == (config->nbr_piece))
	{
		if (ft_find_len(grid) <= config->min_size)
		{
			config->min_size = ft_find_len(grid);
			config->grid = ft_copy_grid(grid, config->min_size);
		}
		ft_clean_grid(grid, config->list_tris[iter].name);
		return ;
	}
	if (starts->next)
		ft_fill_this_shit(grid, config, iter, starts->next);
	if (ft_is_putable(grid, starts, &config->list_tris[iter]))
	{
		ft_put_piece(grid, starts, &config->list_tris[iter]);
		if (ft_find_len(grid) <= config->min_size)
			ft_fill_this_shit(grid, config, iter + 1, ft_give_starts(grid));
	}
	ft_clean_grid(grid, config->list_tris[iter].name);
}

void			ft_fillit(t_conf *config)
{
	char	**grid;
	t_point	*begin;

	begin = ft_new_element(0,0);
	grid = ft_new_grid(config->nbr_piece * 4);
	ft_fill_this_shit(grid, config, 0, begin);
}
