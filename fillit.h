/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:47:01 by adespond          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/12/08 17:01:51 by rdidier          ###   ########.fr       */
/*   Updated: 2015/12/02 17:33:18 by adespond         ###   ########.fr       */
=======
/*   Updated: 2015/12/08 16:19:32 by adespond         ###   ########.fr       */
>>>>>>> 0a5867689ee376f4fb8b2d8dfe6c698acbce5305
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_point
{
	short			x;
	short			y;
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
	char			nbr_piece;
	struct s_tris	list_tris[26];
}					t_conf;

t_conf				*open_file(char *file, t_conf *conf);
t_conf				*read_file(int *fd, t_conf *conf);
void				fillit(int *argc, char **argv);
t_tris				*create_tris(char *str, char name);
void				create_tris_coord(t_tris *tris, int nbr, int i);
t_tris				*check_tris(t_tris *tris);
char				check_tris_form(t_tris  *tris);
t_tris				*init_tris(char name);
t_tris				*order_tris(t_tris *tris);
t_conf				*init_conf();
void				testmescouilles(t_conf *conf);
//imprime une grille.
void		ft_print_grid(char **tab);

//initialise une grille fraiche remplie de '.' de taille 4*nb piece
char		**ft_new_grid(short nb_piece);

//place une piece a start dans la grille si possible
void		ft_put_piece(char **grid, t_point *start, t_tris *piece);

//Verifi que piece peut etre place dans grille a start
short		ft_is_putable(char **grid, t_point *start, t_tris *piece);

//Renvoi la taille du pls grand carre rempli dans la grille sans '.'
short		ft_find_len(char **grid);

//Copi une grille de taille len a partir de la grille envoyee cette fonction segfault quand lenvie lui en prend.
char		**ft_copy_grid(char **grid, short len);

//Dit si un point est un start ou pas
int			ft_is_start(char **grid, short x, short y);

//Renvoi la liste des starts de la grille
t_point		*ft_give_starts(char **grid);

t_point		*ft_new_element(short i, short j);

void		ft_add_list(t_point *list, t_point *element);

void		ft_print_list(t_point *lst);

#endif
