/*
** EPITECH PROJECT, 2017
** sokoban.c
** File description:
** sokoban game
*/
#include "sokoban.h"

static void init_p_pos(char c, int i, int j, struct p_pos *player)
{
	if (c == 'P') {
		player->y = i;
		player->x = j;
	}
}

static void	get_pos(char **tab, struct p_pos *player)
{
	for (int i = 0; tab[i]; ++i) {
		for (int j = 0; tab[i][j]; ++j) {
			init_p_pos(tab[i][j], i, j, player);
		}
	}
}

static void place_case(struct save *elem_tab, char **tab)
{
	for (int i = 0; elem_tab[i].x >= 0; ++i) {
		if (tab[elem_tab[i].y][elem_tab[i].x] == ' ')
			tab[elem_tab[i].y][elem_tab[i].x] = 'O';
	}
}

static int move_player(char **tab, struct p_pos *player)
{
	int	input = getch();

	switch (input) {
		case KEY_LEFT :
			check_obstacles(player, tab, 0, -1);
			break;
		case KEY_RIGHT :
			check_obstacles(player, tab, 0, 1);
			break;
		case KEY_UP :
			check_obstacles(player, tab, -1, 0);
			break;
		case KEY_DOWN :
			check_obstacles(player, tab, 1, 0);
			break;
		case ' ' :
			return (1);

	}
	return (0);
}

void	my_sokoban(char **tab, struct save *elem_tab, char **save)
{
	WINDOW		*win;
	struct p_pos	player;

	get_pos(tab, &player);
	win = initscr();
	clear();
	curs_set(0);
	keypad(win, 1);
	while (game_over(tab, elem_tab) == false && defeate(tab) == false) {
		print_map(tab);
		if (move_player(tab, &player) == 1) {
			reset_game(tab, save, &elem_tab);
			endwin();
			my_sokoban(tab, elem_tab, save);
			return;
		}
		place_case(elem_tab, tab);
		erase();
		refresh();
	}
	endwin();
}