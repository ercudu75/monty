#include "monty.h"


int main(int argc, char *argv[])
{
	FILE *fpc;
	stack_t *top = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fpc = fopen(argv[1], "r");
	if (!fpc)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read_file(fpc, top);
	fclose(fpc);
	return (0);
}
int read_file(FILE *fpc, stack_t *top)
{
	int line_number;
	char *line = NULL;
	size_t size_line = 0;
	ssize_t read;

	while ((read = getline(&line, &size_line, fpc)) != -1)
	{
		line_number++;
		token_line(line, &top);
		free(line);
		line = NULL;
		size_line = 0;
	}
	free(line);
	return (0);
}

void token_line(char *line, stack_t **top)
{
	char *token, *value;
	int i;

	instruction_t ops[] = {
		{"push", push_element},
		{"pall", print_stack},
		{NULL, NULL}
	};
	size_t len = strlen(line);

	if (len > 0 && line[len - 1] == '\n')
	{
		line[len - 1] = '\0';
	}

	token = strtok(line, " \t");
	while (token)
	{
		i = 0;
		while (ops[i].opcode)
		{
			if (strcmp(token, ops[i].opcode) == 0)
			{
				value = strtok(NULL, " \t");
				if (value)
				{
					ops[i].f(top, atoi(value));
					break;
				}
				else
				{
					ops[i].f(top, 0);
					break;
				}
			}
			i++;
		}
		token = strtok(NULL, " \t\n");
	}
}
