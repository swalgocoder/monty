#include "monty.h"

char *read_cmd(char *line, unsigned int line_num)
{
	int i;
	char *t, *temp_num;

	t = strtok(line, " \n\t");

	if (strcmp(t, "push") == 0)
	{
		printf("enter\n");
		temp_num = strtok(NULL, " ");

		if (temp_num == NULL)
		{
			printf("L%u: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
		for (i = 0; temp_num[i] >= 32 && temp_num[i] <= 126; i++)
		{

			if (temp_num[i] > '9' || temp_num[i] < '0')
			{

				printf("L%u: usage: push integer\n", line_num);
				exit(EXIT_FAILURE);
			}
		}

		i = atoi(temp_num);

		my_array[0] = i;

	}

	return t;
}
