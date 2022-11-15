#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		*(char *)s = '\0';
		s++;
		n--;
	}
}


size_t	ft_strlen(const char *s)
{
	int	counter;

	counter = 0;
	while (*s)
	{
		counter++;
		s++;
	}
	return (counter);
}


size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	src_len;

	src_len = ft_strlen(src);
	if (dstsize)
	{
		while (dstsize - 1 != 0 && *src != '\0')
		{
			*dst = *src;
			dst++;
			src++;
			dstsize--;
		}
		*dst = '\0';
	}
	return (src_len);
}


char	*ft_strndup(const char *s1, size_t n)
{
	char	*s1_dup;
	size_t	s1_len;

	if (!n)
		return (NULL);
	s1_len = ft_strlen(s1);
	if (s1_len < n)
		s1_dup = (char *)malloc(sizeof(char) * (s1_len + 1));
	else
		s1_dup = (char *)malloc(sizeof(char) * (n + 1));
	if (s1_dup == NULL)
		return (NULL);
	ft_strlcpy(s1_dup, s1, n + 1);
	return (s1_dup);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstl;
	size_t	srcl;

	if (!(dst) && dstsize == 0)
		return (ft_strlen(src));
	dstl = ft_strlen(dst);
	srcl = ft_strlen(src);
	if (dstsize != 0 && dstsize > dstl)
	{
		dst += dstl;
		while ((dstsize - dstl - 1) != 0 && *src != '\0')
		{
			*dst = *src;
			dst++;
			src++;
			dstsize--;
		}
		*dst = '\0';
		return (srcl + dstl);
	}
	return (srcl + dstsize);
}