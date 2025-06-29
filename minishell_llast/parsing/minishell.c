/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:23:24 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/06/29 16:27:01 by wlarbi-a         ###   ########.fr       */
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
		{
			free(tokens->str);
			tokens->str = NULL;
		}
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

void	cleanup_all_data(t_struct *data)
{
	// Reset the token pool instead of freeing individual tokens
	if (data->token_pool)
	{
		reset_token_pool(data->token_pool);
		data->next = NULL;
	}
	// Clean up data->str (should be the original readline string)
	if (data->str)
	{
		free(data->str);
		data->str = NULL;
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
		free(exec);
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
	
	// Initialiser le pool de tokens avec une capacité initiale de 100
	data->token_pool = init_token_pool(100);
	if (!data->token_pool)
	{
		perror("Error allocating token pool");
		free(exec);
		free(data);
		return (1);
	}
	
	if (cpy_env(data, envp) == -1)
	{
		// free_garbage(&gc);
		free_token_pool(data->token_pool);
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
			// Reset the token pool before exit to avoid leaks
			reset_token_pool(data->token_pool);
			data->next = NULL;
			break ;
		}
		if (ft_strlen(data->str) > 0)
		{
			add_history(data->str);
			if (parsing(data))
			{
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
					// No need to free individual tokens - they're in the pool
					free(data->str);
					free_token_pool(data->token_pool);
					free(exec);
					free(data);
					return (1);
				}
				// ft_printf("%d\n", exec->last_status);
				// gc.cmd = cmd;
				execution(cmd, exec, &data);
				// ft_printf("%d\n", exec->last_status);
				free_all_cmd(cmd);
				// Reset the token pool instead of freeing individual tokens
				reset_token_pool(data->token_pool);
				data->next = NULL;
			}
			else
			{
				// If parsing failed, reset the token pool
				reset_token_pool(data->token_pool);
				data->next = NULL;
			}
		}
		else
		{
			// Even for empty strings, reset the token pool
			reset_token_pool(data->token_pool);
			data->next = NULL;
		}
		free(data->str);
		data->str = NULL;
		data->str = NULL;
	}
	
	// Clean up readline history and internal buffers
	clear_history();
	rl_clear_history();
	
	if (data)
	{
		if (data->env)
			ft_free_array(data->env);
		if (data->str)
		{
			free(data->str);
			data->str = NULL;
		}
		// Libérer le token pool
		if (data->token_pool)
			free_token_pool(data->token_pool);
		free(data);
	}
	if (exec)
		free(exec);
	return (0);
}
