/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:45:59 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/09 11:44:39 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int			main()
{
	// ------------ TEST DE new_grd / print_grid / put piece / putable---------- //
	char **grid;

	t_tris	*piece;
	t_tris	*piece2;
	t_point	*start;

	start = (t_point*)malloc(sizeof(t_point));
	start->x = 0;
	start->y = 0;
	start->next = NULL;
	piece = (t_tris*)malloc(sizeof(t_tris));
	piece->name = 'A';
	piece->coord[0].x = 1;
	piece->coord[0].y = 0;
	piece->coord[1].x = 0;
	piece->coord[1].y = 1;
	piece->coord[2].x = 1;
	piece->coord[2].y = 1;
	piece->coord[3].x = 2;
	piece->coord[3].y = 1;

	piece2 = (t_tris*)malloc(sizeof(t_tris));
	piece2->name = 'B';
	piece2->coord[0].x = 0;
	piece2->coord[0].y = 0;
	piece2->coord[1].x = 1;
	piece2->coord[1].y = 0;
	piece2->coord[2].x = 1;
	piece2->coord[2].y = 1;
	piece2->coord[3].x = 2;
	piece2->coord[3].y = 1;

	grid = ft_new_grid(40);
	ft_put_piece(grid, start, piece);
	if (ft_is_putable(grid, start, piece2))
		ft_put_piece(grid, start, piece2);
	ft_print_grid(grid);

	// --------- TEST de find_len ------//
	char	**gridtest;
	gridtest = ft_new_grid(6);

	gridtest[1][0] = 'A';
	gridtest[2][0] = 'B';
	gridtest[3][0] = 'B';

	ft_print_grid(gridtest);
	ft_putnbr(ft_find_len(gridtest));

	
	// ----------- TEST DE copy grid 
	ft_putstr("Carre trouve :\n");

	int	max;
	max = ft_find_len(grid);
	char	**full_grid;
	full_grid = ft_copy_grid(grid, max);
	ft_print_grid(full_grid);
	// ------------

	// ------------ TEST DE ft_is_start ---------- //
	ft_putstr("doit etre 1 : ");
	ft_putnbr(ft_is_start(grid, 0, 0));
	ft_putstr("\n");
	ft_putstr("doit etre 0 : ");
	ft_putnbr(ft_is_start(grid, 0, 1));
	ft_putstr("\n");
	ft_putstr("doit etre 1 : ");
	ft_putnbr(ft_is_start(grid, 2, 0));
	ft_putstr("\n");
	ft_putstr("doit etre 0 : ");
	ft_putnbr(ft_is_start(grid, 2, 1));
	ft_putstr("\n");
	ft_putstr("doit etre 1 : ");
	ft_putnbr(ft_is_start(grid, 3, 2));
	ft_putstr("\n");
	ft_putstr("doit etre 0 : ");
	ft_putnbr(ft_is_start(grid, 3, 3));
	ft_putstr("\n");

	// ------------ TEST DE ft_give_starts ---------- //
	t_point *list;

	int i;

	i = 0;
	list = ft_give_starts(grid);
	ft_print_list(list);

	// ------------ TEST DE LALGO (sans permutations) MOTHERFUCKER ------- //
	
	t_conf	*config;

	config = (t_conf*)malloc(sizeof(t_conf));
	config->nbr_piece = 4;
	config->list_tris[0] = *piece;
	config->list_tris[1] = *piece2;
	piece->name = 'C';
	config->list_tris[2] = *piece;
	piece2->name = 'D';
	config->list_tris[3] = *piece2;

	ft_fillit(config);

	ft_putstr("Affichage du carre trouve sans permutatoin : \n");
	ft_print_grid(config->grid);
	ft_putstr("Taille du carre trouve : \n");
	ft_putnbr(config->min_size);
	
	return (0);
}
