/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_room_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 07:04:30 by msassaro          #+#    #+#             */
/*   Updated: 2016/05/03 07:04:31 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** The fct returns the nb of room with the room->name in
** the env->room linked-list
*/

int		ft_room_occurs(t_lem *env, t_room *room)
{
	int		occurs;
	t_room	*tmp;

	tmp = env->room;
	occurs = 0;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, room->name) == 0)
			occurs++;
		tmp = tmp->nxt;
	}
	return (occurs);
}

/*
** It will return 1 if there is 2 rooms with the same name in the linked list
** 0 in other cases.
*/

int		ft_double_room_name(t_lem *env)
{
	t_room		*tmp;

	tmp = env->room;
	while (tmp)
	{
		if (ft_room_occurs(env, tmp) != 1)
			return (1);
		tmp = tmp->nxt;
	}
	return (0);
}

/*
** The fct returns the nb of room with the room locations in
** the env->room linked-list
*/

int		ft_location_occurs(t_lem *env, t_room *room)
{
	int		occurs;
	t_room	*tmp;

	tmp = env->room;
	occurs = 0;
	while (tmp)
	{
		if (tmp->x == room->x && tmp->y == room->y)
			occurs++;
		tmp = tmp->nxt;
	}
	return (occurs);
}

/*
** It will return 1 if there is 2 rooms with the same locations
** in the linked-list. 0 in other cases.
*/

int		ft_double_room_location(t_lem *env)
{
	t_room		*tmp;

	tmp = env->room;
	while (tmp)
	{
		if (ft_location_occurs(env, tmp) != 1)
			return (1);
		tmp = tmp->nxt;
	}
	return (0);
}
