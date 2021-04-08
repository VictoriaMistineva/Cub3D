#include "cub.h"

int resolution(char *line, t_all *all)
{
	char **resolution;
	if(all->param_map->scr_w != 0 && all->param_map->scr_h != 0)
		printf_exit("двойной ввод R");
	resolution = ft_split((char const *)line,' ');
	all->param_map->scr_w = ft_atoi(resolution[1]);
	all->param_map->scr_h = ft_atoi(resolution[2]);
	printf(" MY= %d %d\n",all->param_map->scr_w, all->param_map->scr_h);// удалить
	return (1);
}
int check_argument_textur(char *line, t_all *all)
{	
	// char **texture;
	// printf("%d/n", all->param_map->param_textur);
	printf(" MY = textura\n");


	// {
	// 	printf("много аргументов для текстур");
	// 	exit(0);
	// }
	
	
		
	// // check_texture(&all->param_map->param_textur);
	

	return(1);
}

// void check_texture(char *texture)
// {
// 	// int i;
// 	// i = ft_strlen(texture) - 1; //вернуть
// 	// if (open(texture, O_RDONLY) == -1)
// 	// {
// 	// 	perror("Невалидная текстура");
// 	// 	exit(0);
// 	// }
// 	// if(texture[i - 2]!= 'p' && texture[i - 1]!= 'n'&& texture[i]!= 'g')
// 	// {
// 	// 	printf("неверный формат файла");
// 	// 	exit(0);
// 	// }
// }


