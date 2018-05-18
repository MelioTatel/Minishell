/*
** EPITECH PROJECT, 2018
** tab
** File description:
** print a tab
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/sh.h"

void	my_put_tab(char **map)
{
	int	n = 0;

	while (map[n] != NULL) {
		write(2, map[n], strlen(map[n]));
		write(2, "\n", 1);
		n = n + 1;
	}
	return;
}

void	my_put_tabspace(char **map)
{
	int	n = 0;

	while (map[n] != NULL) {
		my_putstr(map[n]);
		my_putchar(' ');
		n = n + 1;
	}
	return;
}
