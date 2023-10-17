#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *fpc;

	if (argc != 2)
	{
		fprintf(stderr,"USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fpc = fopen(argv[1], "r");
	if (!fpc)
	{
		fprintf(stderr,"Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	else
	{
		read_file(fpc);
	}
	fclose(fpc);
	return (0);
}
int read_file(FILE *fpc)
{
	char *line = NULL;
	size_t size_line = 0;
	ssize_t read;

	while ((read = getline(&line, &size_line, fpc)) != -1)
	{
		token_line(line);
		free(line);
		line = NULL;
		size_line = 0;
	}
	free(line);
	return (0);
}

void token_line(char *line)
{
	char *token;

	token = strtok(line, " \t\n");
	while (token)
	{
		printf("token: %s\n", token);
		token = strtok(NULL, " \t\n");
	}
}
