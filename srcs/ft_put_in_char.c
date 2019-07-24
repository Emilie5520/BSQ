/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_in_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:18:30 by edouvier          #+#    #+#             */
/*   Updated: 2019/07/24 17:01:15 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

char 		**ft_tab_char(char **tab_char, int x,int y, int max)
{
	int		i;
	int 	j;

	i = 0;
	j = 0;
	while (tab_char[i])
	{
		while (tab_char[i][j])
		{
			if (i == y && j == x)
			{
				i = max;
				while (i > 0)
				{
					j = max;
					while (j > 0)
					{	
						tab_char[i][j] = 'x';
						j--;
					}
					i--;
				}
			}
			j++;
		}
		i++;
	}
	return (tab_char);
}



char 		**ft_put_in_char(int **tab_int, char **tab_char)
{
	int		max;
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	max = 0;
	while (tab_int[i])
	{
		j = 0;
		while (tab_int[i][j])
		{
			if (max < tab_int[i][j])
			{
				max = tab_int[i][j];
				x = j;
				y = i;
			}
			j++;	
		}	
		i++;
	}
	ft_tab_char(tab_char, x, y, max);
	i = 0;
//	while (i < ft_tablen(tab_char))
//	{
//		j = 0;
//		while (j < ft_strlen(tab_char[i]))
//		{
//			printf("%d", tab_char[i][j]);
//			j++;
//		}
//		printf("%c", '\n');
//		i++;
//	}
	return (tab_char);
}
