/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 12:03:53 by msassaro          #+#    #+#             */
/*   Updated: 2016/04/20 17:18:51 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** In the fct we proceed to double check after the recup.
** If there are some issues, we go into the error function that will
** exit the program.
*/

void	ft_check_after_env_filled(t_lem *env)
{
	if (env->start.name == NULL || env->end.name == NULL)
		ft_error("START / END not defined", env);
	if (env->nb_ant <= 0 || env->nb_ant > 20000)
		ft_error("Wrong ant number", env);
	if (ft_double_room_name(env))
		ft_error("ROOM name already set up", env);
	if (ft_double_room_location(env))
		ft_error("Location already set up", env);
	if (env->tube == NULL || env->room == NULL)
		ft_error("No tube set up", env);
	if ((env->roomlen = ft_len_room(env->room)) > 2000)
		ft_error("Too much room", env);
	ft_init_tube_len(env);
}

/*
** Here we read each line from STDIN then we go check the content
** of each line.
** if line check isnt ok we break the loop.
** at the end we define roomlen.
*/

void	ft_recup(t_lem *env)
{
	char	*line;

	while ((get_next_line(0, &line)) > 0)
	{
		if (!ft_check_line_valid(line, env))
			break ;
		if (line)
			free(line);
	}
	if (line)
		free(line);
	env->roomlen = ft_len_room(env->room);
}

/*
** After the recup is done, we will proceed to double check,
** Then we create a double cost matrix (tube matrix),
** we init the degrees and weight of the rooms.
** If no error unitil here, we display the content recuperation.
** We print the flags request if needed.
** Finaly we will do the ant move at the end.
*/

void	ft_after_recup(t_lem *env)
{
	ft_check_after_env_filled(env);
	ft_init_cost_matrix(env);
	ft_create_room_tab(env);
	ft_create_degree_weight(env);
	ft_printf("%s\n", env->input);
	if (env->print == 1)
		ft_print_basics(env);
	if (env->print_matrix == 1)
	{
		if (env->roomlen < 100)
			ft_print_cost_matrix(env);
		else
			ft_putstr("print option works only with roomlen < 100");
	}
	if (env->roominfo == 1)
		ft_print_matrix(env);
	ft_search_pathlen(env);
	ft_move_ants(env);
	exit(1);
}

/*
** here we init the env flags. all flags = 0. if a flag is on we
** put flag = 1;
** then we init the basic env params.
** then we recup the content of STDIN trough a file or user manual input
** in the after_recup we will re check and proceed to operations.
*/

void	ft_init_env(t_lem *env)
{
	env->print = 0;
	env->print_matrix = 0;
	env->errmode = 0;
	env->noorder = 0;
	env->bestpath = 0;
	env->tube_recup_on = 0;
	env->color = 0;
	env->roominfo = 0;
	env->new_start = NULL;
	env->new_end = NULL;
	env->redefine = 0;
	env->redefine_startend = 0;
	env->redefine_bestpath = 0;
	env->pathlen = 0;
}

int		main(int ac, char **av)
{
	t_lem	env;
	int		i;

	i = -1;
	ft_init_env(&env);
	if (ac >= 2)
	{
		while (av[++i])
			ft_create_flags(av[i], &env);
	}
	ft_init_t_lem(&env);
	ft_recup(&env);
	ft_after_recup(&env);
	return (0);
}
