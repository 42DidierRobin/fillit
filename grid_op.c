/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:43:48 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/09 13:50:11 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

void		ft_del_grid(char ***grid)
{
	int i;

	i = 0;
	while ((**grid)[i])
	{
		free((*grid)[i]);
		i++;
	}
	free(*grid);

}

void		ft_clean_grid(char **grid, char letter)
{
	int i;
	int j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == letter)
				grid[i][j] = '.';
			j++;
		}
		i++;
	}
}

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
	int		j;

	i = 0;
	while(tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			ft_putchar(tab[i][j]);
			ft_putchar(' ');
			j++;
		}
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
		while (grid[i][j])
		{
			if (grid[i][j] != '.' && ((j > max) || (i > max)) )
				max = (i < j)? j: i;
			j++;
		}
		i++;
	}

	// on rajoute 1, car la grille commence a zer et on veut la taille
	return (max + 1);
}

//copy une grille en entiere.
char		**ft_copy_grid_full(char **grid)
{
	short		i;
	short		j;
	short		len;
	char	**result;

	i = 0;
	len = ft_strlen(grid[0]);
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

//copy une grille de la taille precise.
char		**ft_copy_grid(char **grid, short len)
{
	short		i;
	short		j;
	char	**result;

	i = 0;
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
