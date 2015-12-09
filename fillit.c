/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:51:02 by adespond          #+#    #+#             */
/*   Updated: 2015/12/09 14:10:42 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit(int *argc, char **argv)
{
	t_conf	*conf;

	conf = init_conf();
	if (*argc == 2)
	{
		if ((conf = open_file(argv[1], conf)) != NULL)
		{
			testmescouilles(conf);
			//reverse_tris(conf);
			testmescouilles(conf);
			conf->min_size = 4 * conf->nbr_piece;
			permute_tris(conf, 0);
			//ft_fillit(conf);
			ft_print_grid(conf->grid);
			return ;
		}
	}
	else
		ft_putstr("pas 1 argument\n");
	ft_putstr("error\n");	
}

void	testmescouilles(t_conf *conf)
{
	int		i;
	int		y;

	i = -1;
	ft_putstr("\n--------------------------");
	ft_putstr("\n-----Affichage de conf----");
	ft_putstr("\nnbr_piece (+1) : ");
	ft_putnbr(conf->nbr_piece);
	while (++i < conf->nbr_piece)
	{
		y = -1;
		ft_putstr("\npiece ");
		ft_putnbr(i);
		ft_putchar('\n');
		while (++y < 4)
		{
			ft_putstr("\n    (");
			ft_putnbr(conf->list_tris[i].coord[y].x);
			ft_putstr(")(");
			ft_putnbr(conf->list_tris[i].coord[y].y);
			ft_putstr(")");
		}
	}
	ft_putstr("\n--------------------------\n\n");
}
