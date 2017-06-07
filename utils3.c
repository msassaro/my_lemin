/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 07:04:47 by msassaro          #+#    #+#             */
/*   Updated: 2016/05/03 07:07:50 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** We will read from user_man.md file and print it.
** If file doesnt exists display error.
** At the end we exit the program.
*/

void	ft_user_manual(void)
{
	int		fd;
	char	*line;

	fd = open("user_man.md", O_RDONLY);
	if (fd > 0)
	{
		while (get_next_line(fd, &line))
		{
			ft_putstr(line);
			ft_putstr("\n");
			free(line);
		}
		ft_printf("\n\n\t{red}INTERACTIVE MAN -> {bold}sh doc.sh{reset}\n\n\n");
	}
	else
		ft_putstr("ERROR - NO README.md file\n");
	exit(1);
}

void	ft_redefine_2(char *av, t_lem *env)
{
	int		i;
	int		start;

	i = 16;
	while (av[i] && av[i] != '{')
		i++;
	if (av[i] == '{' && av[i + 1])
	{
		i++;
		start = i;
		while (av[i] && av[i] != '}')
			i++;
		env->new_start = ft_strcpy_startend(av, start, i - 1);
		i++;
	}
	if (av[i] == '{' && av[i + 1])
	{
		i++;
		start = i;
		while (av[i] && av[i] != '}')
			i++;
		env->new_end = ft_strcpy_startend(av, start, i - 1);
	}
}

void	ft_redefine(char *av, t_lem *env)
{
	if ((int)ft_strlen(av) > LEN_LINE + 10)
		ft_error("wrong redefinition", env);
	if (ft_strnequ(av, "redefine_bestpath", 16))
	{
		env->redefine = 1;
		env->bestpath = 1;
		ft_redefine_2(av, env);
	}
	else if (ft_strnequ(av, "redefine_startend", 16))
	{
		env->redefine = 1;
		ft_redefine_2(av, env);
	}
	else
		ft_error("wrong redefinition", env);
	if (!env->new_start || !env->new_end
		|| !ft_str_alpha_digit_underscore(env->new_start)
		|| !ft_str_alpha_digit_underscore(env->new_end))
	{
		ft_printf("start:\'%s\' end:\'%s\'\n", env->new_start, env->new_end);
		ft_error("wrong redefinition", env);
	}
}

/*
** Here we just turn flag = 1 if av[i] correspond to a flag
*/

void	ft_create_flags(char *av, t_lem *env)
{
	if (!ft_strcmp(av, "basics"))
		env->print = 1;
	if (!ft_strcmp(av, "matrix"))
		env->print_matrix = 1;
	if (!ft_strcmp(av, "print"))
	{
		env->print = 1;
		env->print_matrix = 1;
	}
	if (!ft_strcmp(av, "errmode"))
		env->errmode = 1;
	if (!ft_strcmp(av, "noorder"))
		env->noorder = 1;
	if (!ft_strcmp(av, "roominfo"))
		env->roominfo = 1;
	if (!ft_strcmp(av, "bestpath"))
		env->bestpath = 1;
	if (!ft_strcmp(av, "man"))
		ft_user_manual();
	if (!ft_strcmp(av, "color"))
		env->color = 1;
	if (ft_strnequ(av, "redefine", 7))
		ft_redefine(av, env);
}

/*
** Here we just take line and put it at the end of the input record.
*/

void	ft_add_line_to_env_record(char *line, t_lem *env)
{
	char	*tmp;

	tmp = env->input;
	env->input = ft_strjoin(tmp, line);
	free(tmp);
	tmp = env->input;
	env->input = ft_strjoin(tmp, "\n");
	free(tmp);
}
