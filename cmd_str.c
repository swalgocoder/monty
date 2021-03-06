#include "monty.h"

	void cmd_str(char *line, size_t length, FILE *fd)
	{
	char *cmd_str;
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
	}
