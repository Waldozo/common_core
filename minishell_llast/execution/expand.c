/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:11:27 by fbenkaci          #+#    #+#             */
/*   Updated: 2025/06/28 19:45:29 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/minishell.h"

// int	extract_name(char *var_name, char *current_str, int i)
// {
// 	var_name = extract_var_name(current_str, i + 1);
// 	if (!var_name)
// 		return (-1);
// }

// int	expand_variable(t_struct **cur, char *str, char **envp)
// {
// 	char	*current_str;
// 	char	*new_str;
// 	char	*var_name;
// 	char	*var_value;
// 	int		i;

// 	current_str = str;
// 	i = 0;
// 	while (current_str[i])
// 	{
// 		if (current_str[i] == '$' && current_str[i + 1]
// 			&& (ft_isalpha(current_str[i + 1]) || current_str[i + 1] == '_'))
// 		{
// 			var_name = extract_var_name(current_str, i + 1);
// 			if (!var_name)
// 				return (-1);
// 			var_value = get_env_value_2(var_name, envp);
// 			if (!var_value)
// 				return (free((*cur)->str), (*cur)->str = ft_strdup(""), 1);
// 			new_str = replace_variable(current_str, i, var_name, var_value);
// 			if (!new_str)
// 				return (free(var_name), -1);
// 			if (current_str != str)
// 				free(current_str);
// 			free((*cur)->str);
// 			(*cur)->str = ft_strdup(new_str);
// 			if (!(*cur)->str)
// 				return (free(var_name), free(new_str), -1);
// 			current_str = new_str;
// 			free(var_name);
// 			i = 0;
// 			continue ;
// 		}
// 		i++;
// 	}
// 	if (current_str != str)
// 		free(current_str);
// 	return (0);
// }

int	update_current_string(t_struct **cur, char *original, char *new_str)
{
	if (original != (*cur)->str)
		free(original);
	free((*cur)->str);
	(*cur)->str = ft_strdup(new_str);
	free(new_str); // Libérer new_str après usage
	if (!(*cur)->str)
	{
		return (-1);
	}
	return (0);
}

int	process_variable_expansion(t_struct **cur, char *str, char **envp, int i)
{
	char	*var_name;
	char	*var_value;
	char	*new_str;

	// (*cur)->exec->last_status = 0;
	// ft_printf("%d\n", (*cur)->exec->last_status);
	var_name = extract_var_name(str, i + 1);
	if (!var_name)
	{
		return (-1);
	}
	var_value = get_env_value_2(var_name, envp);
	if (!var_value)
	{
		// Variable not found, replace with empty string but keep the rest
		new_str = replace_variable(str, i, var_name, "");
		if (!new_str)
		{
			free(var_name);
			return (-1);
		}
		free(var_name);
		return (update_current_string(cur, str, new_str));
	}
	new_str = replace_variable(str, i, var_name, var_value);
	if (!new_str)
	{
		// ft_printf("OK1\n");
		free(var_name);
		return (-1);
	}
	free(var_name);
	return (update_current_string(cur, str, new_str));
}

int	expand_variable(t_struct **cur, char *str, char **envp)
{
	char	*current_str;
	int		i;
	int		result;
	char	*new_str;
	char *exit_status_str;
	
	// (*cur)->exec->last_status = 0;
	exit_status_str = NULL;
	new_str = NULL;
	current_str = str;
	i = 0;
	// ft_printf("%d\n", (*cur)->exec->last_status);
	while (current_str[i])
	{
		if (current_str[i] == '$' && current_str[i + 1] == '?')
		{
			// ft_printf("%d\n", (*cur)->exec->last_status);
			exit_status_str = ft_itoa((*cur)->exec->last_status);
			if (!exit_status_str)
				return (-1);
			new_str = replace_variable(current_str, i, "?", exit_status_str);
			if (!new_str)
				return (free(exit_status_str), -1);
			free(exit_status_str);
			result = update_current_string(cur, current_str, new_str);
			if (result != 0)
				return (result);
			current_str = (*cur)->str;
			i = 0;
			continue ;
		}
		if (current_str[i] == '$' && current_str[i + 1]
			&& (ft_isalpha(current_str[i + 1]) || current_str[i + 1] == '_'))
		{
			result = process_variable_expansion(cur, current_str, envp, i);
			if (result != 0)
				return (result);
			current_str = (*cur)->str;
			i = 0;
			continue ;
		}
		i++;
	}
	// ft_printf("%d\n", (*cur)->exec->last_status);
	return (0);
}
