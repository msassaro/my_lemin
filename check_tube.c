/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tube.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:24:07 by msassaro          #+#    #+#             */
/*   Updated: 2016/05/03 07:04:02 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Here we add the tube at the end of the linked-list env->tube;
*/

void	ft_tube_add_list(t_lem *env, t_tube *tube)
{
	t_tube		*tmp;

	if (tube)
	{
		if (env->tube)
		{
			tmp = env->tube;
			while (tmp->nxt && tmp)
				tmp = tmp->nxt;
			tmp->nxt = tube;
		}
		else
			env->tube = tube;
	}
}

/*
** Here we will check that the tube formates correctly.
** If there is two parts for a tube. We dont care if there are
** double tube or wrong room names.
** WE CAN add a TUBECHECK flag.
*/

int		ft_tube_creation(char *line, t_lem *e)
{
	int		i;
	char	*tab[3];
	t_tube	*tube;

	i = 0;
	tube = NULL;
	if (ft_explode_count(line, '-') == 2)
	{
		ft_explode(line, '-', &tab);
		e->tube_recup_on = 1;
		if ((tube = (t_tube*)malloc(sizeof(t_tube))) == NULL)
			ft_error_file_check("Malloc of tube", e);
		tube->nxt = NULL;
		tube->start = tab[0];
		tube->end = tab[1];
		ft_tube_add_list(e, tube);
	}
	else
		ft_error_file_check("wrong tube definition", e);
	return (0);
}

void	ft_init_tube_len(t_lem *env)
{
	int		result;
	t_tube	*tmp;

	tmp = env->tube;
	result = 0;
	while (tmp)
	{
		result++;
		tmp = tmp->nxt;
	}
	env->tubelen = result;
}
