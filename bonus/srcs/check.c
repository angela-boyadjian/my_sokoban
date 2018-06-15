/*
** EPITECH PROJECT, 2017
** check.c
** File description:
** check functions
*/
#include "sokoban.h"

static int check_box(struct p_pos *player, char **tab, int y, int x)
{
	if (tab[player->y + y][player->x + x] == 'X' &&
	(tab[player->y + y * 2][player->x + x * 2] == ' ' ||
	tab[player->y + y * 2][player->x + x * 2] == 'O')) {
		tab[player->y + y * 2][player->x + x * 2] = 'X';
		return (1);
	} else if (tab[player->y + y][player->x + x] != 'X')
		return (1);
	return (0);
}

int check_obstacles(struct p_pos *player, char **tab, int y, int x)
{
	if (tab[player->y + y][player->x + x] != '#'
	&& check_box(player, tab, y, x) == 1) {
		tab[player->y + y][player->x + x] = 'P';
		tab[player->y][player->x] = ' ';
		player->y += y;
		player->x += x;
		return (0);
	}
	return (1);
}