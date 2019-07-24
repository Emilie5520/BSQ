/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_in_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:14:34 by edouvier          #+#    #+#             */
/*   Updated: 2019/07/24 22:14:38 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

char	*ft_put_in_tab(int size, char *text)
{
	int		fd;
	char	*buf;
	int		ret;

	if (!(buf = malloc(sizeof(char) * size + 1)))
		return (0);
	fd = open(text, O_RDONLY);
	if (fd == -1)
		map_error();
	ret = read(fd, buf, size);
	buf[ret] = '\0';
	close(fd);
	return (buf);
}
