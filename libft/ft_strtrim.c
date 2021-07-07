/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:07:26 by budelphi          #+#    #+#             */
/*   Updated: 2021/01/22 17:48:33 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_set(char s, char *set)
{
	int		flag;
	size_t	i;

	i = 0;
	flag = 0;
	while (set[i] != '\0')
	{
		if (s == set[i])
			flag = 1;
		i++;
	}
	return (flag);
}

char		*ft_strtrim(char *str, char *set)
{
	size_t	end_index;
	size_t	start_index;

	end_index = 0;
	start_index = 0;
	if (!str)
		return (NULL);
	end_index = ft_strlen(str);
	end_index = (end_index == 0) ? 0 : --end_index;
	while (ft_find_set(str[start_index], set) == 1 && start_index <= end_index)
		start_index++;
	while (ft_find_set(str[end_index], set) == 1 && end_index > start_index)
		end_index--;
	return (ft_substr(str, start_index, end_index - start_index + 1));
}
