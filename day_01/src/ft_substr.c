#include <aoc.h>
#include <memory.h>
#include <string.h>

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
	strlcpy(sub, &s[start], len + 1);
	sub[len] = '\0';
	return (sub);
}