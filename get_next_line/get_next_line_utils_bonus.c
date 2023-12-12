/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:12:02 by adjoly            #+#    #+#             */
/*   Updated: 2023/12/08 17:54:32 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	result = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (result == NULL)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	result[i] = '\0';
	return (result);
}

size_t	ft_strlcpy(char	*dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[size] = '\0';
	return (ft_strlen(src));
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if ((int)size < 0 && (int)nmemb < 0)
		return (NULL);
	if ((unsigned long long)(size * nmemb) > 4294967295)
		return (NULL);
	str = malloc(nmemb * size);
	if (!str)
		return (NULL);
	while (i < (nmemb * size))
	{
		*(unsigned char *)(str + i) = '\0';
		i++;
	}
	return (str);
}
