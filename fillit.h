/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:47:01 by adespond          #+#    #+#             */
/*   Updated: 2015/12/02 17:33:18 by adespond         ###   ########.fr       */
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
	struct s_tris	list_tris[26];
	char			nbr_piece;
}					t_conf;

char				open_file(char *file);
char				read_file(int *fd);
void				fillit(int *argc, char **argv);
char				create_tris(char *str, char name);
void				create_tris_coord(t_tris *tris, int nbr, int i);
char				check_tris(t_tris *tris);
t_tris				*init_tris(char name);
#endif
