/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:11:27 by edouvier          #+#    #+#             */
/*   Updated: 2019/07/23 12:09:20 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	ft_display_file(char *file)
{
	int		fd;
	char	buf;
	char	*tab;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Cannot read file.\n", 18);
		return;
	}
	while (read(fd, &buf, 1))
		write(1, &buf, 1);
	tab = ft_strdup(file);
	close(fd);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
		ft_display_file(argv[1]);
	return (0);
}
