#include "../include/aoc.h"
#include <memory.h>

size_t	ft_strclen(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

static size_t	ft_wcount(char const *s, char c)
{
	size_t	i;
	size_t	wcount;

	wcount = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			wcount++;
		while (s[i] != c && s[i + 1])
			i++;
		i++;
	}
	return (wcount);
}

static void	ft_clean(char **out)
{
	size_t	i;

	i = 0;
	while (out[i] != NULL)
	{
		free(out[i]);
		i++;
	}
	free (out);
	return ;
}

static char	**ft_array(size_t wcount, char const *s, char c, char **out)
{
	size_t	lcount;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < wcount)
	{
		while (s[j] == c)
			j++;
		lcount = ft_strclen(&s[j], c);
		out[i] = (char *)calloc(lcount + 1, sizeof(char));
		if (!out[i])
		{
			ft_clean(out);
			return (NULL);
		}
		ft_strlcpy(out[i], &s[j], lcount + 1);
		j += lcount + 1;
		i++;
	}
	return (out);
}

char	**ft_split(char const *s, char c)
{
	size_t	wcount;
	char	**out;

	wcount = ft_wcount(s, c);
	out = (char **)calloc(wcount + 1, sizeof(char *));
	if (!out)
		return (NULL);
	out = ft_array(wcount, s, c, out);
	return (out);
}