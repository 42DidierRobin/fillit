/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:29:16 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/09 11:44:55 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

//-----
#include "stdio.h"
//-----

// Renvoi 1 si le point est un point de start (= un point adjacent (meme en diagonal) a une case remplie), 0 sinon
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

//Renvoi la liste des points de starts de la grille en cours
t_point		*ft_give_starts(char **grid)
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

// Verifie que la piece peut etre pose depuis start dans grid. Retourne 0 ou 1;
short			ft_is_putable(char **grid, t_point *start, t_tris *piece)
{
	short	l;

	l = 0;
	//je verifi les 4 cases
	while (4 - l)
	{
		if (grid[start->y + (piece->coord[l]).y]
				[start->x + (piece->coord[l]).x] != '.')
			return (0);
		l++;
	}
	return (1);
}

// Place une piece dans la grille a partir de start. Retourne grille;
void		ft_put_piece(char **grid, t_point *start, t_tris *piece)
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

//Pour linstant on prend les pieces dans lordre, on verra ensuite;
void		ft_fill_this_shit(char **grid, t_conf *config, short iter, t_point *starts)
{
	//cas de sortie
	if (iter == (config->nbr_piece))
	{
		//On a trouve plus petit on change le la grille de conf
		if (ft_find_len(grid) <= config->min_size)
		{
			//liberer lancienne grille a faire !!!!
			config->min_size = ft_find_len(grid);
			config->grid = ft_copy_grid(grid, config->min_size);
		}
		return ;
	}
	// si on a encore un point de demarage possible
	if (starts->next)
		ft_fill_this_shit(ft_copy_grid_full(grid), config, iter, starts->next);
	if (ft_is_putable(grid, starts, &config->list_tris[iter]))
	{
		ft_put_piece(grid, starts, &config->list_tris[iter]);
		ft_fill_this_shit(ft_copy_grid_full(grid), config, iter + 1, ft_give_starts(grid));
	}
}

// Retourne la taille de plus petit carre constructible grace au pieces de t_conf
void		ft_fillit(t_conf *config)
{
	char	**grid;
	t_point	*begin;

	begin = ft_new_element(0,0);
	config->min_size = config->nbr_piece * 4;

	// On creer la grille max, on pourra chercher a la diminuer plus tard
	grid = ft_new_grid(config->nbr_piece * 4);
	ft_fill_this_shit(grid, config, 0, begin);
}

