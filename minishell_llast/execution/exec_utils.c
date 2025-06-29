/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:21:25 by fbenkaci          #+#    #+#             */
/*   Updated: 2025/06/28 20:32:29 by wlarbi-a         ###   ########.fr       */
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
	else
	{
		// handle_cmd_error(cmd->argv[0]);
		// ft_putstr_fd("minishell: ", STDERR_FILENO);
		// ft_putstr_fd("Command not found\n", STDERR_FILENO);
		// exec->last_status = 127;
	}
	return (builtin_status);
}

void	handle_outfile(t_cmd *cmd)
{
	int	fd2;

	fd2 = 0;
	if (cmd->outfile)
	{
		// ft_printf("%s\n", cmd->outfile);
		if (cmd->append)
			fd2 = open(cmd->outfile, O_APPEND | O_CREAT | O_WRONLY, 0644);
		else
			fd2 = open(cmd->outfile, O_TRUNC | O_WRONLY | O_CREAT, 0644);
		if (fd2 < 0)
		{
			if (errno == EACCES) // Error Access
			{
				// ft_putstr_fd("minishell: Permission denied\n",
				// STDER`R_FILENO);
				handle_cmd_error(cmd->outfile);
				// faut que rajoute t_struct a ton prototype
				exit(1);
			}
			// ft_putstr_fd("minishell: Error opening file\n", STDERR_FILENO);
			handle_cmd_error(cmd->outfile);
			exit(1);
		}
		dup2(fd2, STDOUT_FILENO);
		close(fd2);
	}
}

void	setup_redirections(t_cmd *cmd)
{
	int	fd;

	fd = 0;
	if (cmd->outfiles)
		handle_multiple_outfiles(cmd);
	else if (cmd->outfile)
		handle_outfile(cmd);
	if (cmd->heredoc)
	{
		dup2(cmd->heredoc_fd, STDIN_FILENO);
		// Don't free heredoc_delim in child process - it belongs to parent
		// free(cmd->heredoc_delim);
		close(cmd->heredoc_fd);
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
