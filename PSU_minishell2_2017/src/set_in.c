/*
** EPITECH PROJECT, 2018
** setting my_struc information
** File description:
** oui
*/
#include "../include/sh.h"
#include <stdlib.h>

char	**create_exec(char **env, char **exec)
{
	int i = 0;
	int m = 0;
	int n = 5;
	char *tmp;

	while (env[i] != NULL && my_strncmp(env[i], "PATH=", 4) != 0)
		i = i + 1;
	if (env[i] == NULL) {
		exec = malloc(sizeof(char*) * 1);
		exec[0] = NULL;
		return (exec);
	}
	tmp = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
	while (env[i][n] != '\0') {
		tmp[m] = env[i][n];
		n = n + 1;
		m = m + 1;
	}
	tmp[m] = '\0';
	exec = my_str_to_wordtab(tmp, ':');
	return (exec);
}

char	*findhome(char **env, char *local)
{
	int i = 0;
	int n = 5;
	int m = 0;

	while (my_strncmp(env[i], "HOME=", 4) != 0)
		i = i + 1;
	local = malloc(sizeof(char) * (my_strlen(env[i])+1));

	while (env[i][n] != '\0') {
		local[m] = env[i][n];
		m = m + 1;
		n = n + 1;
	}
	local[n] = '\0';
	return (local);
}
