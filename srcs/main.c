/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 10:56:03 by edouvier          #+#    #+#             */
/*   Updated: 2019/07/23 16:47:49 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_header.h"

int		main(int argc, char **argv)
{
	int		size;
	char 	*tab;
	char	**tab_number;
	int		i;

	i = 0;
	if (argc != 2)
		return (0);
	size = ft_buf_text(argv[1]);
	tab = ft_put_in_tab(size, argv[1]);
	while (tab[i] !=  '\n')
		i++;
	i++;
	tab_number = ft_split(tab + i, "\n");
	find_square(tab_number);
//	printf("%s\n", tab_number);
}
