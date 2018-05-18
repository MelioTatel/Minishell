/*
** EPITECH PROJECT, 2018
** putstr
** File description:
** display a string
*/

#include <unistd.h>
#include "../include/sh.h"

void    my_putchar(char c)
{
	write(1, &c, 1);
}

void	my_putstr(char *c)
{
	int	i = 0;

	while (c[i] != '\0') {
		my_putchar(c[i]);
		i = i + 1;
	}
}

void    my_putcharer(char c)
{
	write(2, &c, 1);
}

void	my_putstrer(char *c)
{
	int	i = 0;

	while (c[i] != '\0') {
		my_putcharer(c[i]);
		i = i + 1;
	}
}
