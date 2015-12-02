/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:47:01 by adespond          #+#    #+#             */
/*   Updated: 2015/12/02 18:08:05 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_point
{
	char			x;
	char			y;
	struct s_point	*next;
}					t_point;

typedef struct		s_tris
{
	char			name;
	t_point			coord[4];
}					t_tris;

typedef struct		s_conf
{
	char			**grid;
	t_tris			*piece;
	char			nbr_piece;
}					t_conf;
#endif

//imprime une grille.
void		ft_print_grid(char **tab);

//initialise une grille fraiche remplie de '.' de taille 4*nb piece
char		**ft_new_grid(int nb_piece);

//place une piece a start dans la grille si possible
int			ft_put_piece(char **grid, t_point *start, t_tris *piece);

//Verifi que piece peut etre place dans grille a start
int			ft_is_putable(char **grid, t_point *start, t_tris *piece);

//Renvoi la taille du pls grand carre rempli dans la grille sans '.'
int			ft_find_len(char **grid);

//Copi une grille de taille len a partir de la grille envoyee cette fonction segfault quand lenvie lui en prend.
char		**ft_copy_grid(char **grid, int len);

//Dit si un point est un start ou pas
int			ft_is_start(char **grid, t_point *point);

//Renvoi la liste des starts de la grille
t_point		**ft_give_starts(char **grid);

