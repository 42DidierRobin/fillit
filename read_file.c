/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:01:06 by adespond          #+#    #+#             */
/*   Updated: 2015/12/08 16:45:40 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_conf	*open_file(char *file, t_conf *conf)
{
	int		fd;

	fd = open(file, O_DIRECTORY);
	//check si c'est un dossier, et retourn 1 si oui
	if (fd >= 0)
		return (NULL);
	fd = open(file, O_RDONLY);
	//si fd vaut 1, c'est que l'ouverture du fichier a merder
	if (fd < 0)
		return (NULL);
	if ((conf = read_file(&fd, conf)) == 0)
		return (NULL);
	return (conf);
}

t_conf	*read_file(int *fd, t_conf *conf)
{
	char	*buff;
	int		i;
	t_tris	*tris;

	i = 0;
	buff = ft_strnew(21);
	if (!buff)
		return (NULL);
	//lit une piece (21 carctere)
	while (read(*fd, buff, 21))
	{
		tris = create_tris(buff, i);
		if (tris == NULL)
			return (NULL);
		conf->nbr_piece = i + 1;
		conf->list_tris[i] = *tris;
		i++;
	}
	return (conf);
}
