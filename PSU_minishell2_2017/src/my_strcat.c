/*
** EPITECH PROJECT, 2017
** strcat
** File description:
** 29
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/sh.h"
#include <unistd.h>

char	*my_strcat(char *dest, char *src)
{
	int	i = 0;
	char	*last;

	last = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
	for (int x = 0; dest[x] != '\0'; x += 1) {
		last[i] = dest[x];
		i += 1;
	}
	for (int x = 0; src[x]; x += 1) {
		last[i] = src[x];
		i += 1;
	}
	last[i] = '\0';
	return (last);
}
