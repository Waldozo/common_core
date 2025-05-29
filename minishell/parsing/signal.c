/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:59:01 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/05/27 17:06:34 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
}

// ctr+\ il faut le faire dans les child, la sortie sera Quit (core dumped)
void	handle_sigquit(int sig)
{
	(void)sig;
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

//oublie pas d'enlever cette fonction avant de merge
int	cpy_env(t_struct *data, char **envp)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (envp[len])
		len++;
	data->env = malloc(sizeof(char *) * (len + 1));
	if (!data->env)
		return (0);
	while (envp[i])
	{
		data->env[i] = ft_strdup(envp[i]);
		// if (!data->env[i])
		// {
		// 	ft_free_array(data->env);
		// 	return (0);
		// }
		i++;
	}
	data->env[len] = NULL;
	return (1);
}

void	ft_env(t_struct *data, char **cmd)
{
	int	i;

	if (cmd[1])
	{
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd("‘", 2);
		ft_putstr_fd(cmd[1], 2);
		ft_putstr_fd("‘", 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return ;
	}
	i = 0;
	while (data->env[i])
	{
		if (ft_strchr(data->env[i], '='))
			printf("%s\n", data->env[i]);
		i++;
	}
}

char *expand_variables(t_struct *data)
{
	
}