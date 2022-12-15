#include "../include/aoc.h"
#include <memory.h>
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	srclen;

	srclen = strlen(src);
	if (!n)
		return (srclen);
	if (srclen + 1 < n)
		memcpy(dst, src, srclen + 1);
	 else if (n != 0)
	{
		memcpy(dst, src, n - 1);
		dst[n - 1] = '\0';
	}
	return (srclen);
}

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	strlen;

	strlen = ft_strlen(s);
	if (start > strlen)
		return (strdup(""));
	if (len > strlen - start)
		return (strdup(s + start));
	sub = (char *)calloc(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, &s[start], len + 1);
	sub[len] = '\0';
	return (sub);
}
