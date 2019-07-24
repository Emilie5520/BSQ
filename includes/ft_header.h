/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:56:48 by edouvier          #+#    #+#             */
/*   Updated: 2019/07/24 11:30:39 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct	s_env
{
	int	nb_lines;
	char	*charset;
}		t_env;

void		ft_putstr(char *str);
void		ft_putchar(char c);
int			ft_strlen(char *str);
char		*ft_strdup(char *src);
int			ft_atoi(char *str);
void		ft_display_file(char *file);
int			main(int argc, char **argv);
int    		ft_buf_text(char *text);
char   		*ft_put_in_tab(int size, char *text);
void		find_square(char **tab);
char 		**ft_split(char *str, char *charset);
int			**create_tabint(char **tab);
int			ft_tablen(char **tab);

#endif
