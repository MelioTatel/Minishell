/*
** EPITECH PROJECT, 2018
** cmd
** File description:
** commande
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/sh.h"
#include <unistd.h>

int	cd(char **user, t_sh mysh)
{
	char *cd_path;

	if (my_strcmp("cd", user[0]) == 0 && user[1] == NULL) {
		chdir(mysh.localhost);
		return (0);
	}
	if (my_strcmp("cd", user[0])== 0 && user[1][0]== '~' && user[2]== NULL){
		chdir(mysh.localhost);
		return (0);
	}
	if (my_strcmp(user[1], "-") == 0 && mysh.pastdir != NULL) {
		my_putstr(mysh.pastdir);
		chdir(mysh.pastdir);
		return (0);
	}
	if (define_cmd(user) == 0)
		forward(cd_path, user, mysh);
	if (define_cmd(user) == 1)
		complete_path(cd_path, user, mysh);
	return (0);
}

char    **unset_path(char *user, char **path)
{
	int i = 0;
	int x = 0;
	char **new;

	new = malloc(sizeof(char *) *(gety(path) + 1));
	while (path[x] != NULL) {
		if (strncmp(user, path[x], my_strlen(user) - 1) == 0){
			x = x + 1;
		}
		new[i] = malloc(sizeof(char)*(my_strlen(path[x]) + 1));
		new[i] = path[x];
		i = i + 1;
		x = x + 1;
	}
	new[i] = NULL;
	return (new);
}

char	**unset_env(char **user, t_sh mysh)
{
	int i = 1;

	while (user[i] != NULL) {
		mysh.path = unset_path(user[i], mysh.path);
		i = i + 1;
	}
	return (mysh.path);
}

int	cmd(char **user, t_sh mysh)
{
	if (user[0][0] == '\0') 
		return (0);
	if (my_strcmp("exit", user[0]) == 0 && user[1] != NULL) {
		my_putstr("Thank you , bye");
		exit(my_getnbr(user[1]));
	}
	if (my_strcmp("env", user[0]) == 0 && user[1] == NULL) {
		my_put_tab(mysh.path);
		return (0);
	}
	if (my_strcmp("unsetenv", user[0]) == 0 && user[1] != NULL) {
		mysh.path = unset_env(user, mysh);
		return (0);
	}
	if (my_strcmp("setenv", user[0]) == 0 && user[1] != NULL) {
		return (0);
	}
	if (my_strcmp(user[0], "cd") == 0)
		return (cd(user, mysh));
	if (user[0][0] == '.' && user[0][1] == '/')
		return (binary(user, mysh.path));
	if (make_cmd(user, mysh.exec, mysh.path) == 0)
		return (0);
	else
		return (1);
}
