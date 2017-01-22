# monty

The project:
The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.


For example, problem 13. rotl:

:1. "bytecodes/35.m" is the "bytecode"  file, as an input . 2. "monty" is our c implementation of "monty vm or interpreter", which includes at least  a doubly linked list simulated "stack", pop(), push(), and it will be compiled into an executable file. 3. run it: ./monty bytecodes/35.m . , and hopefully it will produce right out put, as in problem of "13. rotl".

monty is the interpreter that can read the input file, and  execute the bytecode commands within that file, and monty works as a very simple virtual machine for The Monty Language.