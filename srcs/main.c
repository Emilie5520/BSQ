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

#include "ft_header.h"

void	map_error()
{
	ft_putstr("map error");
	ft_putchar('\n');
	exit(0);
}

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
void	check_tab(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\n' && str[i] != 'o' && str[i] != 'x' && str[i] != '.')
			map_error();
		i++;
	}
}

void	check_lines(char **tab_number, int size, int i, int nb_lines)
{
	if(tab_number[0])
		size = ft_strlen(tab_number[0]);
	i = 0;
	while (tab_number[i])
	{
		ft_putstr(tab_number[i]);
		ft_putchar('\n');
		check_tab(tab_number[i]);
		if (ft_strlen(tab_number[i]) != size)
			map_error();
		i++;
	}
	if (i != nb_lines)
		map_error();
}

int		main(int argc, char **argv)
{
	int		size;
	char 		*tab;
	char		**tab_number;
	int		i;
	int		nb_lines;

	i = 0;
	if (argc != 2)
		return (0);
	size = ft_buf_text(argv[1]);
	tab = ft_put_in_tab(size, argv[1]);
	nb_lines = atoi(tab);
	if (nb_lines == 0)
		map_error();
	while (tab[i] !=  '\n')
		i++;
	i++;
	tab_number = ft_split(tab + i, "\n");
	i = 0;
	check_lines(tab_number, size, i, nb_lines);
	find_square(tab_number);
//	printf("%s\n", tab_number);
}
