/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** put in list
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/sh.h"

void	my_put_in_list(char **tab, t_list **list)
{
	t_list	*tmp = *list;
	t_list	*elem;

	elem = malloc(sizeof(*elem));
	if (elem == NULL)
		return;
	elem->c = tab;
	elem->next = NULL;
	if (tmp == NULL) {
		*list = elem;
		return;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = elem;
}
