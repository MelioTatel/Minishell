/*
** EPITECH PROJECT, 2018
** path
** File description:
** aht
*/
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/sh.h"
#include <unistd.h>


void	forward(char *cd_path, char **user, t_sh mysh)
{
	if (chdir(user[1]) != 0) {
		my_putstr("cd: no such files or directory:");
		my_putstr(user[1]);
		my_putchar('\n');
	}
}

int	define_cmd(char **user)
{

	if (user[0][0] != '/')
		return (0);
	if (user[0][0] == '/')
		return (1);
}
