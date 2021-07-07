/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cub_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:26:02 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/13 18:54:56 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** Что делает функция:		Парсит параметры CUB MAP. Формирует список,
**							а затем переносит его в массив t_cub *cub.map
**
** Возвращаемое значение:	(int) '0'	-	Произошел парсинг.
** 							(int) '-1'	-	Произошла ошибка.
**
** Дополнительно:			Выводит сообщение об ошибке:
**							--> DOUBLE DECLARATION OF [CUB MAP]
**							-->  MALLOC ERROR IN [MAP]
**
** Особенности:				Сам чистит карту в случае ошибки.
**							Всегда чистит дерево, но не его содержимое,
**							если ошибок не произошло.
*/

static int	ft_check_double_declartion(t_cub *cub)
{
	int	res;

	res = 0;
	if (cub->map != NULL)
		res = ft_putstr_fd("--> DOUBLE DECLARATION OF [CUB MAP]\n", 2);
	return (res);
}

static int	ft_clear_lst_map(char *tmp_line, t_list **head)
{
	ft_lstclear(head, &free);
	free(tmp_line);
	return (ft_putstr_fd("-->  MALLOC ERROR IN [MAP]\n", 2));
}

static int	ft_make_map(t_cub *cub, t_list **head, int size)
{
	int		i;
	char	**map;
	t_list	*tmp_head;

	tmp_head = *head;
	i = -1;
	if (!(map = ft_calloc(size + 1, sizeof(char *))))
	{
		ft_lstclear(head, &free);
		return (ft_putstr_fd("-->  MALLOC ERROR IN [MAP]\n", 2));
	}
	while (tmp_head)
	{
		map[++i] = tmp_head->content;
		tmp_head = tmp_head->next;
	}
	cub->map = map;
	ft_lstclear(head, NULL);
	return (0);
}

int			ft_parse_map_to_lst(char **line, t_list **head, int fd)
{
	t_list	*t_tmp;
	char	*tmp;
	int		gnl;

	gnl = 0;
	t_tmp = NULL;
	if (!(tmp = ft_strdup(*line)))
		return (ft_putstr_fd("-->  MALLOC ERROR IN [MAP]\n", 2));
	if (!(*head = ft_lstnew(tmp)))
		return (ft_putstr_fd("-->  MALLOC ERROR IN [MAP]\n", 2));
	while ((gnl = get_next_line(fd, &tmp)) > 0)
	{
		if (!(t_tmp = ft_lstnew(tmp)))
			return (ft_clear_lst_map(tmp, head));
		ft_lstadd_back(head, t_tmp);
	}
	if (gnl == -1)
		return (ft_clear_lst_map(tmp, head));
	if (!(t_tmp = ft_lstnew(tmp)))
		return (ft_clear_lst_map(tmp, head));
	ft_lstadd_back(head, t_tmp);
	return (0);
}

int			ft_parse_cub_map(char **line, t_cub *cub, int fd)
{
	t_list	*head;

	head = NULL;
	if (ft_check_double_declartion(cub) == -1)
		return (-1);
	if (ft_parse_map_to_lst(line, &head, fd) == -1)
		return (-1);
	if (ft_make_map(cub, &head, ft_lstsize(head)) == -1)
		return (-1);
	return (0);
}
