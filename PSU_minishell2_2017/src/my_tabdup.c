/*
** EPITECH PROJECT, 2018
** tabdup
** File description:
** tabdup
*/

#include <stdlib.h>
#include "../include/sh.h"

int	my_size_w(char **env, t_sh *v1, int *i)
{
	int     j = 0;

	while (env[*i][j] != '\0')
		j++;
	return (j);
}

int	len_words(char **array, t_sh *v1)
{
	int	j = 0;

	while (array[v1->x][j] != '\0')
		j++;
	return (j);
}

char	**my_tabdup(char **old, t_sh *v1)
{
	int	j = -1;
	int	i = 0;
	char	**new;

	new = malloc(sizeof(char *) * (my_count_w(old) + 3));
	if (new == NULL)
		return (NULL);
	while (old[i] != NULL) {
		v1->len_str = my_size_w(old, v1, &i);
		new[i] = malloc(sizeof(char) * (v1->len_str) + 2);
		if (new[i] == NULL)
			return (NULL);
		my_strcpy(new[i], old[i]);
		j = -1;
		i++;
	}
	new[i] = NULL;
	return (new);
}

void	reset_values(t_sh *v1, int *i, int *j)
{
	*j = 0;
	*i += 1;
	v1->x++;
}

char	**my_tabdup_dot(char **old, char **new, t_sh *v1, char *sep)
{
	int	j = 0;
	int	i = 0;

	new = malloc(sizeof(char *) * (my_count_w(old) + 2));
	if (new == NULL)
		return (NULL);
	while (old[v1->x] != NULL) {
		if (my_strcmp(old[v1->x], sep) == 0) {
			new[i] = NULL;
			return (new);
		}
		v1->len_str = len_words(old, v1);
		new[i] = malloc(sizeof(char) * (v1->len_str + 2));
		if (new[i] == NULL)
			return (NULL);
		my_strcpy(new[i], old[v1->x]);
		reset_values(v1, &i, &j);
	}
	v1->x = 0;
	new[i] = NULL;
	return (new);
}
