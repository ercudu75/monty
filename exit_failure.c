#include "monty.h"
void cleanup_and_exit(const char *error_message)
{
	if (fail.fpc)
	{
		fclose(fail.fpc);
	}
	if (fail.line)
	{
		free(fail.line);
	}
	fprintf(stderr, "%s", error_message);
	exit(EXIT_FAILURE);
}
