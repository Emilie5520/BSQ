/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:34:32 by edouvier          #+#    #+#             */
/*   Updated: 2019/07/24 21:10:41 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
#define BUFF_SIZE 4096

int		ft_buf_text(char *text)
{
	int		fd;
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		size;

	size = 0;
	fd = open(text, O_RDONLY);
	if (fd == -1)
		map_error();
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		size += ret;
	}
	close(fd);
	return (size);
}
