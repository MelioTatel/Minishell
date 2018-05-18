/*
** EPITECH PROJECT, 2017
** my_strcmp
** File description:
** task05
*/
#include "../include/sh.h"

int my_strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
		i++;
	}
	return (s2[i] - s1[i]);
}

int my_strncmp(char *s1, char *s2, int n)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
		i++;
		if (i == n)
			return (s2[i] - s1[i]);
	}
	return (s2[i] - s1[i]);
}
