/*
** EPITECH PROJECT, 2017
** read_file.c
** File description:
** functions for reading the file
*/
#include "sokoban.h"

char	**read_file(char const *filename)
{
	FILE	*file;
	char	*buffer = NULL;
	size_t	bufsize = 0;
	char	**tab = malloc(sizeof(char *) * 10000);
	int	i;

	file = fopen(filename, "r");
	if (file == NULL)
		return (NULL);
	for (i = 0; getline(&buffer, &bufsize, file) != -1; ++i) {
		tab[i] = buffer;
		if (tab[i][my_strlen(tab[i]) - 1] == '\n')
			tab[i][my_strlen(tab[i]) - 1] = 0;
		buffer = NULL;
		bufsize = 0;
	}
	tab[i] = 0;
	fclose(file);
	return (tab);
}