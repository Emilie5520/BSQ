/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:47:43 by edouvier          #+#    #+#             */
/*   Updated: 2019/07/24 21:47:47 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	map_error(void)
{
	ft_putstr("map error");
	ft_putchar('\n');
	exit(0);
}

int		ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	check_tab(char *str, t_env *e)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\n' && str[i] != e->char_block
			&& str[i] != e->char_result && str[i] != e->char_empty)
			map_error();
		i++;
	}
}

void	check_lines(char **tab_number, int size, int i, t_env *e)
{
	if (tab_number[0])
		size = ft_strlen(tab_number[0]);
	i = 0;
	while (tab_number[i])
	{
		check_tab(tab_number[i], e);
		if (ft_strlen(tab_number[i]) != size)
			map_error();
		i++;
	}
	if (i != e->nb_lines)
		map_error();
}
