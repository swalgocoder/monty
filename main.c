#include "monty.h"

/**
 * The code implementation of this project is mostly due to the credit and help of jay, her help is greatly   * * appreciated.
 * "https://github.com/jayjay823/monty"
 *
 */

int my_array[2];
int main(int argc, char **argv)
{
	FILE *fd = fopen(argv[1], "r");
	char *filepath, *line = NULL;
	size_t length = 0;

	argc_check(argc);
	filepath = argv[1];

	fd = fopen(argv[1], "r");
	file_check(fd, filepath);

	cmd_str(line, length, fd);
	
	fclose(fd);
	if (line)
		free(line);
	exit(EXIT_SUCCESS);
}
