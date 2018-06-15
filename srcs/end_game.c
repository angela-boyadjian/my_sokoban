/*
** EPITECH PROJECT, 2017
** end_game.c
** File description:
** end game functions
*/
#include "sokoban.h"

static bool	victory(char **tab, struct save *elem_tab)
{
	int	count = get_nb_box(tab);
	int	nb = 0;

	for (int i = 0; elem_tab[i].x >= 0; ++i) {
		if (tab[elem_tab[i].y][elem_tab[i].x] == 'X')
			++nb;
	}
	if (nb == count)
		return (true);
	return (false);
}

bool	game_over(char **tab, struct save *elem_tab)
{
	if (victory(tab, elem_tab) == true)
		return (true);
	return (false);
}