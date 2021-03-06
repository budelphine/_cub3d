/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 15:25:22 by budelphi          #+#    #+#             */
/*   Updated: 2021/01/22 16:38:50 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Что делает функция:		Находит последнее вхождение символа в строке.
**
** Возращаемое значение:	(char *) Указатель на последнее вхождение
**							символа в строке. Иначе NULL.
**
** Особенности:				Нет.
*/

char	*ft_strrchr(char *str, int ch)
{
	char	*res;
	char	c;

	res = (char *)str + ft_strlen((char *)str);
	c = (char)ch;
	while (res >= str)
	{
		if (*res == c)
			return (res);
		res--;
	}
	return (NULL);
}
