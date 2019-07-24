/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:43:51 by edouvier          #+#    #+#             */
/*   Updated: 2019/07/24 21:43:56 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_env
{
	int			size;
	char		*tab;
	char		**tab_number;
	int			i;
	int			nb_lines;
	int			**tabint;
	char		*charset;
	char		char_empty;
	char		char_block;
	char		char_result;
}				t_env;

void			ft_putstr(char *str);
void			ft_putchar(char c);
int				ft_strlen(char *str);
char			*ft_strdup(char *src);
int				ft_atoi(char *str);
void			ft_display_file(char *file);
int				main(int argc, char **argv);
int				ft_buf_text(char *text);
char			*ft_put_in_tab(int size, char *text);
int				**find_square(char **tab, t_env e);
char			**ft_split(char *str, char *charset);
int				**create_tabint(char **tab, t_env e);
int				ft_tablen(char **tab);
void			map_error();
char			**ft_put_in_char(int **tab_int, char **tab_char, t_env *e);
void			map_error();
void			check_tab(char *str, t_env *e);
void			check_lines(char **tab_number, int size, int i, t_env *e);
char			*ft_strjoin(char *s1, char *s2);

#endif
