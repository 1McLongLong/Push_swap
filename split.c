/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:15:09 by touahman          #+#    #+#             */
/*   Updated: 2024/01/05 22:08:06 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	count_words(char *str, char c)
{
	int	word_flag;
	int	count;

	count = 0;
	word_flag = 0;
	if (check_space(str))
		return (1);
	while (*str)
	{
		if (*str == c)
			word_flag = 0;
		else if (word_flag == 0)
		{
			word_flag = 1;
			count++;
		}
		str++;
	}
	return (count);
}

static	void	free_string(char **str, int word_count)
{
	int	i;

	i = word_count;
	while (i)
	{
		i--;
		free(str[i]);
	}
	free(str);
}

static char	*my_ft_strdup(const char *str, int len)
{
	int		i;
	char	*copy;

	copy = (char *)malloc(len + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static void	fill_result(char **result, char const *s, char c, int word_count)
{
	int	i;
	int	len;

	i = 0;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		result[i] = my_ft_strdup(s, len);
		s += len;
		i++;
	}
}

char	**split(char *s, char c)
{
	int		i;
	int		words_count;
	char	**full_str;

	if (s == NULL)
		return (NULL);
	words_count = count_words(s, c);
	full_str = malloc(sizeof(char *) * (words_count + 1));
	if (full_str == NULL)
		return (NULL);
	fill_result(full_str, s, c, words_count);
	full_str[words_count] = NULL;
	i = 0;
	while (i < words_count)
	{
		if (!full_str[i])
		{
			free_string(full_str, words_count);
			return (NULL);
		}
		i++;
	}
	return (full_str);
}
