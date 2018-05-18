/*
** EPITECH PROJECT, 2018
** clear string
** File description:
** remove spaces
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/sh.h"
void	*my_memset(void *s, int c, int n)
{
	int	a = 0;

	while (a < n)
		((char *)s)[a ++] = c;
	return (s);
}

int	my_count_colon(char *str)
{
	int	i = 0;
	int	count = 0;

	while (str[i]) {
		if (str[i] == ';')
			count += 2;
		count += 1;
		i += 1;
	}
	return (count);
}

char	*clean_set(char *str)
{
	char	*tmp = malloc(sizeof(char) * (my_count_colon(str) + 3));

	if (!tmp)
		exit(1);
	tmp = my_memset(tmp, 0, sizeof(char) * (my_count_colon(str) + 3));
	return (tmp);
}

char	*clear_string(char *s)
{
	char	*tmp = NULL;
	int	bool = 0;
	int	a = 0;
	int	b = 0;

	if (!s)
		return (NULL);
	a = my_strlen(s);
	tmp = clean_set(s);
	for (; s[0] == ' ' || s[0] == '\t' || s[0] == ';'; s ++, b ++);
	if (a == b)
		return (s);
	for (a = 0, b = 0; s[a]; ) {
		for (; s[a]>= 33 && s[a]<= 126 && s[a]!= ';'; a += 1, b+= 1) {
			if (tmp[b] == ';') {
				b += 1;
				tmp[b++] = ' ';
			}
			tmp[b] = s[a];
		}
		tmp[b ++] = ' ';
		for (; s[a] == ' ' || s[a] == '\t' || s[a] == ';'; a ++) {
			if (s[a] == ';' && bool == 0) {
				tmp[b] = s[a];
				bool = 1;
			}
		}
		bool = 0;
	}
	tmp[--b] = '\0';
	return (tmp);
}

int	is_string_alpha(char *s)
{
	for (int i = 0; s[i]; i++) {
		if (s[i] < '0' || (s[i] > '_' && s[i] < 'a') || s[i] > 'z')
			return (1);
		if ((s[i] > '9' && s[i] < 'A') || (s[i] > 'Z' && s[i] < '_'))
			return (1);
	}
	return (0);
}
