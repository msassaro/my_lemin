/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 07:04:39 by msassaro          #+#    #+#             */
/*   Updated: 2016/05/03 07:04:40 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_search_pathlen(t_lem *env)
{
	int		ant[1];
	int		r_togo;

	ant[0] = env->start_nb;
	while (ant[0] != env->end_nb)
	{
		r_togo = ft_min_weight(env, ant[0], 0);
		if (env->room_tab[r_togo]->dispo == 0 || r_togo == env->end_nb)
			ant[0] = r_togo;
		env->pathlen++;
	}
}
