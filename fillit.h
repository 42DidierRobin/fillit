/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:47:01 by adespond          #+#    #+#             */
/*   Updated: 2015/12/09 11:10:09 by rdidier          ###   ########.fr       */
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
	short			min_size;
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

void		ft_print_grid(char **tab);
char		**ft_new_grid(short nb_piece);
void		ft_put_piece(char **grid, t_point *start, t_tris *piece);
short		ft_is_putable(char **grid, t_point *start, t_tris *piece);
short		ft_find_len(char **grid);
char		**ft_copy_grid(char **grid, short len);
char		**ft_copy_grid_full(char **grid);
int			ft_is_start(char **grid, short x, short y);
t_point		*ft_give_starts(char **grid);
t_point		*ft_new_element(short i, short j);
void		ft_add_list(t_point *list, t_point *element);
void		ft_print_list(t_point *lst);
void		ft_fill_this_shit(char **grid, t_conf *config, short iter, t_point *starts);
void		ft_fillit(t_conf *config);

#endif
