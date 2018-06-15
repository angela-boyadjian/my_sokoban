/*
** EPITECH PROJECT, 2017
** error.c
** File description:
** error handling
*/
#include "sokoban.h"

int	check_arg(int ac)
{
	if (ac < 2) {
		my_print_err("Not enough arguments\n");
		return (FAILURE);
	}
	return (SUCCESS);
}