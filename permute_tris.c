/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permute_tris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 10:32:56 by adespond          #+#    #+#             */
/*   Updated: 2015/12/09 11:18:50 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		permute_tris(t_conf *conf, int index)
{
	int		j;

	j = index;
	if (index == conf->nbr_piece - 1)
		ft_fillit(conf);
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
