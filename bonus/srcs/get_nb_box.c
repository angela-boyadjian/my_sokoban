/*
** EPITECH PROJECT, 2017
** get_nb_box.c
** File description:
** functions to get nb box
*/
#include "sokoban.h"

int adding_count(char c, int count, char comp)
{
	if (c == comp)
		++count;
	return (count);
}

int get_nb_box(char **tab)
{
	int	count = 0;

	for (int i = 0; tab[i]; ++i) {
		for (int j = 0; tab[i][j]; ++j) {
			count = adding_count(tab[i][j], count, 'X');
		}
	}
	return (count);
}