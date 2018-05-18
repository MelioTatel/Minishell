/*
** EPITECH PROJECT, 2018
** execve
** File description:
** user exec
*/
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/sh.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int	make_cmd(char **user, char **exec, char **path)
{
	char	*cmd;
	char	*v;
	int	i = 0;
	int	bool = -1;

	cmd = my_strcat("/", user[0]);
	if (exec[0] != NULL) {
		while (bool != 0 && exec[i] != NULL) {
			v = malloc(sizeof(char)*(my_strlen(user[0]) * 3));
			v = my_strcat(exec[i], cmd);
			bool = access(v, 0);
			i = i + 1;
		}
	}
	if (bool == 0 && fork() == 0) {
		bool = execve(v, user, path);
	}
	wait(NULL);
	return (bool);
}
