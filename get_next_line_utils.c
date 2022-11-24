/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:29:54 by ttalvenh          #+#    #+#             */
/*   Updated: 2022/11/24 13:30:20 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
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
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s1_dup;

	if (!n)
		return (NULL);
	s1_dup = (char *)malloc(sizeof(char) * (n + 1));
	if (s1_dup == NULL)
		return (NULL);
	ft_strlcpy(s1_dup, s1, n + 1);
	return (s1_dup);
}

void	ft_strlcat(char *dst, const char *src, size_t dstsize, size_t dst_len)
{
	if (dstsize != 0 && dstsize > dst_len)
	{
		dst += dst_len;
		while ((dstsize - dst_len - 1) != 0 && *src != '\0')
		{
			*dst = *src;
			dst++;
			src++;
			dstsize--;
		}
		*dst = '\0';
	}
}
