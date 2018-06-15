/*
** EPITECH PROJECT, 2017
** init.c
** File description:
** init functions
*/
#include "sokoban.h"

void	reset_game(char **tab, char **save, struct save **elem_tab)
{
	for (int i = 0; tab[i]; ++i)
		my_strcpy(tab[i], save[i]);
	*elem_tab = init_tab(save);
}

int	get_size(char **tab)
{
	int	nb = 0;

	for (int i = 0; tab[i]; ++i) {
		for (int j = 0; tab[i][j]; ++j) {
			nb = adding_count(tab[i][j], nb, 'O');
		}
	}
	return (nb);
}

static int	check_char(int y, int x, struct save *elem_tab, int count)
{
	elem_tab[count].x = x;
	elem_tab[count].y = y;
	return (1);
}

struct save	*init_tab(char **tab)
{
	int		i;
	int		j;
	int		count = 0;
	struct save	*elem_tab = malloc(sizeof(*elem_tab)
	* (get_size(tab) + 1));

	if (elem_tab == NULL)
		return (NULL);
	for (i = 0; tab[i]; ++i) {
		for (j = 0; tab[i][j]; ++j) {
			if (tab[i][j] == 'O') {
				count += check_char(i, j, elem_tab, count);
			}
		}
	}
	elem_tab[count].x = -1;
	return (elem_tab);
}