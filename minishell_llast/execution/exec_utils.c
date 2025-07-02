/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:21:25 by fbenkaci          #+#    #+#             */
/*   Updated: 2025/07/02 15:21:24 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/minishell.h"

int	open_all_heredocs(t_exec *exec, t_struct **data, t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp)
	{
		if (tmp->heredoc)
		{
			tmp->heredoc_fd = heredoc_input(data, tmp->heredoc_delim);
			if (tmp->heredoc_fd < 0)
			{
				if (g_signal_status == 130)
				{
					exec->last_status = 130;
					return (130);
				}
				return (-1);
			}
		}
		tmp = tmp->next;
	}
	return (1);
}

int	execute_single_builtin(t_exec *exec, t_cmd *cmd, t_struct **data)
{
	int	saved_stdin;
	int	builtin_status;

	saved_stdin = 0;
	if (cmd->heredoc)
	{
		saved_stdin = dup(STDIN_FILENO);
		dup2(cmd->heredoc_fd, STDIN_FILENO);
		close(saved_stdin);
		free(cmd->heredoc_delim);
	}
	builtin_status = exec_builtin(exec, *data, cmd);
	if (builtin_status == 1)
	{
		if (cmd->heredoc)
		{
			close(cmd->heredoc_fd);
			dup2(saved_stdin, STDIN_FILENO);
			close(saved_stdin);
			free(cmd->heredoc_delim);
		}
	}
	return (builtin_status);
}

void	setup_redirections(t_struct *data, t_cmd *cmd, t_exec *exec)
{
	int	fd;

	fd = 0;
	if (cmd->outfiles)
	{
		if (handle_multiple_outfiles(data, cmd, exec) == -1)
			exit(1);  // Seulement exit dans le processus enfant
	}
	if (cmd->heredoc)
	{
		dup2(cmd->heredoc_fd, STDIN_FILENO);
		close(cmd->heredoc_fd);
	}
	else if (cmd->infiles)
	{
		if (handle_multiple_infiles(data, cmd, exec) == -1)
			exit(1);  // Seulement exit dans le processus enfant
	}
	else if (cmd->infile)
	{
		fd = open(cmd->infile, O_RDONLY);
		if (fd < 0)
		{
			handle_cmd_error(cmd->infile);
			exit(1);
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
}
