/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:15:53 by edouvier          #+#    #+#             */
/*   Updated: 2019/07/24 22:23:21 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

char	*read_stdin(void)
{
	char	buff[4098];
	size_t	ret;
	char	*input;

	while ((ret = read(STDIN_FILENO, buff, 4096)) > 0)
	{
		if (ret)
		{
			buff[ret - 1] = '\n';
			buff[ret] = '\0';
			input = ft_strjoin(input, buff);
		}
	}
	return (input);
}

void	define_chars(t_env *e)
{
	int	i;

	i = 0;
	while (e->tab[i] && (e->tab[i] >= '0' && e->tab[i] <= '9'))
		i++;
	e->char_empty = e->tab[i];
	e->char_block = e->tab[i + 1];
	e->char_result = e->tab[i + 2];
}

void	check_args(int argc, t_env *e, char **argv)
{
	int 	i;

	i = 1;
	if (argc < 2)
		e->tab = read_stdin();
	else
	{
		while (i < argc - 1)
		{
			e->size = ft_buf_text(argv[i]);
			e->tab = ft_put_in_tab(e->size, argv[i]);
			i++;
		}
	}
	if (!e->tab)
		map_error();
}

int		main(int argc, char **argv)
{
	t_env	e;
	int		i;
	int		j;

	i = 0;
	j = 0;
	check_args(argc, &e, argv);
	e.nb_lines = ft_atoi(e.tab);
	define_chars(&e);
	if (e.nb_lines == 0)
		map_error();
	while (e.tab[i] != '\n')
		i++;
	i++;
	e.tab_number = ft_split(e.tab + i, "\n");
	i = 0;
	check_lines(e.tab_number, &e.size, i, &e);
	e.tabint = create_tabint(e.tab_number, e);
	e.tabint = find_square(e.tab_number, e);
	ft_put_in_char(e.tabint, e.tab_number, &e);
	return (0);
}
