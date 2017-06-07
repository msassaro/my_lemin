/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 07:04:51 by msassaro          #+#    #+#             */
/*   Updated: 2016/05/03 07:04:51 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_check_redefine_room_exist(t_lem *e)
{
	t_room		start;
	t_room		end;

	start.name = e->new_start;
	end.name = e->new_end;
	if (ft_room_occurs(e, &start) && ft_room_occurs(e, &end))
		return (1);
	return (0);
}

/*
** this will find the location of end and start on the matrix, then
** we store those values in env as int (row nb)
*/

void	ft_find_start_end_value(t_lem *env)
{
	int		i;

	i = -1;
	if (env->redefine && ft_check_redefine_room_exist(env))
	{
		while (++i < env->roomlen)
		{
			if (!ft_strcmp(env->room_tab[i]->name, env->new_start))
				env->start_nb = i;
			else if (!ft_strcmp(env->room_tab[i]->name, env->new_end))
				env->end_nb = i;
		}
	}
	else
	{
		while (++i < env->roomlen)
		{
			if (!ft_strcmp(env->room_tab[i]->name, env->start.name))
				env->start_nb = i;
			else if (!ft_strcmp(env->room_tab[i]->name, env->end.name))
				env->end_nb = i;
		}
	}
}

/*
** Creation of room tab. We want an array of t_room instead of a list.
** We take the list and creates an array from it.
*/

void	ft_create_room_tab(t_lem *env)
{
	int		i;
	t_room	*tmp;
	int		roomlen;

	i = -1;
	tmp = env->room;
	roomlen = ft_len_room(env->room);
	env->room_tab = (t_room**)malloc(sizeof(t_room*) * 2000);
	while (++i < roomlen && tmp)
	{
		env->room_tab[i] = (t_room*)malloc(sizeof(t_room));
		if (env->room_tab[i])
		{
			env->room_tab[i]->name = tmp->name;
			env->room_tab[i]->x = tmp->x;
			env->room_tab[i]->y = tmp->y;
			env->room_tab[i]->nxt = NULL;
			env->room_tab[i]->weight = 2147483647;
			env->room_tab[i]->degree = 0;
			env->room_tab[i]->dispo = -1;
		}
		tmp = tmp->nxt;
	}
	ft_find_start_end_value(env);
}
