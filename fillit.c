/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:51:02 by adespond          #+#    #+#             */
/*   Updated: 2015/12/02 14:36:21 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit(int *argc, char **argv)
{
	if (*argc == 2)
	{
		if (open_file(argv[1]) == 1)
		{
			return ;
		}
	}
	else
	{
		ft_putstr("pas 1 argument\n");
	}
	ft_putstr("error\n");	
}
