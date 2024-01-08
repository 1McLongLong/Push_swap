/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:08:32 by touahman          #+#    #+#             */
/*   Updated: 2024/01/06 13:09:40 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	*ft_strdup(char *s1)
{
	int		i;
	int		size;
	char	*copy;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1);
	copy = malloc(sizeof(char) * size + 1);
	if (copy == 0)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	ft_free(char **lst)
{
	int	i;

	i = 0;
	while (lst[i])
	{
		free(lst[i]);
		i++;
	}
	free(lst);
}

static int	argument_count(int argc, char **argv)
{
	int	args_count;
	int	index;

	args_count = 0;
	index = 1;
	while (index < argc)
	{
		args_count += count_words(argv[index], ' ');
		index++;
	}
	return (args_count);
}

static void	argument_list(char **args_list, int argc, char **argv)
{
	char	**list;
	int		index;
	int		i;
	int		j;

	j = 0;
	index = 0;
	while (++index < argc)
	{
		if (count_words(argv[index], ' ') == 1)
			args_list[j++] = ft_strdup(argv[index]);
		else if (count_words(argv[index], ' ') > 1)
		{
			i = -1;
			list = split(argv[index], ' ');
			while (list[++i])
			{
				args_list[j++] = ft_strdup(list[i]);
				free(list[i]);
			}
			free(list);
		}
	}
	args_list[j] = NULL;
}

char	**parse_args(int argc, char **argv)
{
	char	**args_list;
	int		args_count;

	args_count = argument_count(argc, argv);
	if (args_count > 0)
	{
		args_list = malloc(sizeof(char *) * (args_count + 1));
		if (!args_list)
			return (NULL);
	}
	else
		exit (1);
	argument_list(args_list, argc, argv);
	return (args_list);
}
