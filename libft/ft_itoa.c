/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:09:55 by budelphi          #+#    #+#             */
/*   Updated: 2021/01/20 22:36:50 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Что делает функция:		Переводит число в строку символов.
**
** Возращаемое значение:	Указатель на строку с числом.
**
** Особенности:				Работает с long int чтобы избежать переполнения.
*/

static int		ft_lennbr(long nbr)
{
	int		len;

	len = 0;
	if (nbr == 0)
		len++;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		len++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	long int	nbr;
	char		*str;
	int			i;

	nbr = n;
	i = ft_lennbr(nbr);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (nbr == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * -1;
	}
	while (nbr > 0)
	{
		str[i--] = 48 + (nbr % 10);
		nbr = nbr / 10;
	}
	return (str);
}
