/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:29:16 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/02 14:12:10 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"


// Verifie que la piece peut etre pose depuis start dans grid. Retourne 0 ou 1;
int			ft_is_putable(char **grid, t_point start, t_tris p)
{
	char	l;

	l = 0;
	//je verifi les 4 cases
	while (4 - l)
	{
		if (grid[start->x + p->coord[l]->x][start->y + p->coord[l]->y] != '.')
			return (0);
		l++;
	}
	return (1);
}

// Place une piece dans la grille a partir de start. Retourne 1 ou 0;
int			ft_put_piece(char **grid, t_point start, t_tris piece)
{
	char	l;

	if (ft_is_putable(grid, start, piece))
	{
		l = 0;
		while (4 - l)
		{
			
		}
	}
	return (0);
}

char 		**ft_new_grid(int nb_pieces)
{
	int			len;
	int			i;
	int			j;
	char		**result;

	i = 0;
	len = 4 * nb_pieces + 1;
	result = (char**)malloc(sizeof(char*) * len);
	result[len] = NULL;
	while (len - i)
	{
		result[i] = (char*)malloc(sizeof(char) * len);
		j = 0;
		while(len - j)
		{
			result[i][j] = '.';
			j++;
		}
		result[i][j] = '\0';
		i++;
	}
	return (result);
}

void		ft_print_grid(char **tab)
{
	int		i;

	i = 0;
	while(tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

int			main()
{
	char **grid;

	grid = ft_new_grid(10);
	ft_print_grid(grid);
	return (0);
}
