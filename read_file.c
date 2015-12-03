/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:01:06 by adespond          #+#    #+#             */
/*   Updated: 2015/12/02 15:46:00 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	open_file(char *file)
{
	int		fd;

	fd = open(file, O_DIRECTORY);
	//check si c'est un dossier, et retourn 1 si oui
	if (fd >= 0)
		return (0);
	fd = open(file, O_RDONLY);
	//si fd vaut 1, c'est que l'ouverture du fichier a merder
	if (fd < 0)
		return (0);
	if (read_file(&fd) == 0)
		return (0);
	return (1);
}

char	read_file(int *fd)
{
	char	*buff;
	char	i;

	i = 0;
	buff = ft_strnew(21);
	if (!buff)
		return (0);
	//lit une piece (21 carctere)
	while (read(*fd, buff, 21))
	{
		if (create_tris(buff, i) == 0)
			return (0);
		ft_putstr(buff);
		ft_putstr("------\n");
		i++;
	}
	return (1);
}
