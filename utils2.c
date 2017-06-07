/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 07:04:44 by msassaro          #+#    #+#             */
/*   Updated: 2016/05/03 07:04:45 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** We display the degree, weight and dispo matrix.
*/

void	ft_print_matrix(t_lem *e)
{
	int		i;

	i = -1;
	ft_printf("{bold}{yellow}ROOM DEGREES:\n{reset}");
	while (++i < e->roomlen)
		ft_printf("%d\t\t%s\n", e->room_tab[i]->degree, e->room_tab[i]->name);
	ft_printf("{bold}{yellow}ROOM WEIGHTS:\n{reset}");
	i = -1;
	while (++i < e->roomlen)
		ft_printf("%d\t\t%s\n", e->room_tab[i]->weight, e->room_tab[i]->name);
	ft_printf("{bold}{yellow}ROOM DISPOS:\n{reset}");
	i = -1;
	while (++i < e->roomlen)
		ft_printf("%d\t\t%s\n", e->room_tab[i]->dispo, e->room_tab[i]->name);
	ft_putstr("\n");
}

/*
** In case of basics set, we will print the rooms, tubes, ant nb, start
** end, that we get on the recup.
*/

void	ft_print_basics(t_lem *e)
{
	t_room		*r_tmp;
	t_tube		*t_tmp;

	r_tmp = e->room;
	t_tmp = e->tube;
	ft_printf("{bold}{yellow}BASIC INFOS:{reset}\n");
	ft_printf("NB ANT:\t[%d]\n", e->nb_ant);
	ft_printf("[%d|%d]\t%s (start)\n", e->start.x, e->start.y, e->start.name);
	ft_printf("[%d|%d]\t%s (end)\n\n", e->end.x, e->end.y, e->end.name);
	ft_printf("{bold}{yellow}ROOM LIST:{reset}\n");
	while (r_tmp)
	{
		ft_printf("[%d|%d]\t%s\n", r_tmp->x, r_tmp->y, r_tmp->name);
		r_tmp = r_tmp->nxt;
	}
	ft_printf("\n");
	ft_printf("{bold}{yellow}TUBE LIST:{reset}\n");
	while (t_tmp)
	{
		ft_printf("[%s --> %s]\n", t_tmp->start, t_tmp->end);
		t_tmp = t_tmp->nxt;
	}
	ft_printf("\n");
}

/*
** Like the php explode function. It will separate the line into different
** parts with the separator.
** It will put each parts into tab[x]
*/

void	ft_explode(char *line, char separator, char *(*tab)[3])
{
	int		i;
	int		nb_part;
	int		start;
	int		end;

	i = 0;
	nb_part = 0;
	while (line[i])
	{
		while (line[i] == separator)
			i++;
		if (line[i] != separator)
		{
			start = i;
			while ((line[i] != separator) && line[i])
				i++;
			end = i;
			(*tab)[nb_part] = ft_strsub(line, start, end - start);
			nb_part++;
		}
	}
}

/*
** This is the Final error function. The program exit after it.
** if errmode is set then, we display the error detailed msg.
*/

void	ft_error(char *msg, t_lem *env)
{
	int		i;

	i = -1;
	if (env->errmode == 1)
	{
		ft_putstr_fd("ERROR - ", 2);
		ft_putstr_fd(msg, 2);
		ft_putstr_fd("\n", 2);
	}
	else
		ft_putstr_fd("ERROR\n", 2);
	exit(0);
}

/*
** This is the first error msg. The recup stops but the programs continues.
** It will try to solve with the info it already have.
** If errmode is set, display the detailed messages.
*/

void	ft_error_file_check(char *msg, t_lem *env)
{
	if (env->errmode == 1)
	{
		ft_putstr_fd("ERROR - ", 2);
		ft_putstr_fd(msg, 2);
		ft_putstr_fd("\n", 2);
	}
	ft_after_recup(env);
}
