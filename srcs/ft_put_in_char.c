/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_in_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:18:30 by edouvier          #+#    #+#             */
/*   Updated: 2019/07/24 20:40:54 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	display_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

void	ft_tab_char(int x, int y, int max, t_env *e)
{
	int	i;
	int	j;

	i = y;
	j = x;
	while (i > y - max)
	{
		while (j > x - max)
		{
			e->tab_number[i][j] = e->char_result;
			j--;
		}
		j = x;
		i--;
	}
}

char	**ft_put_in_char(int **tab_int, char **tab_char, t_env *e)
{
	int		max;
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	max = 0;
	while (i < ft_tablen(tab_char))
	{
		j = 0;
		while (j++ < ft_strlen(tab_char[i]))
		{
			if (max < tab_int[i][j])
			{
				max = tab_int[i][j];
				x = j;
				y = i;
			}
		}
		i++;
	}
	ft_tab_char(x, y, max, e);
	display_tab(tab_char);
	return (tab_char);
}
