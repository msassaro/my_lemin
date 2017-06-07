/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 07:04:27 by msassaro          #+#    #+#             */
/*   Updated: 2016/05/03 07:04:28 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Here we will simply print the cost matrix.
*/

void	ft_print_cost_matrix(t_lem *env)
{
	int		x;
	int		y;

	ft_printf("\n{bold}{yellow}COST MATRIX{reset}\n");
	x = 0;
	while (x < env->roomlen)
	{
		y = 0;
		while (y < env->roomlen)
		{
			ft_printf("%d ", env->matrix[x][y]);
			y++;
		}
		ft_printf("\n");
		x++;
	}
	ft_printf("\n");
}

/*
** Here, we put zeros and 1 to the cost matrix, if there is a tube
** between 2 rooms, we put a 1.
*/

void	ft_cost_matrix_to_env(t_lem *env, int **matrix, int len)
{
	int		x;
	int		y;

	x = -1;
	while (++x < len)
	{
		if ((matrix[x] = (int*)ft_memalloc(sizeof(int)
		* ft_len_room(env->room) + 1)) == NULL)
			ft_error("Malloc matrix", env);
		y = -1;
		while (++y < len)
		{
			if (ft_exists_tube(x, y, env))
				matrix[x][y] = 1;
			else
				matrix[x][y] = 0;
		}
	}
	env->matrix = matrix;
}

/*
** Here we initialize the cost matrix, if malloc error -> error
*/

void	ft_init_cost_matrix(t_lem *env)
{
	int		**matrix;
	int		nb_room;

	nb_room = ft_len_room(env->room);
	if ((matrix = (int**)malloc(sizeof(int) * (nb_room * nb_room) + 1)) == NULL)
		ft_error("Malloc matrix", env);
	ft_cost_matrix_to_env(env, matrix, nb_room);
}
