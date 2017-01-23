#include "monty.h"

/**
 * argc_check - checks if arg count is correct value
 * @argc: count of arguments
 * Return: void
 *
 */

void argc_check(int argc)
{
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/** 
 * file_check - check the file stream
 * @fd: pointer to file
 * Return: void
 */

void file_check(FILE *fd, char *infile)
{
	if (fd == NULL)
	  {
	    printf("Error: can't open file %s\n", infile);
	    exit(EXIT_FAILURE);

	  }
}
