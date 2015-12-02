/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:47:01 by adespond          #+#    #+#             */
/*   Updated: 2015/12/02 13:26:31 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_point
{
	char		x;
	char		y;
}				t_point;

typedef struct	s_tris
{
	char		name;
	t_point		coord[4];
}				t_tris;

typedef struct	s_conf
{
	char		**grid;
	s_tris		**piece;
	char		nbr_piece;
}				t_conf;
#endif
