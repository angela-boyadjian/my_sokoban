/*
** EPITECH PROJECT, 2017
** defeate.c
** File description:
** defeate functions
*/
#include "sokoban.h"

static int	check_walls(char **tab, int y, int x)
{
	if (tab[y - 1][x] == '#' && tab[y][x + 1] == '#')
		return (1);
	if (tab[y + 1][x] == '#' && tab[y][x + 1] == '#')
		return (1);
	if (tab[y + 1][x] == '#' && tab[y][x - 1] == '#')
		return (1);
	if (tab[y - 1][x] == '#' && tab[y][x - 1] == '#')
		return (1);
	return (0);
}

static int	counting(char **tab, int i, int j, int count)
{
	if (tab[i][j] == 'X')
		count += check_walls(tab, i, j);
	return (count);
}

bool	defeate(char **tab)
{
	int	count = 0;

	for (int i = 0; tab[i]; ++i) {
		for (int j = 0; tab[i][j]; ++j) {
			count = counting(tab, i, j, count);
		}
	}
	if (count == get_nb_box(tab))
		return (true);
	return (false);
}