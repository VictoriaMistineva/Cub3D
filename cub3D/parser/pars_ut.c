#include "../cub.h"

void set_cub(t_all *all, char **argv, int argc)
{
	if (argc > 3)
  		printf_exit("WRONG_MAP");
	if (argc == 3 && all->flag_save == 0)
		printf_exit("WRONG_MAP");
	if (open (argv[1], O_RDONLY) <= 0)
		printf_exit("WRONG_MAP");
}