/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:43:48 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/08 15:26:22 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

char 		**ft_new_grid(short len)
{
	short			i;
	short			j;
	char		**result;

	i = 0;
	len = len + 1;
	result = (char**)malloc(sizeof(char*) * len);
	if (!result)
		ft_putstr("malloc error in new_grid(1)");
	result[len] = NULL;
	while (len - i)
	{
		result[i] = (char*)malloc(sizeof(char) * len);
		if (!result[i])
			ft_putstr("malloc error in new_grid(2)");
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

short		ft_find_len(char **grid)
{
	short i;
	short j;
	short max;

	i = 0;
	max = 0;
	while(grid[i])
	{
		j = 0;
		if (grid[i][j] != '.' && i > max)
			max = i;
		while (grid[i][j])
		{
			if (grid[i][j] != '.' && (j > max))
				max = j;
			j++;
		}
		i++;
	}
	// on rajoute 1, car la grille commence a zer et on veut la taille
	return (max + 1);
}

// !!!!! cette fonction segfault quand lenvie lui en prend.
char		**ft_copy_grid(char **grid, short len)
{
	short		i;
	short		j;
	char	**result;

	i = 0;
	//Wtf ce +1 debug mais on veut pas savoir pourquoi.
	result = ft_new_grid(len + 1);
	while (len - i)
	{
		j = 0;
		while (len - j)
		{
			if (grid[i][j] != '.')
				result[i][j] = grid[i][j];
			j++;
		}
		result[i][j] = '\0';
		i++;
	}
	result[i] = NULL;
	return (result);
}
