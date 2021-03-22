 int type_identifier(char *line)
 {
	 int i ;
	 i = -1;

	printf("%s\n", line);
	while(line[++i])
	{
	 if (line[i] == 'R' && line[i + 1] == ' ')
		 //return (resolution());
		 printf("R\n");
	 else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		 //return (texture());
		 printf("NO\n");
	 else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		 //return (texture());
		 printf("SO\n");
	 else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		 //return (texture());
		 printf("WE\n");
	 else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		 //return (texture());
		 printf("EA\n");
	 else if (line[i] == 'S' && line[i + 1] == ' ')
		 //return (texture());
		 printf("S\n");
	 else if (line[i] == 'F' && line[i + 1] == ' ')
		 //return (floor_texture());
		 printf("FLOOR\n");
	 else if (line[i] == 'C' && line[i + 1] == ' ')
		 //return (ceilling_texture());
		 printf("CEIL\n");
	}
	return (1);
 }