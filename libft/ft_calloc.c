/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:02:26 by adjoly            #+#    #+#             */
/*   Updated: 2023/12/18 08:40:14 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <complex.h>

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
