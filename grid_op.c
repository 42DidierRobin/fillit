/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:43:48 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/02 16:50:25 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

char 		**ft_new_grid(int len)
{
	int			i;
	int			j;
	char		**result;

	i = 0;
	len = len + 1;
	result = (char**)malloc(sizeof(char*) * len);
	if (!result)
		ft_putstr("pas de malloc 1");
	result[len] = NULL;
	while (len - i)
	{
		result[i] = (char*)malloc(sizeof(char) * len);
		if (!result[i])
			ft_putstr("pas de malloc 2");
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

int			ft_find_len(char **grid)
{
	int i;
	int j;
	int max;

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
char		**ft_copy_grid(char **grid, int len)
{
	int		i;
	int		j;
	char	**result;

	i = 0;
	result = ft_new_grid(len);
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
