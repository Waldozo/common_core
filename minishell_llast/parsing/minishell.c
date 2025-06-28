/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:23:24 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/06/28 19:49:54 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_signal_status = 0;

void	free_token_chain(t_struct *tokens)
{
	t_struct	*tmp;
	
	while (tokens)
	{
		tmp = tokens->next;
		if (tokens->str)
			free(tokens->str);
		free(tokens);
		tokens = tmp;
	}
}

void	free_tokens(t_struct *data)
{
	t_struct	*tmp;
	
	while (data)
	{
		if (data->env)
			ft_free_array(data->env);
		tmp = data->next;
		if (data->str)
			free(data->str);
		free(data);
		data = tmp;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_struct	*data;
	t_cmd		*cmd;
	t_exec		*exec;

	// t_garbage	gc;
	// t_struct	*tmp;
	(void)argv;
	data = NULL;
	// init_garbage(&gc);
	exec = malloc(sizeof(t_exec));
	// exec = gc_malloc(sizeof(t_exec), &gc);
	if (!exec)
		return (1);
	exec->path = NULL;
	exec->pipes = 0;
	if (argc != 1)
	{
		printf("Error: need only one argument\n");
		// free_garbage(&gc);
		return (1);
	}
	data = malloc(sizeof(t_struct));
	if (!data)
	{
		perror("Error allocating memory");
		// free_garbage(&gc);
		free(exec);
		return (1); // Ajoutez cette fonction à la fin du fichier
	}
	if (cpy_env(data, envp) == -1)
	{
		// free_garbage(&gc);
		free(exec);
		free(data);
		return (1);
	}
	data->exec = exec;
	data->next = NULL;  // Initialize data->next to NULL
	exec->last_status = 0;
	while (1)
	{
		// exec->last_status = g_signal_status;
		g_signal_status = 0;
		signal(SIGINT, handle_sigint);
		// Je remplace le comportement de ctrl+c par le mien
		signal(SIGQUIT, SIG_IGN);
		// je capture le signal quit et je lui dis de l'ignore dans le parent pour éviter le core dumped. Mon shell ne doit pas crasher.
		data->str = readline("💻 minishell > ");
		if (data->str == NULL)
		{
			ft_putstr_fd("exit\n", STDOUT_FILENO);
			break ;
		}
		if (ft_strlen(data->str) > 0)
		{
			add_history(data->str);
			if (parsing(data))
			{
				t_struct *token_chain = data->next; // Save reference to token chain
				// t_struct *tmp = data->next;
				// while (tmp)
				// {
				// 	printf("{%d -> '%s'}\n", tmp->type, tmp->str);
				// 	tmp = tmp->next;
				// }
				cmd = create_cmd_from_tokens(&data->next, data->env, exec);
				if (!cmd)
				{
					// free_garbage(&gc)
					free_token_chain(token_chain);
					free(data->str);
					free(exec);
					free(data);
					return (1);
				}
				// ft_printf("%d\n", exec->last_status);
				// gc.cmd = cmd;
				execution(cmd, exec, &data);
				// ft_printf("%d\n", exec->last_status);
				free_all_cmd(cmd);
				free_token_chain(token_chain);
				data->next = NULL;
			}
			else
			{
				// If parsing failed, still need to clean up any tokens that may have been created
				if (data->next)
				{
					free_token_chain(data->next);
					data->next = NULL;
				}
			}
		}
		else
		{
			// Even for empty strings, make sure to reset data->next in case it was set
			if (data->next)
			{
				free_token_chain(data->next);
				data->next = NULL;
			}
		}
		free(data->str);
		data->str = NULL;
	}
	// Additional cleanup - ensure any remaining tokens are freed
	if (data->next)
	{
		free_token_chain(data->next);
		data->next = NULL;
	}
	ft_free_array(data->env);
	free(data);
	free(exec);
	return (0);
}
