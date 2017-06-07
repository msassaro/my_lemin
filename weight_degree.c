/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weight_degree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 07:04:54 by msassaro          #+#    #+#             */
/*   Updated: 2016/05/03 07:06:33 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Here we will loop, for the room param, if there is a link (matrix)
** we will:
** if its the start we put the dispo to -2
** if the room[i] has a 0 or more than 1 paths, and a weight bigger than
** the param weight, we changes its values.
** We do not touch the end.
*/

void	ft_recursive_weight(t_lem *env, int room, int weight)
{
	int		i;

	i = -1;
	while (++i < env->roomlen)
	{
		if (env->matrix[room][i] && i != env->end_nb)
		{
			if (i == env->start_nb)
				env->room_tab[i]->dispo = -2;
			else if (env->room_tab[i]->degree != 1
					&& env->room_tab[i]->weight > weight + 1)
			{
				env->room_tab[i]->weight = weight + 1;
				ft_recursive_weight(env, i, weight + 1);
				env->room_tab[i]->dispo = 0;
			}
		}
	}
}

/*
** Here we will first put the degrees to each room.
** degree = nb of link on the room.
** We put the weight and dispo of the end to 0 (= ist available)
** Then we create the weight. It will be recursive from End --> start.
** We will put start dispo to -2, then if not we know that the
** path isnt complete.
*/

void	ft_create_degree_weight(t_lem *env)
{
	int		i;
	int		j;

	i = -1;
	while (++i < env->roomlen)
	{
		j = -1;
		while (++j < env->roomlen)
		{
			if (env->matrix && env->matrix[i][j])
				env->room_tab[i]->degree++;
		}
	}
	env->room_tab[env->end_nb]->weight = 0;
	env->room_tab[env->end_nb]->dispo = 0;
	ft_recursive_weight(env, env->end_nb, 0);
	if (env->room_tab[env->start_nb]->dispo != -2)
		ft_error("No path: START -- / --> END", env);
}
