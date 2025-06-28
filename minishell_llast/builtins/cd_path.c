/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:30:40 by fbenkaci          #+#    #+#             */
/*   Updated: 2025/06/27 19:00:04 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

// A la fin faudra tout free c.a.d env_new et env_old

void	free_all(char *new_pwd, char *oldpwd, char *env_old, char *env_new)
{
	if (new_pwd)
		free(new_pwd);
	if (oldpwd)
		free(oldpwd);
	if (env_old)
		free(env_old);
	if (env_new)
		free(env_new);
}

void	free_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		free(envp[i]);
		i++;
	}
	free(envp);
}

int	cd_path(t_struct *data, const char *path)
{
	char		*old_pwd;
	struct stat	path_stat;

	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
		return (0);
	
	// Vérifier si le chemin existe et son type
	if (stat(path, &path_stat) == -1)
	{
		// Le fichier/répertoire n'existe pas
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		ft_putstr_fd((char *)path, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		return (free(old_pwd), 0);
	}
	
	// Vérifier si c'est un répertoire
	if (!S_ISDIR(path_stat.st_mode))
	{
		// C'est un fichier, pas un répertoire
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		ft_putstr_fd((char *)path, STDERR_FILENO);
		ft_putstr_fd(": Not a directory\n", STDERR_FILENO);
		return (free(old_pwd), 0);
	}
	
	if (chdir(path) == -1)
	{
		// Erreur de permission ou autre
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		ft_putstr_fd((char *)path, STDERR_FILENO);
		ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
		return (free(old_pwd), 0);
	}
	if (!update_pwd_vars(data, old_pwd))
		return (0);
	return (1);
}

// int	main(int ac, char **av, char **envp)
// {
// 	(void)ac;
// 	(void)av;
// 	cd_relative_path(envp, "hello/ok");
// 	return (0);
// }

// int cd_absolute_path(const char *path)
// {

// }
