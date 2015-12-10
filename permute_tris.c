/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permute_tris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 10:32:56 by adespond          #+#    #+#             */
/*   Updated: 2015/12/09 14:08:01 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		reverse_tris(t_conf *conf)
{
	int		i;
	
	i = 0;
	while (i <= (conf->nbr_piece - 1) / 2)
	{
		swap_tris(conf, i, conf->nbr_piece - i - 1);
		printf("\n\n %d, %d\n\n", i, conf->nbr_piece - i - 1);
		i++;
	}
}

void		testSalut(t_conf *conf)
{
	int i;

	i = 0;

	while (i < conf->nbr_piece)
	{
		ft_putchar(conf->list_tris[i].name);
		i++;
	}
		ft_putchar('\n');
}

void		permute_tris(t_conf *conf, int index)
{
	int		j;

	j = index;
	if (index == conf->nbr_piece - 1)
	{
		testSalut(conf);
		ft_fillit(conf);
	}
	else
	{
		while (j < conf->nbr_piece)
		{
			swap_tris(conf, index, j);
			permute_tris(conf, index + 1);
			swap_tris(conf, index, j);
			j++;
		}
	}
}

void		swap_tris(t_conf *conf, int a, int b)
{
	t_tris	tmp;

	tmp = conf->list_tris[a];
	conf->list_tris[a] = conf->list_tris[b];
	conf->list_tris[b] = tmp;
}
