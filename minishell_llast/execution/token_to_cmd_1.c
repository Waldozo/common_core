/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_cmd_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:39:52 by fbenkaci          #+#    #+#             */
/*   Updated: 2025/07/02 14:38:26 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/minishell.h"

#define MAX_ARGS 100

// Fonction pour réorganiser les tokens si la redirection vient avant la commande
int	reorder_command_tokens(t_struct **cur)
{
	t_struct	*redir_start;
	t_struct	*redir_end;
	t_struct	*cmd_node;
	t_struct	*temp;

	if (!cur || !*cur)
		return (0);
	if ((*cur)->type == HEREDOC || (*cur)->type == REDIR_OUT 
		|| (*cur)->type == REDIR_IN || (*cur)->type == APPEND)
	{
		redir_start = *cur;
		redir_end = redir_start;
		while (redir_end->next && (redir_end->next->type == SPACES 
			|| redir_end->next->type == WORD || redir_end->next->type == WORD_D_QUOTES 
			|| redir_end->next->type == WORD_S_QUOTES))
		{
			redir_end = redir_end->next;
			if (redir_start->type == HEREDOC && redir_end->type != SPACES)
				break;
		}
		cmd_node = redir_end->next;
		while (cmd_node && cmd_node->type == SPACES)
			cmd_node = cmd_node->next;
		
		if (cmd_node && (cmd_node->type == WORD || cmd_node->type == WORD_D_QUOTES 
			|| cmd_node->type == WORD_S_QUOTES))
		{
			temp = cmd_node->next;
			redir_end->next = temp;
			cmd_node->next = redir_start;
			*cur = cmd_node;
			return (1);
		}
	}
	return (0);
}

int	fill_cmd_from_token(t_struct **cur, t_cmd *cmd, int *i, char **envp)
{
	int	res;

	while (*cur && (*cur)->type != PIPE)
	{
		if ((*cur)->type == REDIR_OUT || (*cur)->type == REDIR_IN)
		{
			res = handle_out_and_in(cur, cmd);
			if (res == -1)
				return (-1);
		}
		else if ((*cur)->type == APPEND || (*cur)->type == WORD
			|| (*cur)->type == WORD_D_QUOTES || (*cur)->type == WORD_S_QUOTES)
		{
			if (handle_word_and_append(cur, cmd, i, envp) == -1)
				return (-1);
		}
		else if ((*cur)->type == HEREDOC)
		{
			if (handle_heredocs(cur, cmd) == -1)
				return (-1);
		}
		*cur = (*cur)->next;
	}
	return (1);
}

t_cmd	*init_new_cmd(t_struct **cur, char **env)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (cmd==NULL)
		return (NULL);
	cmd->heredoc_delim = NULL;
	cmd->outfile = NULL;
	cmd->infile = NULL;
	cmd->outfiles = NULL;
	cmd->infiles = NULL;
	cmd->next = NULL;
	cmd->heredoc = 0;
	cmd->append = 0;
	if((*cur))
	{	
		(*cur)->env = env;
	}
	cmd->argv = malloc(sizeof(char *) * (MAX_ARGS + 1));
	if (!cmd->argv)
	{
		free(cmd);
		return (NULL);
	}
	ft_memset(cmd->argv, 0, sizeof(char *) * (MAX_ARGS + 1));
	return (cmd);
}

int	create_cmd_list(t_struct **cur, t_cmd *cmd, char **envp)
{
	t_cmd	*current;
	int		i;

	current = cmd;
	while (*cur)
	{
		i = 0;
		if (fill_cmd_from_token(cur, current, &i, (*cur)->env) == -1)
			return (-1);
		current->argv[i] = NULL;
		if (*cur && (*cur)->type == PIPE)
		{
			if ((*cur)->next)
				*cur = (*cur)->next;
			current->next = init_new_cmd(cur, envp);
			if (!current->next)
				return (-1);
			current = current->next;
		}
	}
	return (1);
}

void	free_all_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;

	while (cmd)
	{
		tmp = cmd->next;
		if (cmd->argv)
			ft_free_array(cmd->argv);
		if (cmd->infile)
			free(cmd->infile);
		if (cmd->outfile)
			free(cmd->outfile);
		if (cmd->outfiles)
			free_outfiles(cmd->outfiles);
		if (cmd->infiles)
			free_outfiles(cmd->infiles);
		if (cmd->heredoc_delim)
			free(cmd->heredoc_delim);
		free(cmd);
		cmd = tmp;
	}
}

t_cmd	*create_cmd_from_tokens(t_struct **cur, char **env, t_exec *exec)
{
	t_cmd		*cmd;
	t_struct	*tmp;
	
	reorder_command_tokens(cur);
	cmd = init_new_cmd(cur, env);
	if (!cmd)
		return (NULL);
	tmp = *cur;
	while (tmp)
	{
		tmp->exec = exec;
		tmp = tmp->next;
	}
	if((*cur))
	{
		if (create_cmd_list(cur, cmd, (*cur)->env) == -1)
			return (NULL);
	}
	return (cmd);
}
