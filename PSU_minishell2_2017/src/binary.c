/*
** EPITECH PROJECT, 2018
** hello
** File description:
** cmd
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/sh.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int	check_sig(int wstatus)
{
	int ret_line;

	if (WIFSIGNALED(wstatus)) {
		if (wstatus == 11 || wstatus == 139) {
			my_putstrer("Segmentation fault\n");
			return (ret_line = 139);
		}
		if (wstatus == 136 && wstatus == 8) {
			my_putstrer("Floating exception\n");
			return (ret_line = 136);
		}
	}
	return (ret_line);
}

int	binary(char **user, char **path)
{
	int	ret;
	pid_t	pid;
	int	stat = 0;

	if ((pid = fork()) == 0) {
		ret = execve(user[0], user, path);
		if (ret == -1)
			return (0);
	}
	if (waitpid(pid, &stat, WSTOPPED))
		return (check_sig(stat));
}
