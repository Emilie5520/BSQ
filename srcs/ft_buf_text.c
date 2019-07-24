/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:34:32 by edouvier          #+#    #+#             */
/*   Updated: 2019/07/23 16:35:23 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

#define BUF_SIZE 4096

int     ft_buf_text(char *text)
{
	int   fd;
	char  buf[BUF_SIZE +1];
	int ret;	
	int size;
	
	fd = open(text, O_RDONLY);
	if (fd == -1)
	{
		write(2, "open error\n", 11);
		exit(0);
	}
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		size = ret;
	}
	printf("%d\n", size);
	close(fd);
	return (size);
}
