/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:04:58 by edouvier          #+#    #+#             */
/*   Updated: 2019/07/24 20:50:04 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
#include <stdlib.h>

int		is_charset(char *charset, char c)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int		ft_strlen_split(char *src, char *charset)
{
	int		i;

	i = 0;
	while (src[i] != '\0' && (is_charset(charset, src[i]) == 0))
		i++;
	return (i);
}

char	*ft_strdup_split(char *src, char *charset)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen_split(src, charset) + 1));
	if (dest == NULL)
		return (NULL);
	while (src[i] != '\0' && (is_charset(charset, src[i]) == 0))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		count_words(char *str, char *charset)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (is_charset(charset, str[i]) == 0 &&
				(is_charset(charset, str[i + 1]) == 1 || str[i + 1] == '\0'))
		{
			count += 1;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**res;
	int		nb_words;

	i = 0;
	j = 0;
	if (str == 0 || charset == 0)
		return (NULL);
	nb_words = count_words(str, charset);
	res = malloc(sizeof(char*) * nb_words + 1);
	if (res == 0)
		return (NULL);
	while (i < nb_words)
	{
		while (str[j] && is_charset(charset, str[j]) == 1)
			j++;
		res[i] = ft_strdup_split(&str[j], charset);
		while (str[j] && is_charset(charset, str[j]) == 0)
			j++;
		i++;
	}
	res[i] = NULL;
	return (res);
}
