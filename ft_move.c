/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 07:04:34 by msassaro          #+#    #+#             */
/*   Updated: 2016/05/03 07:06:12 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Here we will determine the room to go in.
** input room is the room that the ant is in.
** We will check for the current room if there is a path to other rooms
** (we loop for each room).
** If so, in case its the end, then we return the end cause its the room we
** want to go and we dont care about weight.
** If its not the end, we add the weigh and dispo of the i room,
** If its, lower than the weigh, then we reset the values of the
** searched room;
** At the end we have the room with the minimum weight or the end.
*/

int		ft_min_weight(t_lem *env, int room, int rm)
{
	int		i;
	int		wgt;
	int		deg;
	int		id;

	wgt = (int)2147483647;
	deg = 0;
	id = -1;
	i = -1;
	while (++i < env->roomlen)
	{
		if (env->matrix[room][i])
		{
			if (i == env->end_nb)
				return (i);
			rm = env->room_tab[i]->weight + env->room_tab[i]->dispo;
			if ((rm < wgt) || (rm == wgt && env->room_tab[i]->degree < deg))
			{
				wgt = rm;
				id = i;
				deg = env->room_tab[i]->degree;
			}
		}
	}
	return (id);
}

/*
** Here we will print ant by ant and room by room, turn by turn.
*/

void	ft_go(t_lem *env, int r_togo, int ant, int room)
{
	if (env->room_tab[r_togo]->dispo == 0 || r_togo == env->end_nb)
	{
		env->room_tab[room]->dispo = 0;
		env->room_tab[r_togo]->dispo = 1;
		if (env->bestpath != 1)
		{
			if ((ant - 1) >= 0 && r_togo == env->end_nb && env->pathlen == 1)
				ft_putstr("\n");
			if (ant % 4 == 0 && env->color == 1)
				ft_printf("{red}");
			else if (ant % 4 == 1 && env->color == 1)
				ft_printf("{yellow}");
			else if (ant % 4 == 2 && env->color == 1)
				ft_printf("{green}");
			else if (ant % 4 == 3 && env->color == 1)
				ft_printf("{blue}");
			ft_printf("L%d-", ant + 1);
		}
		ft_putstr(env->room_tab[r_togo]->name);
		ft_printf("{reset} ");
	}
	else
		env->room_tab[r_togo]->dispo += 1;
}

/*
** In this function we will move each ant[i] if the ant is not at the
** end, to the room with the minimum weight that is available (or end).
** dispo = 0 <--> nobody is inside <--> room is available.
** we will first determine the room to go in.
*/

void	ft_move_ant(t_lem *env, int ant[])
{
	int		i;
	int		room;
	int		r_togo;

	i = -1;
	while (++i < env->nb_ant)
	{
		if ((room = ant[i]) != env->end_nb)
		{
			r_togo = ft_min_weight(env, ant[i], 0);
			if (env->room_tab[r_togo]->dispo == 0 || r_togo == env->end_nb)
				ant[i] = r_togo;
			ft_go(env, r_togo, i, room);
		}
	}
	ft_putstr("\n");
}

/*
** Here we first init a ant tab that represents all the ants we have.
** We init this tab -> all ants are at start.
** If bestpath is set, then we will send only 1 ant that ll check for the
** best path.
** We will do an infinite loop. We will do the loop until all ants are at
** the end.
** Each loop, we will check for each ant, if the ant is not at the end,
** we move the ant. then we retart from the begining of ant tab.
*/

void	ft_move_ants(t_lem *env)
{
	int		ant[env->nb_ant];
	int		i;

	i = -1;
	while (++i < env->nb_ant)
		ant[i] = env->start_nb;
	i = -1;
	if (env->bestpath == 1)
	{
		ft_printf("{bold}{yellow}BEST PATH\n{reset}");
		env->nb_ant = 1;
	}
	while (1)
	{
		while (++i < env->nb_ant)
		{
			if (ant[i] != env->end_nb)
			{
				ft_move_ant(env, ant);
				i = -1;
			}
			else if (i == env->nb_ant - 1)
				return ;
		}
	}
}
