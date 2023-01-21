/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:03:45 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/21 16:49:07 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_3(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero_2(void *s, size_t n)
{
	unsigned char	*var;
	size_t			i;

	i = 0;
	var = (unsigned char *)s;
	while (i < n)
	{
		var[i] = '\0';
		i++;
	}
}

void	*ft_calloc_2(size_t count, size_t size)
{
	void	*str;

	if (!count || !size)
		return (malloc(0));
	str = malloc(count * size);
	if (!str)
		return (NULL);
	ft_bzero_2(str, count * size);
	return (str);
}

char	*ft_strchr_2(char *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen_3(str);
	while (i <= len)
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

void	ft_strlcpy_2(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}
