/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:51:02 by adespond          #+#    #+#             */
/*   Updated: 2015/12/18 15:44:55 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void	fillit(int *argc, char **argv)
{
	t_conf	*conf;

	conf = init_conf();
	if (*argc == 2)
	{
		if ((conf = open_file(argv[1], conf)) != NULL)
		{
			conf->grid = ft_new_grid(conf->nbr_piece * 4);
			conf->min_size = conf->nbr_piece * 4 + 1;
			permute_tris(conf, 0);
			ft_print_grid(conf->grid);
			return ;
		}
	}
	ft_putstr("error\n");
}
