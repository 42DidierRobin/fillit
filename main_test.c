/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:45:59 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/02 18:08:13 by rdidier          ###   ########.fr       */
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
	if (!ft_put_piece(grid, start, piece))
		ft_putstr("piece 1 : Probleme\n");
	if (!ft_put_piece(grid, start, piece2))
		ft_putstr("piece 2 :Probleme\n");
	ft_print_grid(grid);

	// ----------- TEST DE copy grid  Ce code segfault, probleme non resolu
	//ft_putstr("Carre trouve :\n");

	//int	max;
	//max = ft_find_len(grid);
	//char	**full_grid;
	//full_grid = ft_copy_grid(grid, max);
	//ft_print_grid(full_grid);
	// ------------

	// ------------ TEST DE ft_is_start ---------- //
	start->x = 0;
	start->y = 0;
	ft_putstr("doit etre 1 : ");
	ft_putnbr(ft_is_start(grid, start));
	ft_putstr("\n");
	start->x = 3;
	start->y = 0;
	ft_putstr("doit etre 1 : ");
	ft_putnbr(ft_is_start(grid, start));
	ft_putstr("\n");
	start->x = 4;
	start->y = 1;
	ft_putstr("doit etre 0 : ");
	ft_putnbr(ft_is_start(grid, start));
	ft_putstr("\n");
	start->x = 3;
	start->y = 2;
	ft_putstr("doit etre 1 : ");
	ft_putnbr(ft_is_start(grid, start));
	ft_putstr("\n");
	start->x = 3;
	start->y = 3;
	ft_putstr("doit etre 0 : ");
	ft_putnbr(ft_is_start(grid, start));
	ft_putstr("\n");

	// ------------ TEST DE ft_give_starts ---------- //
	t_point **list;
	t_point	*yolo;
	int i;

	i = 0;
	list = ft_give_starts(grid);
	ft_putstr("ft_give_starts sest executee\n");
	yolo = *list;
	while (yolo->next)
	{
		ft_putstr("Point numero ");
		ft_putnbr(i);
		ft_putstr(" : (");
		ft_putnbr(yolo->x);
		ft_putstr(";");
		ft_putnbr(yolo->y);
		ft_putstr(")\n");
		yolo = yolo->next;
		i++;
	}
	ft_putstr("Point numero ");
	ft_putnbr(i);
	ft_putstr(" : (");
	ft_putnbr(yolo->x);
	ft_putstr(";");
	ft_putnbr(yolo->y);
	ft_putstr(")\n");
	yolo = yolo->next;

	return (0);
}
