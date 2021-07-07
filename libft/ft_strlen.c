/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:43:39 by budelphi          #+#    #+#             */
/*   Updated: 2021/01/22 16:33:36 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Что делает функция:		Считает кол-во символов в строке.
**
** Возращаемое значение:	(size_t) Кол-во символов в строке.
**
** Особенности:				Нет.
*/

size_t	ft_strlen(char *str)
{
	size_t len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
