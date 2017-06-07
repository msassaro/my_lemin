/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:25:42 by msassaro          #+#    #+#             */
/*   Updated: 2016/05/03 07:05:56 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** returns 1 if the str is only alpha digit and underscores.
** 0 in other cases.
*/

int		ft_str_alpha_digit_underscore(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalpha(str[i]) && !ft_isdigit(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

/*
** We init the environement env here.
*/

void	ft_init_t_lem(t_lem *env)
{
	env->start_found = 0;
	env->end_found = 0;
	env->start_previous = 0;
	env->end_previous = 0;
	env->start.x = 0;
	env->start.y = 0;
	env->start.name = NULL;
	env->end.x = 0;
	env->end.y = 0;
	env->start_nb = 0;
	env->end_nb = 0;
	env->end.name = NULL;
	env->nb_ant = 0;
	env->room = NULL;
	env->tube = NULL;
	env->input = ft_strnew(1);
	env->room_tab = NULL;
}

/*
** This function will return the nb of room in the linked-list
** env->room.
*/

int		ft_len_room(t_room *room)
{
	t_room		*tmp;
	int			count;

	count = 0;
	tmp = room;
	while (tmp)
	{
		count++;
		tmp = tmp->nxt;
	}
	return (count);
}

/*
** This function returns the name of the room number x of the
** linked-list env->room
*/

char	*ft_get_room_name(int x, t_lem *env)
{
	t_room		*r_tmp;
	int			i;

	i = 0;
	r_tmp = env->room;
	while (r_tmp && i <= x)
	{
		if (i == x)
			return (r_tmp->name);
		i++;
		r_tmp = r_tmp->nxt;
	}
	return (NULL);
}

/*
** This function returns 1 if the tube (room nb x) <--> (room nb y) exists
*/

int		ft_exists_tube(int x, int y, t_lem *env)
{
	char	*r1;
	char	*r2;
	t_tube	*tmp;

	r1 = ft_get_room_name(x, env);
	r2 = ft_get_room_name(y, env);
	if (ft_strcmp(r1, r2))
	{
		tmp = env->tube;
		while (tmp)
		{
			if ((!ft_strcmp(tmp->start, r1) && !ft_strcmp(tmp->end, r2))
			|| (!ft_strcmp(tmp->start, r2) && !ft_strcmp(tmp->end, r1)))
				return (1);
			tmp = tmp->nxt;
		}
		return (0);
	}
	else
		return (0);
}
