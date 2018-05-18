/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** reproduction of shell
*/
#include "../include/sh.h"
#include <string.h>
#include <stdlib.h>
int	gety(char **env)
{
	int i = 0;

	while (env[i] != NULL)
		i = i + 1;
	return (i);
}

char	**my_getenv(char **env, char **path)
{
	int i = 0;

	path = malloc(sizeof(char *) *(gety(env) + 1));
	while (env[i] != NULL) {
		path[i] = malloc(sizeof(char)*(my_strlen(env[i]) + 1));
		path[i] = env[i];
		i = i + 1;
	}
	path[i] = NULL;
	return (path);
}

int	sh(t_sh mysh)
{
	while (1) {
		my_putstr("$>");
		mysh.use = get_next_line(0);
		if (mysh.use == NULL)
			return (0);
		mysh.use = clear_string(mysh.use);
		mysh.user = my_str_to_wordtab(mysh.use, ' ');
		if (mysh.user[0] != NULL&&my_strcmp("unsetenv", mysh.user[0])==0&&mysh.user[1]!=NULL)
			mysh.path = unset_env(mysh.user, mysh);
		if (mysh.user[0] != NULL)
			detect(mysh);
		free(mysh.user);
		free(mysh.exec);
		mysh.exec = create_exec(mysh.path, mysh.exec);
	}
}

t_sh	settings(char	**env, t_sh mysh)
{
	mysh.path = my_getenv(env, mysh.path);
	mysh.localhost = findhome(env, mysh.localhost);
	mysh.exec = create_exec(env, mysh.exec);
	return (mysh);
}

int	main(int ac, char **av, char **env)
{
	t_sh	mysh;

	mysh = settings(env, mysh);
	sh(mysh);
	return (0);
}
