/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:06:28 by budelphi          #+#    #+#             */
/*   Updated: 2021/01/22 17:47:11 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*substr;

	if (!str)
		return (NULL);
	i = 0;
	s_len = ft_strlen(str);
	if (!(substr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (s_len < ((size_t)start))
	{
		substr[0] = '\0';
		return (substr);
	}
	while (i < len)
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
