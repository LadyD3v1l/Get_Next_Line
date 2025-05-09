/*int	main(void)
{
	int		fd;
	char	*line;

	fd = open("arquivo.txt", O_RDONLY);
	if (fd < 0)
		return (1);
 	while (1)
 	{
 		line = get_next_line(fd);
 		if (line)
 		{
 			printf("%s", line);
 			free(line);
 		}
 		else
 			break ;
 	}
	close(fd);
	printf("%c", '\n');
	return (0);
}*/
// IMPRIME O TEXTO COMPLETO

/*int	main(void)
{
	int		fd;
	char	*line;

	fd = open("arquivo.txt", O_RDONLY);
	if (fd < 0)
		return (1);

	line = get_next_line(fd);
		printf("%s", line);
		free(line);
	close(fd);
	get_next_line(-1);
	return (0);
}*/
// IMPRIME UMA LINHA
// IMPRIME UMA LINHA
