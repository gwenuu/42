#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define BUF_SIZE 4096

char	*validate_first_line(char *str, int n);
int		get_nbr(char *str, int n);
int		width(char *str, int i);
int		check_rows(char *str, int i, int width, char *p);
int		validate_map(char *str);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		**map_to_binary(char *str, char *params);
int		fill_row(int *row, char *str, char *params);
char	*str_join(char *old, char *chunk, int n);
char	*input_to_str(int fd);
void	process_map(char *str);
int	solve_map(char *str, char *params,int h, int w);
void	solu(int **map, int h, int w, int res[3]);
void	paint(int res[3], char **map, char c);
void	free_bin(int **bin, int j);
int		under_strlen(char *str);

#endif
