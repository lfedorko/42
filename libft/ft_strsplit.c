/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:27:15 by lfedorko          #+#    #+#             */
/*   Updated: 2016/12/07 17:05:08 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count_words(const char *s, char c)
{
	int			word;
	int			count;

	count = 0;
	word = 0;
	while (s[count] == c && s[count] != '\0')
		count++;
	while (s[count] != '\0')
	{
		if (s[count] != c && (s[count + 1] == c || s[count + 1] == '\0'))
		{
			word++;
			count++;
		}
		else
			count++;
	}
	return (word);
}

static	char	**ft_split(char **arr, int i, const char *s, char c)
{
	int			t;
	int			begin;
	int			curr;

	t = 0;
	curr = 0;
	while (s[t] != '\0' && curr < i)
	{
		if (s[t] != c)
		{
			begin = t;
			while (s[t] != c && s[t] != '\0')
				t++;
			arr[curr] = ft_strsub(s, begin, t - begin);
			curr++;
		}
		t++;
	}
	arr[curr] = 0;
	return (arr);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**arr;
	int			i;
	int			t;

	t = 0;
	if (s == NULL)
		return (NULL);
	i = ft_count_words(s, c);
	arr = (char **)malloc((i + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	arr = ft_split(arr, i, s, c);
	return (arr);
}
