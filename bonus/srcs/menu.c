/*
** EPITECH PROJECT, 2017
** menu.c
** File description:
** functions to create a menu
*/
#include "sokoban.h"

void init(struct menu *tools)
{
	tools->highlight = 1;
	tools->start_x = (80 - WIDTH) / 2;
	tools->start_y = (24 - HEIGHT) / 2;
	tools->choice = 0;
	tools->n_choices = 2;
}

static void print_menu(WINDOW *menu_win, struct menu *tools, char **choices)
{
	int	x = 2;
	int	y = 2;
	int	i;

	box(menu_win, 0, 0);
	for(i = 0; i < tools->n_choices; ++i) {
		if(tools->highlight == i + 1) {
			wattron(menu_win, A_REVERSE);
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", choices[i]);
		++y;
	}
	wrefresh(menu_win);
}

static void	check_choice(struct menu *tools)
{
	if (tools->highlight == 1)
		tools->highlight = tools->n_choices;
	else
		tools->highlight--;

}

static void get_input(WINDOW *menu_win, struct menu *tools)
{
	int	c;

	c = wgetch(menu_win);
	switch(c)
	{	case KEY_UP:
			check_choice(tools);
			break;
		case KEY_DOWN:
			if (tools->highlight == tools->n_choices)
				tools->highlight = 1;
			else
				tools->highlight++;
			break;
		case 10:
			tools->choice = tools->highlight;
			break;
		default:
			refresh();
			break;
	}
}

int	menu(WINDOW *menu_win, struct menu *tools, char **choices)
{
	initscr();
	clear();
	noecho();
	curs_set(0);
	menu_win = newwin(HEIGHT, WIDTH, tools->start_y, tools->start_x);
	keypad(menu_win, TRUE);
	refresh();
	print_menu(menu_win, tools, choices);
	while (1) {
		get_input(menu_win, tools);
		print_menu(menu_win, tools, choices);
		if (tools->choice == 1 || tools->choice == 2)
			break;
	}
	refresh();
	endwin();
	return (tools->choice);
}