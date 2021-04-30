#include "cub.h"

void is_save(char **argv, t_all *all, int argc)
{
 if (argc == 3 && ft_strlen(argv[2]) == 6)
  if (argv[2][0] == '-' && argv[2][1] == '-' && argv[2][2] == 's'
   && argv[2][3] == 'a' && argv[2][4] == 'v' && argv[2][5] == 'e'
   && argv[2][6] == '\0')
   all->flag_save = 1;
}

void    create_screenshot2(int fd, t_all *all)
{
    int32_t x;
    int32_t y;
    int     color;
    y = all->param_map->scr_h - 1;
    while (y >= 0)
    {
        x = 0;
        while (x < all->param_map->scr_w)
        {
            color = *(unsigned int *)(all->win->addr
                    + (y * all->win->line_length)
                    + x * (all->win->bits_per_pixel / 8));
            write(fd, &color, 4);
            x++;
        }
        y--;
    }
    close(fd);
}
void    create_screenshot(t_all *all)
{
    int     fd;
    char    bitmap[54];
    fd = 0;
    fd = open("screenshot.bmp", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
    if (fd < 0)
        printf("Error\nСreating a screenshot resulted in an error");
    ft_bzero(bitmap, 54);
    bitmap[0] = 'B';// просто символы
    bitmap[1] = 'M';
    *((int *)(bitmap + 2)) = all->param_map->scr_h
        * all->param_map->scr_w * 4 + 54;// размер всего файла, 4 потому что цвет состоит из 4 параметров
    *(int *)(bitmap + 10) = 54;
    *(int *)(bitmap + 14) = 40;
    *(int *)(bitmap + 18) = all->param_map->scr_w;;//ширина скриншота
    *(int *)(bitmap + 22) = all->param_map->scr_h;;//высота скриншота
    *(bitmap + 26) = 1;
    *(bitmap + 28) = 32;//количество бит на пиксель
    write(fd, bitmap, 54);
    create_screenshot2(fd, all);
	exit(0);
}