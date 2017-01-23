#include "monty.h"

int my_array[] = {0, 0};
int main(int argc, char **argv)
{
	FILE *fd = fopen(argv[1], "r");
	char *filepath, *line = NULL, *cmd_str;
	size_t length = 0;
	ssize_t readfile;
	stack_t *head = NULL;
	unsigned int line_num;
	int j;
	instruction_t instruct[] = {
		{"push", my_push},
		{"pall", my_pall},
		{"pint", my_pint},
		{"pop", my_pop},
		{"swap", my_swap},
		{"add", my_add},
		{"nop", my_nop},
		{NULL, NULL}
	};

	argc_check(argc);
	filepath = argv[1];

	fd = fopen(argv[1], "r");
	file_check(fd, filepath);
	
	line_num = 1;

	while ((readfile = getline(&line, &length, fd)) != -1)
	{

		cmd_str = read_cmd(line, line_num);
		j = 0;
		while (j < 8)
		{
			if (cmd_str[0] != '#' && strcmp(instruct[j].opcode, cmd_str) == 0)
			{
				instruct[j].f(&head, line_num);
				break;
			}
			j++;
		}
		line_num++;
	}

	fclose(fd);
	if (line)
		free(line);
	exit(EXIT_SUCCESS);
}
