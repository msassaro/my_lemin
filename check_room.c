/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:22:26 by msassaro          #+#    #+#             */
/*   Updated: 2016/04/20 17:32:41 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** will return 0 or 1.
** In this fct we check all the params of a line that we suppose
** describes a room
** We need first a name, only with letters and underscores, we dont want a L
** at the begining of the name.
** for the coordinates we want digit only.
*/

int		ft_check_params(char *tab[3])
{
	if (ft_str_digit(tab[1]) && ft_str_digit(tab[2])
	&& ft_strlen(tab[1]) < 10 && ft_strlen(tab[2]) < 10)
	{
		if (!ft_str_alpha_digit_underscore(tab[0]))
			return (-1);
		else if (tab[0][0] == 'L')
			return (-1);
		else
			return (1);
	}
	else
		return (-1);
}

/*
** Here we will divide the line with the separator ' '.
** We check the params and if its ok, we check the coordinates.
** if not ok -> error
*/

int		ft_param_to_room(t_room *room, char *line, t_lem *env)
{
	char	*tab[3];

	ft_explode(line, ' ', &tab);
	if (ft_check_params(tab) == 1)
	{
		if (ft_long_atoi(tab[1]) < 2147483647 && ft_long_atoi(tab[1]) >= 0
			&& ft_long_atoi(tab[2]) < 2147483647 && ft_long_atoi(tab[2]) >= 0
			&& ft_strlen(tab[1]) < 10 && ft_strlen(tab[1]) < 10)
		{
			room->name = tab[0];
			room->x = (int)ft_atoi(tab[1]);
			room->y = (int)ft_atoi(tab[2]);
		}
		else
			ft_error_file_check("ERROR with room params", env);
	}
	else
		ft_error_file_check("ERROR with room params", env);
	return (1);
}

/*
** Here we check if the line correspond to a great room definition,
** and if a room with same name/coordinates exists.
*/

int		ft_check_room_valid(char *line, t_room *room, t_lem *env)
{
	if ((ft_explode_count(line, ' ')) != 3)
	{
		ft_error_file_check("Wrong ROOM definition (more than 3 params)", env);
		return (-1);
	}
	else
	{
		if (ft_param_to_room(room, line, env))
			return (1);
		else
			return (-1);
	}
}

/*
** We check if room exists, then we add the room at the end of the linked list.
** If the room already exists (name or coordinates) -> error.
*/

void	ft_room_add_list(t_lem *env, t_room *room)
{
	t_room		*tmp;

	if ((ft_location_occurs(env, room) > 0) || (ft_room_occurs(env, room) > 0))
		ft_error_file_check("Double room definition", env);
	if (room)
	{
		if (env->room)
		{
			tmp = env->room;
			while (tmp->nxt && tmp)
				tmp = tmp->nxt;
			tmp->nxt = room;
		}
		else
			env->room = room;
	}
}

/*
** Here we will check if the line is correct for a room definition.
** If so, we add the room to the linked-list env->room
** If the previous line was ##start we definie the start = this room.
*/

void	ft_create_room(char *line, t_lem *env)
{
	t_room		*room;

	if ((room = (t_room*)malloc(sizeof(t_room))) == NULL)
		ft_error_file_check("Malloc of room", env);
	room->nxt = NULL;
	if (ft_check_room_valid(line, room, env) == 1)
	{
		ft_room_add_list(env, room);
		if (env->start_previous == 1)
		{
			env->start_previous = 0;
			env->start.name = room->name;
			env->start.x = room->x;
			env->start.y = room->y;
		}
		else if (env->end_previous == 1)
		{
			env->end_previous = 0;
			env->end.name = room->name;
			env->end.x = room->x;
			env->end.y = room->y;
		}
	}
}
