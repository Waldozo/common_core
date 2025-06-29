/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:43:07 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/06/29 16:25:41 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


t_token_pool	*init_token_pool(int initial_capacity)
{
	t_token_pool	*pool;

	pool = malloc(sizeof(t_token_pool));
	if (!pool)
		return (NULL);
	
	pool->tokens = malloc(sizeof(t_struct) * initial_capacity);
	if (!pool->tokens)
	{
		free(pool);
		return (NULL);
	}
	
	pool->index = 0;
	pool->capacity = initial_capacity;
	return (pool);
}

t_struct	*get_token_from_pool(t_token_pool *pool)
{
	t_struct	*new_tokens;
	int			new_capacity;
	int			i;

	if (!pool)
		return (NULL);
	if (pool->index >= pool->capacity)
	{
		new_capacity = pool->capacity * 2;
		new_tokens = malloc(sizeof(t_struct) * new_capacity);
		if (!new_tokens)
			return (NULL);
		// Copier les anciens tokens vers le nouveau tableau
		i = 0;
		while (i < pool->index)
		{
			new_tokens[i] = pool->tokens[i];
			i++;
		}
		// Libérer l'ancien tableau
		free(pool->tokens);
		pool->tokens = new_tokens;
		pool->capacity = new_capacity;
	}
	return (&pool->tokens[pool->index++]);
}

void	reset_token_pool(t_token_pool *pool)
{
	int	i;

	if (!pool)
		return;
	i = 0;
	// Libérer toutes les strings allouées
	while( i < pool->index)
	{
		if (pool->tokens[i].str)
		{
			free(pool->tokens[i].str);
			pool->tokens[i].str = NULL;
		}
		i++;
	}
	// Réinitialiser l'index
	pool->index = 0;
}

void	free_token_pool(t_token_pool *pool)
{
	if (!pool)
		return;
	
	// Libérer toutes les strings d'abord
	reset_token_pool(pool);
	
	// Libérer le tableau de tokens
	if (pool->tokens)
		free(pool->tokens);
	
	// Libérer la structure du pool
	free(pool);
}

void	free_token_list(t_struct *start)
{
	t_struct	*tmp;

	while (start)
	{
		tmp = start;
		start = start->next;
		free(tmp->str);
		free(tmp);
	}
}

t_struct	*create_token(const char *str, int len, t_token type, t_struct *data)
{
	t_struct	*new;
	int			i;

	if (!data || !data->token_pool)
		return (NULL);
	
	new = get_token_from_pool(data->token_pool);
	if (!new)
		return (NULL);
	new->str = malloc(len + 1);
	if (!new->str)
		return (NULL);
		
	i = 0;
	while (i < len)
	{
		new->str[i] = str[i];
		i++;
	}
	new->str[i] = '\0';
	new->type = type;
	new->next = NULL;
	new->env = NULL;
	new->exec = NULL;
	new->token_pool = data->token_pool;
	
	return (new);
}

int	token_init(t_struct *data)
{
	int		i;

	i = 0;
	if (!data || !data->str)
		return (-1);
	data->next = NULL;
	data->type = NONE; // Ensure data is not treated as a token
	while (data->str[i] && data->str[i] != ' ' && data->str[i] != '<'
		&& data->str[i] != '>' && data->str[i] != '|' && data->str[i] != '('
		&& data->str[i] != ')' && data->str[i] != '\'' && data->str[i] != '\"')
		i++;
	i = 0;
	return (i);
}

void	tokenize_string(t_struct *data, int i)
{
	t_struct	*cur;
	int			flag;

	if (i < 0)
		return ;
	cur = data;
	flag = 0;
	while (data->str[i])
	{
		if (data->str[i] == ' ')
			handle_space_token(data->str, &i, &cur);
		else if (data->str[i] == '\"' || data->str[i] == '\'')
			handle_quotes(data->str, &i, &cur);

		else if (data->str[i] == '<' || data->str[i] == '>')
			handle_redir_token(data->str, &i, &cur);
		else if (data->str[i] == '|' || data->str[i] == '(' || data->str[i] == ')')
			handle_special_tokens(data->str, &i, &cur);
		else
			handle_word_token(data->str, &i, &cur);
		if (i >= (int)ft_strlen(data->str))
			break;
	}
}

void	token_append(t_struct *data)
{
	int	start_index;

	start_index = token_init(data);
	if (start_index >= 0)
		tokenize_string(data, start_index);
}

void	free_token_strings_only(t_token_pool *pool)
{
	int	i;

	if (!pool)
		return;
	
	// Libérer seulement les strings allouées, pas la structure du pool
	for (i = 0; i < pool->index; i++)
	{
		if (pool->tokens[i].str)
		{
			free(pool->tokens[i].str);
			pool->tokens[i].str = NULL;
		}
	}
	// NE PAS réinitialiser l'index ni toucher à la structure du pool
}
