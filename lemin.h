/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 11:05:54 by msassaro          #+#    #+#             */
/*   Updated: 2016/04/20 16:51:59 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <unistd.h>
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include "libft/includes/ft_printf.h"

# define LEN_LINE	100
# define NB_LINE	10000

typedef struct	s_room
{
	int			x;
	int			y;
	char		*name;
	int			weight;
	int			degree;
	int			dispo;
	void		*nxt;
}				t_room;

typedef struct	s_tube
{
	int			lenght;
	char		*start;
	char		*end;
	void		*nxt;
}				t_tube;

typedef struct	s_lem
{
	t_room		*room;
	t_tube		*tube;
	t_room		start;
	t_room		end;
	t_room		**room_tab;
	int			redefine;
	int			redefine_bestpath;
	int			redefine_startend;
	int			color;
	int			print;
	int			errmode;
	int			noorder;
	int			bestpath;
	int			roominfo;
	int			print_matrix;
	int			**tubes;
	int			start_nb;
	int			end_nb;
	int			**matrix;
	char		*input;
	int			start_found;
	int			end_found;
	int			start_previous;
	int			end_previous;
	int			nb_ant;
	int			pathlen;
	int			roomlen;
	int			tubelen;
	int			tube_recup_on;
	char		*new_start;
	char		*new_end;
}				t_lem;

/*
** main.c
*/

void			ft_check_after_env_filled(t_lem *env);
void			ft_after_recup(t_lem *env);
void			ft_recup(t_lem *env);
void			ft_init_env(t_lem *env);

/*
** check_room.c
*/

int				ft_check_params(char *tab[3]);
int				ft_param_to_room(t_room *room, char *line, t_lem *env);
int				ft_check_room_valid(char *line, t_room *room, t_lem *env);
void			ft_room_add_list(t_lem *env, t_room *room);
void			ft_create_room(char *line, t_lem *env);

/*
** check_tube.c
*/

void			ft_tube_add_list(t_lem *env, t_tube *tube);
int				ft_tube_creation(char *line, t_lem *env);
void			ft_init_tube_len(t_lem *env);

/*
** check_line.c
*/

void			ft_check_first_line(char *line, t_lem *env);
void			ft_check_line_sharp_2(t_lem *env);
void			ft_check_line_sharp(char *line, t_lem *env);
void			ft_check_line_valid_2(char *line, t_lem *env);
int				ft_check_line_valid(char *line, t_lem *env);

/*
** double_room_check.c
*/

int				ft_room_occurs(t_lem *env, t_room *room);
int				ft_double_room_name(t_lem *env);
int				ft_location_occurs(t_lem *env, t_room *room);
int				ft_double_room_location(t_lem *env);

/*
** cost_matrix.c
*/

void			ft_print_cost_matrix(t_lem *env);
void			ft_cost_matrix_to_env(t_lem *env, int **matrix, int len);
void			ft_init_cost_matrix(t_lem *env);

/*
** ft_move.c
*/

int				ft_min_weight(t_lem *env, int room, int rm);
void			ft_go(t_lem *env, int min, int i, int room);
void			ft_move_ant(t_lem *env, int ant[]);
void			ft_move_ants(t_lem *env);

/*
** weight_degree.c
*/

void			ft_recursive_weight(t_lem *env, int room, int weight);
void			ft_create_degree_weight(t_lem *env);

/*
** pathlen.c
*/

void			ft_search_pathlen(t_lem *env);

/*
** utils.c
*/

int				ft_str_alpha_digit_underscore(char *str);
void			ft_init_t_lem(t_lem *env);
int				ft_len_room(t_room *room);
char			*ft_get_room_name(int x, t_lem *env);
int				ft_exists_tube(int x, int y, t_lem *env);

/*
** utils2.c
*/

void			ft_print_basics(t_lem *env);
void			ft_print_matrix(t_lem *env);
void			ft_explode(char *line, char separator, char *(*tab)[3]);
void			ft_error_file_check(char *msg, t_lem *env);
void			ft_error(char *msg, t_lem *env);

/*
** utils3.c
*/

void			ft_user_manual(void);
void			ft_redefine_2(char *av, t_lem *env);
void			ft_redefine(char *av, t_lem *env);
void			ft_create_flags(char *av, t_lem *env);
void			ft_add_line_to_env_record(char *line, t_lem *env);

/*
** utils4.c
*/

int				ft_check_redefine_room_exist(t_lem *e);
void			ft_find_start_end_value(t_lem *env);
void			ft_create_room_tab(t_lem *env);

#endif
