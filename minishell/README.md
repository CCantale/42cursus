Minishell
=======
This project was made in team with [Michele Ruizzo](https://github.com/ozziur "Check out the awsome guy").

Minishell is a C program that emulates the behavior of a UNIX bash terminal. It displays a prompt, parses the input string, determines the role of every element and finally executes the command, while handling pipes, redirections and &&/|| operators. To do this, the program creates a list of structures, containing each one the data relative to a single command, and organises them in a binary tree from which it deduces the execution path. The subject required some commands to be hardcoded and not simply executed via execve(): echo, cd, ls, env, export.
The program also handles any environment variables, like \$USER, macros like \$\$ and \$?, the * sign autocompletion, HereDoc and command incompleteness detection, giving the user the chance to add the rest of the command after sending the first part.

![Minishell pic](https://github.com/CCantale/42cursus/assets/95633668/f0bb701d-3a82-4d4d-9ee8-aca258487e8d)
