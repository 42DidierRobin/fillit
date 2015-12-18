/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:29:16 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/18 14:13:30 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

void	brain_rec(char **grid, t_conf *config, short iter, t_point *starts)
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
		if (ft_find_len(grid) < config->min_size)
			brain_rec(grid, config, iter + 1, ft_give_starts(grid, starts));
	}
	ft_clean_grid(grid, config->list_tris[iter].name);
	if (starts->next)
		brain_rec(grid, config, iter, starts->next);
}

void	algo(t_conf *config)
{
	char	**grid;
	t_point	*begin;

	begin = ft_new_element(0, 0);
	if (ft_grid_isfull(config->grid))
		return ;
	grid = ft_new_grid(config->nbr_piece * 4);
	brain_rec(grid, config, 0, begin);
}
