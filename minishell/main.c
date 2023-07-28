/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:53:50 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/29 14:55:59 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_pid_variable(pid_t	pid);
static void	set_env(char const **envp, pid_t	pid);
static void	unlink_here_docs(void);
static void	print_signature(void);

int	main(int argc, char const **argv, char const **envp)
{
	t_tree_node	*parse_tree;
	pid_t		pid;

	pid = 0;
	if (argc != 1)
	{
		put_error(ARGS_ERROR, EXIT_FAILURE, (void *)(argv[1]));
		exit(EXIT_FAILURE);
	}
	set_env(envp, pid);
	sig_handling_set(SIG_INITIAL);
	print_signature();
	while (e_true)
	{
		parse_tree = shell_read();
		execute(parse_tree);
		tokenizer_free();
		free_tree(&parse_tree);
		unlink_here_docs();
	}
	return (EXIT_SUCCESS);
}

static void	unlink_here_docs(void)
{
	t_bool			repeat;
	char			*next_here_doc;
	size_t			progressive_nbr;
	char			*prefix;

	prefix = ".here_doc-";
	progressive_nbr = 0;
	repeat = e_true;
	while (repeat)
	{
		next_here_doc = ft_strjoin(prefix, ft_itoa(progressive_nbr),
				e_false, e_true);
		if (access(next_here_doc, R_OK | W_OK) != 0)
			repeat = e_false;
		else
			unlink(next_here_doc);
		free(next_here_doc);
		progressive_nbr++;
	}
}

static void	set_env(char const **envp, pid_t	pid)
{
	size_t	cur_shell_lvl;
	char	*new_shell_lvl_string;

	env_handler(ENV_INITIALIZE, (char **)envp);
	set_pid_variable(pid);
	printf("my pid is %d\n", g_env.pid);
	cur_shell_lvl = ft_atoi(env_handler(BINDING_GET_VALUE, "SHLVL"));
	new_shell_lvl_string = ft_itoa(cur_shell_lvl + 1);
	env_handler(BINDING_UPDATE,
		get_new_binding("SHLVL", new_shell_lvl_string, e_false));
	free(new_shell_lvl_string);
	if (env_handler(BINDING_GET_VALUE, "minishell_first_call_set") == NULL)
	{
		env_handler(BINDING_UPDATE,
			get_new_binding("minishell_first_call_set", "1", e_false));
		g_env.stdout_clone = dup(STDOUT_FILENO);
	}
	g_env.last_executed_cmd_exit_status = EXIT_SUCCESS;
}

static void	set_pid_variable(pid_t	pid)
{
	int		pid_val_pipe[2];
	int		shell_exit_value;

	pipe(pid_val_pipe);
	pid = fork();
	if (pid == 0)
	{
		close(pid_val_pipe[1]);
		read(pid_val_pipe[0], &g_env.pid, sizeof(pid_t));
		close(pid_val_pipe[0]);
	}
	else
	{
		signal(SIGINT, sig_ign);
		signal(SIGQUIT, sig_ign);
		close(pid_val_pipe[0]);
		write(pid_val_pipe[1], &pid, sizeof(pid_t));
		close(pid_val_pipe[1]);
		env_handler(ENV_CLEAN, NULL);
		waitpid(pid, &shell_exit_value, 0);
		exit(WEXITSTATUS(shell_exit_value));
	}
}

static void	print_signature(void)
{
	int		cur_stdout_backup;

	printf(CYAN "I devoti Jita dello Shogun presentano\n\n" RESET);
	printf(BOLDYELLOW "\
########   ######     ######     ######   ##########          #\n\
       #     #                     #      #        #         #  ##########   ######     ######\n\
      #  ########## ########## ##########         #     #   #           #        #          #\n\
    ##       #      #        #     #             #       # #           #        #          #\n\
  ## #       #             ##      #            #         #         # #         #          #\n\
 ##   #      #           ##        #          ##        ## #         #     ########## ##########\n\
#      #      ####     ##           ####\
    ##        ##    #         #\n\n" RESET);
	printf(RED "Minishell\n" RESET);
	printf(CYAN "La storia di" BOLDYELLOW " CCantale " \
	RESET CYAN "e" BOLDYELLOW " MRuizzo \n" RESET);
	printf(CYAN "Lode allo Shogun " RED "MMarinel " \
	CYAN "che ci ha preceduti\n\n" RESET);
}
