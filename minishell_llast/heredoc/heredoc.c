/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:27:16 by fbenkaci          #+#    #+#             */
/*   Updated: 2025/07/02 14:45:00 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/minishell.h"

int	init_heredoc_pipe(int *fd)
{
	if (pipe(fd) == -1)
	{
		perror("pipe");
		return (-1);
	}
	return (1);
}

int	process_heredoc_line(t_struct **data, char *delimiter, int *fd,
		int *line_nb)
{
	char	*line;
	char	*expanded_line;

	line = readline("> ");
	if (!line)  // Ctrl+D (EOF)
	{
		ft_putstr_fd("\nminishell: warning: here-document at line ", 2);
		ft_putnbr_fd(*line_nb, 2);
		ft_putstr_fd(" delimited by end-of-file (wanted ", 2);
		ft_putstr_fd(delimiter, 2);
		ft_putstr_fd("')\n", 2);
		return (-3);  // EOF: cas spécial, arrêter avec erreur
	}
	
	if (g_signal_status == 130)
	{
		free(line);
		return (-1);
	}
	
	if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0
		&& line[ft_strlen(delimiter)] == '\0')
	{
		free(line);
		return (-2);  // Délimiteur trouvé: arrêter normalement
	}
	
	expanded_line = expand_variables_heredoc(data, line);
	if (expanded_line)
	{
		write(fd[1], expanded_line, ft_strlen(expanded_line));
		write(fd[1], "\n", 1);  // Ajouter le newline
		free(expanded_line);
	}
	
	free(line);
	(*line_nb)++;
	return (1);  // Continue le heredoc
}

void	handle_sigint_heredoc(int sig)
{
	(void)sig;
	g_signal_status = 130;
	write(STDOUT_FILENO, "\n", 1);
}

int	heredoc_input(t_struct **data, char *delimiter)
{
	int					fd[2];
	int					line_nb;
	int					ret;
	struct sigaction	old_sigint;
	struct sigaction	new_sigint;

	line_nb = 1;
	if (init_heredoc_pipe(fd) == -1)
		return (-1);
	new_sigint.sa_handler = handle_sigint_heredoc;
	sigemptyset(&new_sigint.sa_mask);
	new_sigint.sa_flags = 0;
	sigaction(SIGINT, &new_sigint, &old_sigint);
	while (1)
	{
		if (g_signal_status == 130)
		{
			close(fd[0]);
			close(fd[1]);
			sigaction(SIGINT, &old_sigint, NULL);
			return (-1);
		}
		ret = process_heredoc_line(data, delimiter, fd, &line_nb);
		if (ret == -1)
		{
			close(fd[0]);
			close(fd[1]);
			sigaction(SIGINT, &old_sigint, NULL);
			return (-1);
		}
		else if (ret == -2)
		{
			sigaction(SIGINT, &old_sigint, NULL);
			close(fd[1]);
			return (fd[0]);
		}
		else if (ret == -3)  // EOF par Ctrl+D
		{
			sigaction(SIGINT, &old_sigint, NULL);
			close(fd[1]);  // Fermer seulement l'écriture
			return (fd[0]); // Retourner le fd de lecture pour que la commande s'exécute
		}
	}
}

// int handle_heredoc_signal(char *delimiter)
// {
// 	free(delimiter);
// 	// ft_free_array()
// 	g_signal = 0;
// 	close(0);
// 	return (-1);
// }