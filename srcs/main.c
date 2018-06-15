/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main function
*/
#include "sokoban.h"

int	help(int ac, char **av)
{
	for (int i = 0; i < ac; ++i) {
		if (my_strcmp(av[i], "-h") == 0) {
			my_printf("%s%s%s", U1, U2, U3);
			return (1);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	char		**tab = NULL;
	char		**save = NULL;
	struct save	*elem_tab = NULL;

	if (check_arg(ac) == FAILURE)
		return (FAILURE);
	if (help(ac, av) == 1)
		return (SUCCESS);
	tab = read_file(av[1]);
	save = read_file(av[1]);
	if (check_map(tab) == FAILURE)
		return (FAILURE);
	elem_tab = init_tab(tab);
	my_sokoban(tab, elem_tab, save);
	return (SUCCESS);
}