/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** 03
*/

#include "../include/hangman.h"

int	my_put_nbr(int nb)
{
	long	n = nb;

	if (n < 0) {
		my_putchar('-');
		n = n *- 1;
	}
	if (n / 10 > 0)
		my_put_nbr(n / 10);
	my_putchar(n % 10 + '0');
	return (0);
}
