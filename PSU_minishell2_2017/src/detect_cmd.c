/*
** EPITECH PROJECT, 2018
** detect my cmd
** File description:
** detect
*/
#include "../include/sh.h"
#include <string.h>
int count_semicolon(char **user)
{
	int i = 0;
	int c = 0;

	if (user == NULL)
		return (0);
	while (user[i] != NULL) {
		if (my_strcmp(user[i], ";") == 0)
			c = c + 1;
		i = i + 1;		     
	}
	return (c);
}

t_list *array_to_list(t_sh mysh, char **user, int count)
{
	int i = 0;
	t_list *list = NULL;
	t_list *tmp = list;
	char	**tab = NULL;

	mysh.x = 0;
	while (i < count + 1) {
		tab = my_tabdup_dot(user, tab, &mysh, ";");
		my_put_in_list(tab, &tmp);
		mysh.x += 1;
		i = i + 1;
	}
	return (tmp);
}

int execute_commands(t_list *list, t_sh mysh, int count)
{
	int	ret = 0;

	while (list != NULL) {
		if (ret = cmd(list->c, mysh) != 0)
			error_cmd(list->c);
		list = list->next;
	}
	return (ret);
}

void error_cmd(char **user)
{
	my_put_tabspace(user);
	my_putstr(" :Command not found\n");
}

int	detect(t_sh mysh)
{
	int i = 0;
	int ret = 0;
	int count = 0;
	t_list *list = NULL;

	count = count_semicolon(mysh.user);
	if (count > 0) {
		list = array_to_list (mysh, mysh.user, count);
		ret = execute_commands(list, mysh, count);
	}
	else
		if (ret = cmd(mysh.user, mysh) != 0)
			error_cmd(mysh.user);
	return (ret);}
