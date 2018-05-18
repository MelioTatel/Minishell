/*
** EPITECH PROJECT, 2018
** gnl
** File description:
** .h
*/

#ifndef GET_NEXT_LINE_H_
#define BUFF_SIZE       (10)

typedef struct	s_list
{
	char	c;
	struct s_list	*next;
}	t_list;

char	*get_next_line(const int);

#endif /* GET_NEXT_LINE_H_ */
