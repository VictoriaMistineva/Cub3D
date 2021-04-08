#include "cub.h"

int charlen(char **str)
{
	int i;
	i = 0;
	while(str[i]!='\0')
		i++;
	return i;
}
char *printf_exit(char *str)
{
	printf("%s\n", str);
	exit(0);
}
int	ft_atoi_pars(const char *str)
{
	unsigned int	i;

	i = 0;
	while (*str && (*str == 32 || (*str > 8 && *str < 14)))
		str++;
	if (*str > 33 && *str < 126)
		return (1);
	while (*str >= '0' && *str <= '9')
	{
		i = i * 10 + *str - '0';
		str++;
	}
	return (i);
}