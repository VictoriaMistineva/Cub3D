#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i++]!='\0')
		return i;
}

char *ft_end(char *line , char by)
{
	char *res;
	int i;

	res = malloc(ft_strlen(line)+2);
	while((res[i]==line[i]))
		i++;
	res[i++] =  by;
	res[i] = '\0';
	free(line);
	return(res);
}

int get_next_line(char **line)
{
	char buf[1]
	int res;

	*line = malloc(1);
	*line = '\0';
	while((res = read(0, buf, 1)) && buf[0]= '\n');
	(*line)[i] = ft_end(*line, buf[0]);
	return(res!=0);  
}