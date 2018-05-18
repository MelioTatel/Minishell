/*
** EPITECH PROJECT, 2018
** str_to_word_tab
** File description:
**
*/

#include <stdio.h>
#include "../include/sh.h"

int	count_word2(char prev, int words)
{
	if (prev != ' ' && prev != '\n' && prev != '\0')
		words++;
	return (words);
}

int	count_word(char *str)
{
	int	i = 0;
	int	words = 0;
	char	prev = 0;

	while (42) {
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\0')
			words = count_word2(prev, words);
		prev = str[i];
		if (str[i] == '\0')
			break;
		else
			i++;
	}
	return (words);
}

int my_count_w(char **str)
{
	int i = 0;

	while (str[i] != NULL)
		i = i + 1;
	return (i);
}
