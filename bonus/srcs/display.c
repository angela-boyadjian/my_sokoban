/*
** EPITECH PROJECT, 2017
** display.c
** File description:
** display functions
*/
#include "sokoban.h"

void	print_map(char **tab)
{
	for (int i = 0; tab[i]; ++i)
		printw("%s\n", tab[i]);
}