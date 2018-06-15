/*
** EPITECH PROJECT, 2017
** check_map.c
** File description:
** check if map is valid
*/
#include "sokoban.h"

static int	checking(char **tab, int i, int j)
{
	if (tab[i][j] != 'O' && tab[i][j] != 'X'
	&& tab[i][j] != ' ' && tab[i][j] != 'P'
	&& tab[i][j] != '#' && tab[i][j] != '\n') {
		return (1);
	}
	return (0);
}

static bool	check_char(char **tab)
{
	int	count = 0;

	for (int i = 0; tab[i]; ++i) {
		for (int j = 0; tab[i][j]; ++j) {
			count += checking(tab, i, j);
		}
	}
	if (count > 0)
		return (false);
	return (true);
}

static int	increment_count(char c, char comp, int count)
{
	if (c == comp)
		++count;
	return (count);
}

static int	check_number(char **tab, char c)
{
	int	count = 0;

	for (int i = 0; tab[i]; ++i) {
		for (int j = 0; tab[i][j]; ++j) {
			count = increment_count(tab[i][j], c, count);
		}
	}
	return (count);
}

int	check_map(char **tab)
{
	if (tab == NULL) {
		my_print_err("Failed to open file\n");
		return (FAILURE);
	}
	if ((check_number(tab, 'X') < check_number(tab, 'O'))
	|| check_number(tab, 'O') == 0
	|| check_number(tab, 'X') == 0 || check_number(tab, 'P') != 1) {
		my_print_err("Invalid map\n");
		return (FAILURE);
	} else if (check_char(tab) == false) {
		my_print_err("Invalid map\n");
		return (FAILURE);
	}
	return (SUCCESS);
}