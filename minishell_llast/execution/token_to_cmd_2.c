/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_cmd_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:16:07 by fbenkaci          #+#    #+#             */
/*   Updated: 2025/06/28 19:45:57 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/minishell.h"

int	handle_in(t_struct **cur, t_cmd *cmd)
{
	if ((*cur)->next)
	{
		while (*cur && (*cur)->next && (*cur)->next->type == SPACES)
			*cur = (*cur)->next;
		if (cmd->infile)
			free(cmd->infile);
		cmd->infile = ft_strdup((*cur)->next->str);
		if (!cmd->infile)
			return (-1);
		if ((*cur)->next)
			*cur = (*cur)->next;
		return (1);
	}
	return (0);
}

int	handle_out(t_struct **cur, t_cmd *cmd, int fd)
{
	t_redir	*new_redir;
	t_redir	*current;

	(void)fd;
	if ((*cur)->next)
	{
		*cur = (*cur)->next;
		while (*cur && (*cur)->type == SPACES)
			*cur = (*cur)->next;
		if (!*cur)
			return (-1);
		
		// Create new redirection node
		new_redir = create_redir_node((*cur)->str, 0);
		if (!new_redir)
			return (-1);
		
		// Add to outfiles list
		if (!cmd->outfiles)
			cmd->outfiles = new_redir;
		else
		{
			current = cmd->outfiles;
			while (current->next)
				current = current->next;
			current->next = new_redir;
		}
		
		// Keep backward compatibility with single outfile
		if (cmd->outfile)
			free(cmd->outfile);
		cmd->outfile = ft_strdup((*cur)->str);
		cmd->append = 0;
		if (!cmd->outfile)
			return (-1);
	}
	return (1);
}

int	handle_out_and_in(t_struct **cur, t_cmd *cmd)
{
	int	fd;

	fd = 0;
	if (*cur && (*cur)->type == REDIR_OUT)
	{
		if (handle_out(cur, cmd, fd) == -1)
			return (-1);
		if ((*cur)->next)
			*cur = (*cur)->next;
		return (1);
	}
	else if (*cur && (*cur)->type == REDIR_IN)
		if (handle_in(cur, cmd) == -1)
			return (-1);
	return (0);
}

int	handle_word_and_expand(t_struct **cur, t_cmd *cmd, int *i, char **envp)
{
	char	*combined_arg;
	char	*temp;

	if (*cur && ((*cur)->type == WORD || (*cur)->type == WORD_D_QUOTES
			|| (*cur)->type == WORD_S_QUOTES || (*cur)->type == EMPTY_QUOTES))
	{
		// Check for VAR=VALUE pattern (WORD + = + WORD)
		if ((*cur)->next && (*cur)->next->type == WORD && 
			(*cur)->next->str && ft_strcmp((*cur)->next->str, "=") == 0 && 
			(*cur)->next->next && ((*cur)->next->next->type == WORD || 
			(*cur)->next->next->type == WORD_D_QUOTES || 
			(*cur)->next->next->type == WORD_S_QUOTES || 
			(*cur)->next->next->type == EMPTY_QUOTES))
		{
			// Combine VAR + = + VALUE into single argument
			temp = ft_strjoin((*cur)->str, "=");
			if (!temp)
				return (-1);
			combined_arg = ft_strjoin(temp, (*cur)->next->next->str);
			free(temp);
			if (!combined_arg)
				return (-1);
			
			cmd->argv[*i] = combined_arg;
			(*i)++;
			
			// Skip the = and value tokens
			*cur = (*cur)->next->next;
			return (1);
		}
		
		// Regular word processing
		if (ft_strchr((*cur)->str, '$') && (*cur)->type != WORD_S_QUOTES)
		{
			if (expand_variable(cur, (*cur)->str, envp) == -1)
				return (-1);
			if ((*cur)->str[0] == '\0')
			{
				return (1);
			}
			cmd->argv[*i] = ft_strdup((*cur)->str);
			if (!cmd->argv[*i])
				return (ft_free_array(cmd->argv), -1);
		}
		else
		{
			cmd->argv[*i] = ft_strdup((*cur)->str);
			if (!cmd->argv[*i])
				return (-1);
		}
		(*i)++;
	}
	return (1);
}

int	handle_word_and_append(t_struct **cur, t_cmd *cmd, int *i, char **envp)
{
	t_redir	*new_redir;
	t_redir	*current;

	if (*cur && (*cur)->type == APPEND)
	{
		if ((*cur)->next)
		{
			while (*cur && (*cur)->next && (*cur)->next->type == SPACES)
				*cur = (*cur)->next;
			if (!(*cur)->next)
				return (-1);
			
			// Create new redirection node for append
			new_redir = create_redir_node((*cur)->next->str, 1);
			if (!new_redir)
				return (-1);
			
			// Add to outfiles list
			if (!cmd->outfiles)
				cmd->outfiles = new_redir;
			else
			{
				current = cmd->outfiles;
				while (current->next)
					current = current->next;
				current->next = new_redir;
			}
			
			// Keep backward compatibility
			if (cmd->outfile)
				free(cmd->outfile);
			cmd->outfile = ft_strdup((*cur)->next->str);
			cmd->append = 1;
			if (!cmd->outfile)
				return (-1);
			if ((*cur)->next)
				*cur = (*cur)->next;
		}
	}
	else if (*cur && ((*cur)->type == WORD || (*cur)->type == WORD_D_QUOTES
			|| (*cur)->type == WORD_S_QUOTES || (*cur)->type == EMPTY_QUOTES))
	{
		if (handle_word_and_expand(cur, cmd, i, envp) == -1)
			return (-1);
	}
	return (1);
}
