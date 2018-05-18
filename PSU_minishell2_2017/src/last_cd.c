/*
** EPITECH PROJECT, 2018
** path
** File description:
** last
*/
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/sh.h"
#include <unistd.h>

void	error(char **user, char *begin)
{
	chdir(begin);
	my_putstr("mysh : no such files or no directory :");
	my_putstr(user[1]);
}

void	complete_path(char *cd_path, char **user, t_sh mysh)
{
	int	i = 0;
	int	x = 0;
	char	*begin = getcwd(NULL, 0);

	chdir("/");
	if (chdir(user[1]) != 0)
		error(user, begin);
}
