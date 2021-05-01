#include "../cub.h"

// void check_texture(char *texture)
// {
// 	int i;
// 	i = ft_strlen(texture) - 1; //вернуть
// 	if (open(texture, O_RDONLY) == -1)
// 	{
// 		perror("Невалидная текстура");
// 		exit(0);
// 	}
// 	if(texture[i - 2]!= 'p' && texture[i - 1]!= 'n'&& texture[i]!= 'g')
// 	{
// 		printf("неверный формат файла");
// 		exit(0);
// 	}
// }

int	resolution(char *line, t_all *all)
{
	char	**resolution;

	if (all->pm->scr_h != -1 && all->pm->scr_w != -1)
		printf_exit("двойной ввод R");
	resolution = ft_split(line, ' ');
	all->pm->scr_w = ft_atoi_pars(resolution[1]);
	all->pm->scr_h = ft_atoi_pars(resolution[2]);
	array_free(resolution);
	return (1);
}

int	check_texture(char *line, char **texture)
{
	int	i;

	i = 2;
	if (*texture != NULL)
		printf_exit("двойной ввод texture");
	while (line[i] == ' ')
		i++;
	*texture = ft_strdup(&line[i]);
	// check_texture(all->pm->north); //оставить
	return (1);
}
