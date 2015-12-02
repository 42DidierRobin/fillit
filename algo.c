/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:29:16 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/02 18:08:01 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

// Renvoi 1 si le point est un point de start (= un point adjacent (meme en diagonal) a une case remplie), 0 sinon
int				ft_is_start(char **grid, t_point *point)
{
	int		i;
	int		j;

	i = -1;
	while (i < 2)
	{
		j = -1;
		while (j < 2)
		{
			if (((point->x + i) >= 0) && ((point->y + j) >= 0)
					&& grid[point->y + j][point->x + i] != '.')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

//Renvoi la liste des points de starts de la grille en cours
t_point		**ft_give_starts(char **grid)
{
	int			max;
	int			i;
	int			j;
	t_point		*tmp;
	t_point		*starts;
	t_point		**ret;

	ret = &starts;
	max = ft_find_len(grid) + 1;
	ft_putnbr(max);
	i = 0;
	while (max - i)
	{
		j = 0;
		while (max - j)
		{
			tmp = (t_point*)malloc(sizeof(t_point));
			tmp->x = i;
			tmp->y = j;
			tmp->next = NULL;
			if (ft_is_start(grid, tmp))
			{
				starts = tmp;
				starts = starts->next;
			}
			free(tmp);
			j++;
		}
		i++;
	}
	return (ret);
}


// Verifie que la piece peut etre pose depuis start dans grid. Retourne 0 ou 1;
int			ft_is_putable(char **grid, t_point *start, t_tris *piece)
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

// Place une piece dans la grille a partir de start. Retourne 1 ou 0;
int			ft_put_piece(char **grid, t_point *start, t_tris *piece)
{
	short	l;

	if (ft_is_putable(grid, start, piece))
	{
		l = 0;
		while (4 - l)
		{
			grid[start->y + (piece->coord[l]).y]
				[start->x + (piece->coord[l]).x] = piece->name;
			l++;
		}
		return (1);
	}
	return (0);
}

