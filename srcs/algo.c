


#include "ft_header.h"
#include <stdio.h>
#include <stdlib.h>


int		ft_min(int str_g, int str_h, int str_hg)
{
	if (str_g < str_h && str_g < str_hg)
		return (str_g);
	else if (str_h < str_g && str_h < str_hg)
		return (str_h);
	else if (str_hg < str_g && str_hg < str_h)
		return (str_hg);
	return (0); 
}

void		tab_int_verif(int *tab)
{
	int i;

	i = 0;
	while (i < 10)
	{
		printf(" %d", tab[i]);
		i++;
	}

}

void	find_square(char **tab)
{
	int		i;
	int		j;
	int 	*tab_int;
	int a;
	int resultat;

	resultat = 0;
	i = 0;
	while (tab[i])
	{
		j = 0;
		tab_int = malloc(sizeof(int) * ft_strlen(&tab[i][j]));
		if (tab_int == NULL)
			return ;
		while (tab[i][j])
		{
			
			printf(" %c", tab[i][j]);
			if (i == 0 && tab[i][j])
			{
				if (tab[i][j] == 'o')
					tab_int[j] = 0;
				else
					tab_int[j] = 1;
			}
			else if (tab[i][j] == 'o')
				resultat = 0;
			else if (j == 0 && tab[i][j])
			{
				resultat = 1;
				tab_int[j] = 1;
			}	
			else if (a != 0 && tab_int[j] != 0 && tab_int[j - 1] != 0)
				resultat = ft_min(a, tab_int[j], tab_int[j - 1]) + 1;
			else
				resultat = 1;
			
			//		tab_int_verif(tab_int);
			tab_int[i - 1] = a;		
			a = resultat;
			j++;
		}
		tab_int_verif(tab_int);
		printf("\n");
		i++;
	}	
}

