#include "monty.h"

char *read_cmd(char *line, unsigned int line_num)
{
	int i;
	char *tok, *tmp_tok;

	tok = strtok(line, " \n\t");

	if (strcmp(tok, "push") == 0)
	{
		printf("enter\n");
		tmp_tok = strtok(NULL, " ");

		if (tmp_tok == NULL)
		{
			printf("L%u: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
		for (i = 0; tmp_tok[i] >= ' ' && tmp_tok[i] <= '~'; i++)
		{

			if (tmp_tok[i] > '9' || tmp_tok[i] < '0')
			{

				printf("L%u: usage: push integer\n", line_num);
				exit(EXIT_FAILURE);
			}
		}

		i = atoi(tmp_tok);

		my_array[0] = i;

	}

	return tok;
}
