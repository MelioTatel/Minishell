/*
** EPITECH PROJECT, 2018
** sh
** File description:
** include
*/
#ifndef SH_H_
#define SH_H_

typedef struct  s_list
{
	char	**c;
	struct s_list	*next;
}	t_list;

typedef struct  s_sh
{
	int	pos;
	int	len_str;
	int	x;
	char	**path;
	char	**build;
	char	*use;
	char	**user;
	char	**exec;
	char	*localhost;
	char	*pastdir;
}	t_sh;

char	**unset_env(char **user, t_sh mysh);
int	check_sig(int wstatus);
int	binary(char **user, char **path);
void	*my_memset(void *s, int c, int n);
int	my_count_colon(char *str);
char	*clean_set(char *str);
char	*clear_string(char *s);
char	*get_next_line(const int fd);
int	my_count_w(char **str);
int	is_string_alpha(char *s);
int	cd(char **user, t_sh mysh);
void	error_cmd(char **user);
int	cmd(char **user, t_sh mysh);
int	count_word2(char prev, int words);
int	count_word(char *str);
int	count_semicolon(char **user);
t_list	*array_to_list(t_sh mysh, char **user, int count);
int	execute_commands(t_list *list, t_sh mysh, int count);
int	detect(t_sh mysh);
int	make_cmd(char **user, char **exec, char **path);
void	error(char **user, char *begin);
void	complete_path(char *cd_path, char **user, t_sh mysh);
int	gety(char **env);
char	**my_getenv(char **env, char **path);
int	sh(t_sh mysh);
t_sh	settings(char **env, t_sh mysh);
int	main(int ac, char **av, char **env);
int	my_getnbr(char const *str);
void	my_put_in_list(char **tab, t_list **list);
void	my_putchar(char c);
void	my_putstr(char *c);
void	my_putcharer(char c);
void	my_putstrer(char *c);
void	my_put_tab(char **map);
void	my_put_tabspace(char **map);
char	*my_strcat(char *dest, char *src);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strcpy(char *dest, char *src);
int	my_strlen(char const *str);
int	countword(char *str, char sep);
int	my_strlent(char *str, char sep);
char	**my_str_to_wordtab(char *str, char sep);
int	my_size_w(char **env, t_sh *v1, int *i);
int	len_words(char **array, t_sh *v1);
char	**my_tabdup_dot(char **old, char **new, t_sh *v1, char *sep);
void	forward(char *cd_path, char **user, t_sh mysh);
int	define_cmd(char **user);
char	**create_exec(char **env, char **exec);
char	*findhome(char **env, char *local);

#endif /* !SH_H_ */
