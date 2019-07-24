#include "ft_header.h"

int		**create_tabint(char **tab)
{
		int		**tabint;
		int		size;
		int		i;
		int		j;

		i = 0;
		j = 0;
		size = ft_tablen(tab);
		tabint = (int**)malloc(sizeof(int*) * size);
		while (i < size)
		{
			tabint[i] = (int*)malloc(sizeof(int) * ft_strlen(tab[i]));
			j = 0;
			while (tab[i][j])
			{
				if (tab[i][j] == '.')
					tabint[i][j] = 1;
				else if (tab[i][j] == 'o')
					tabint[i][j] = 0;
				j++;
			}
			i++;
		}
		return (tabint);
}

int	ft_min(int str_g, int str_h, int str_hg)
{
	int min;

	min = str_g;
	if (min > str_h)
		min = str_h;
	if (min > str_hg)
		min = str_hg;
	return (min); 
}

int		**find_square(char **tab)
{
	int		i;
	int		j;
	int 	**tab_int;
	
	tab_int = create_tabint(tab);
	i = 1;
	while (i < ft_tablen(tab))
	{
		j = 1;
		while (j < ft_strlen(tab[i]))
		{
			tab_int[i][j] = tab_int[i][j] * (ft_min(tab_int[i -1][j], tab_int[i - 1][j - 1], tab_int[i][j - 1]) + 1);
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < ft_tablen(tab))
	{
		j = 0;
		while (j < ft_strlen(tab[i]))
		{
			printf("%d ", tab_int[i][j]);
			j++;
		}
		printf("%c", '\n');
		i++;
	}
	return (tab_int);
}

