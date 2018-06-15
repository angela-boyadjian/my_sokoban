/*
** EPITECH PROJECT, 2017
** sokoban.h
** File description:
** sokoban header
*/
#ifndef SOKOBAN_H_
#define SOKOBAN_H_

#include <ncurses.h>
#include "my.h"
#include "define.h"

struct save {
	int	x;
	int	y;
};

struct	p_pos {
	int	x;
	int	y;
};

struct menu {
	int 	highlight;
	int 	n_choices;
	int 	choice;
	int 	start_x;
	int 	start_y;
};

void		init(struct menu *tools);
struct save	*init_tab(char **tab);
int		menu(WINDOW *menu_win, struct menu *tools, char **choices);
int		errors(char **tab);
int		get_size(char **tab);
int		check_obstacles(struct p_pos *player, char **tab, int y, int x);
int		check_arg(int ac);
char		**read_file(char const *filename);
bool		game_over(char **tab, struct save *elem_tab);
bool		defeate(char **tab);
void		my_sokoban(char **tab, struct save *elem_tab, char **save);
void		reset_game(char **tab, char **save, struct save **elem_tab);
int		check_map(char **tab);
int		get_nb_box(char **tab);
void		print_map(char **tab);
int		get_size(char **tab);
int		adding_count(char c, int count, char comp);

#endif /* !SOKOBAN_H_ */