/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:29:16 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/18 19:16:12 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void	pre_brain(char **grid, t_conf *config)
{
	int		minx;
	int		miny;
	int		i;

	minx = 0;
	miny = 0;
	i = -1;
	while (++i < 4)
	{
		if (minx > config->list_tris[0].coord[i].x)
			minx = config->list_tris[0].coord[i].x;
		if (miny > config->list_tris[0].coord[i].y)
			miny = config->list_tris[0].coord[i].y;
	}
	i = -1;
	while (++i < 4)
	{
		grid[(miny * -1) + config->list_tris[0].coord[i].y]
			[(minx * -1) + config->list_tris[0].coord[i].x] =
			config->list_tris[0].name;
	}
}

char	last_min(t_conf *conf, int p, t_point *start)
{
	int		i;
	int		j;

	i = -1;
	while (++i < conf->min_size)
	{
		j = -1;
		while (++j < conf->min_size)
		{
			if (conf->grid[j][i] == conf->list_tris[p].name)
			{
				if (j < start->y)
					return (0);
				else if (j == start->y && i < start->x)
					return (0);
			}	
		}
	}
	return (1);
}

t_point	*next_pos(t_point *pos, int min)
{
	if (pos->x >= min)
	{
		pos->x = 0;
		pos->y++;
		if (pos->y > min)
		{
			return (NULL);
		} 
	}
	else
		pos->x++;
	return (pos);
}

int		brain_rec(t_conf *conf, char **grid, int iter, t_point *pos)
{
	ft_putstr("   hey ");
	ft_putnbr(iter);
	if (pos == NULL)
	{
		ft_clean_grid(grid, conf->list_tris[iter - 1].name);
		return (0);
	}
	ft_putnbr(pos->x);
	ft_putnbr(pos->y);
	ft_putchar('\n');
	ft_print_grid(grid);
	if (iter == conf->nbr_piece)
	{
		ft_putstr("       jamais\n");
		conf->grid = ft_copy_grid(grid, conf->min_size);
		return (1);
	}
	if (ft_is_putable(grid, pos, &conf->list_tris[iter]))
	{
		ft_put_piece(grid, pos, &conf->list_tris[iter]);
		return (brain_rec(conf, grid, iter + 1, ft_new_element(0, 0)));
	}
	if (!brain_rec(conf, grid, iter, next_pos(pos, conf->min_size)))
		return (0);
	return (0);
}

void	algo(t_conf *conf)
{
	char	**grid;
	t_point	*pos;

	pos = ft_new_element(0, 0);
	conf->min_size = 2;
	grid = ft_new_grid(conf->min_size);
	ft_putstr("OKk\n");
	while (!brain_rec(conf, grid, 0, pos))
	{
		ft_putchar('\n');
		ft_print_grid(grid);
		ft_putstr("  JE GRANDI\n");
		conf->min_size++;
		ft_putnbr(conf->min_size);
		ft_putchar('\n');
		grid = ft_new_grid(conf->min_size);
	}
	brain_rec(conf, grid, 0, pos);
}

/*void	brain_rec(char **grid, t_conf *config, short iter, t_point *starts)
{
	if (iter == (config->nbr_piece))
	{
		if (ft_find_len(grid) < config->min_size)
		{
			config->min_size = ft_find_len(grid);
			config->grid = ft_copy_grid(grid, config->min_size);
			ft_print_grid(config->grid);
		}
		return ;
	}
	if (ft_is_putable(grid, starts, &config->list_tris[iter]))
	{
		ft_put_piece(grid, starts, &config->list_tris[iter]);
		if (ft_find_len(grid) <= config->min_size)
			brain_rec(grid, config, iter + 1, ft_give_starts(grid, starts));
	}
	ft_clean_grid(grid, config->list_tris[iter].name);
	if (starts->next)
		brain_rec(grid, config, iter, starts->next);
}*/

/*void	algo(t_conf *config)
{
	char	**grid;
	t_point	*begin;

	begin = ft_new_element(0, 0);
	if (ft_grid_isfull(config->grid))
		return ;
	grid = ft_new_grid(config->nbr_piece * 4);
	pre_brain(grid, config);
	brain_rec(grid, config, 1, ft_give_starts(grid, begin));
}*/
