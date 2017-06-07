/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 07:04:19 by msassaro          #+#    #+#             */
/*   Updated: 2016/05/03 07:05:38 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** On the first line we check if ALL the line is a digit (no - nor +)
** If the line's length is greater than 10 (int < ) -> error
** If nb ants > 20000 -> error.
** If all is good we set the nb_ant into the env.
*/

void	ft_check_first_line(char *line, t_lem *env)
{
	int		nb_ant;

	if (ft_str_digit(line))
	{
		if (ft_strlen(line) < 10)
		{
			nb_ant = (int)ft_long_atoi(line);
			if (0 < nb_ant && nb_ant < 20000)
				env->nb_ant = nb_ant;
			else
				ft_error("Wrong ant number", env);
		}
		else
			ft_error("Wrong ant number", env);
	}
	else
		ft_error("First line need to be a digit", env);
}

/*
** this is the function that checks the lines that starts with #
** if line start with ## its a command, if it starts with # only, its
** a comment. if its ##start or ##end its a valid cmd, else we dont care.
** (respectively end for the following)
** If we have ##start we check if start is already set, if so -> error.
** We also check that we do not need an end definition (= previous line
** was ##end, and now we need a room before having ##start)
** start_previous = 1 --> ##start was the line before, we need a room
** to define the start.
*/

void	ft_check_line_sharp_2(t_lem *env)
{
	if (env->start_previous == 1)
		ft_error_file_check("END definition before START room", env);
	else if (env->end_found == 0)
	{
		env->end_found = 1;
		env->end_previous = 1;
	}
	else
		ft_error_file_check("END already set up", env);
}

void	ft_check_line_sharp(char *line, t_lem *env)
{
	if (line[1] == '#')
	{
		if (ft_strcmp(line, "##start") == 0)
		{
			if (env->end_previous == 1)
				ft_error_file_check("START definition before END room", env);
			else if (env->start_found == 0)
			{
				env->start_found = 1;
				env->start_previous = 1;
			}
			else
				ft_error_file_check("START already set up", env);
		}
		else if (ft_strcmp(line, "##end") == 0)
			ft_check_line_sharp_2(env);
	}
}

/*
** This is the function on which we check each line 1 by 1 when
** we do the recup
** First we check the line's length. if it's greater than LINE_LEN => error.
** We could also add a nb_line max.
** For the first line we go into a specific function.
** if the line is empty, function returns 0
** tube format room1-room2
** room format name x y
** we check the format then if a room is defined after a tube, error
** unless the flag noorder is set.
** we add the line to the record.
*/

void	ft_check_line_valid_2(char *line, t_lem *env)
{
	if (ft_explode_count(line, ' ') == 3)
	{
		if (env->tube_recup_on == 1 && env->noorder == 0)
			ft_error_file_check("Tube defined before room", env);
		else
			ft_create_room(line, env);
	}
	else if (ft_explode_count(line, ' ') == 1)
		ft_tube_creation(line, env);
	else
		ft_error_file_check("Wrong room or tube / wrong line", env);
}

int		ft_check_line_valid(char *line, t_lem *env)
{
	static int		nb_line;

	if (ft_strlen(line) < LEN_LINE && nb_line < NB_LINE)
	{
		line = ft_strtrim(line);
		if (nb_line == 0)
			ft_check_first_line(line, env);
		else
		{
			if (line[0] == '#')
				ft_check_line_sharp(line, env);
			else if (ft_strcmp(line, ""))
				ft_check_line_valid_2(line, env);
			else
				return (0);
		}
		ft_add_line_to_env_record(line, env);
	}
	else
		ft_error_file_check("line too long", env);
	nb_line++;
	return (1);
}
