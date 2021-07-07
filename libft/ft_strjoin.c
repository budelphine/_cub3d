/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:06:55 by budelphi          #+#    #+#             */
/*   Updated: 2021/01/22 17:50:26 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*newstr;

	i = 0;
	j = 0;
	len = 0;
	if (str1 == NULL || str2 == NULL)
		return (NULL);
	len = ft_strlen(str1) + ft_strlen(str2);
	if (!(newstr = (char *)malloc(sizeof(*newstr) * (len + 1))))
		return (NULL);
	while (str1[i] != '\0')
	{
		newstr[i] = str1[i];
		i++;
	}
	while (str2[j] != '\0')
	{
		newstr[i + j] = str2[j];
		j++;
	}
	newstr[i + j] = '\0';
	return (newstr);
}
