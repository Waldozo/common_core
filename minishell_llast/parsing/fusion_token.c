/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:42:59 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/06/29 16:06:06 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	can_join_tokens(t_struct *current, t_struct *next)
{
	if (!current || !next)
		return (0);
	if (next->type == SPACES)
		return (0);
	if (current->str && ft_strcmp(current->str, "=") == 0)
		return (0);
	if ((current->type == WORD_D_QUOTES || current->type == WORD_S_QUOTES)
		&& (next->type == WORD || next->type == WORD_D_QUOTES
			|| next->type == WORD_S_QUOTES))
		return (1);
	if (current->type == WORD 
		&& (next->type == WORD_D_QUOTES || next->type == WORD_S_QUOTES))
		return (1);
	
	return (0);
}

int	join_quoted_tokens(t_struct *current)
{
	t_struct	*temp;
	char		*joined_str;

	if (!(can_join_tokens(current, current->next)))
		return (0);
	joined_str = ft_strjoin(current->str, current->next->str);
	if (!joined_str)
		return (0);
	// PROBLÈME : On ne peut pas faire free des elements du pool !
	// Solution : on laisse les anciennes strings, elles seront libérées par reset_token_pool
	current->str = joined_str; // Remplacer par la nouvelle string
	temp = current->next;
	current->next = temp->next;
	// Ne pas libérer temp->str ni temp car ils font partie du pool
	// Mettre temp->str à NULL pour éviter double free dans reset_token_pool
	temp->str = NULL;
	return (1);
}

int	process_quote_chars(char *str, char *clean)
{
	int	i;
	int	j;
	int	in_dquote;
	int	in_squote;

	i = 0;
	j = 0;
	in_dquote = 0;
	in_squote = 0;
	while (str[i])
	{
		if ((str[i] == '"' && !in_squote) || (str[i] == '\'' && !in_dquote))
		{
			if (str[i] == '"')
				in_dquote = !in_dquote;
			else
				in_squote = !in_squote;
			i++;
			continue ;
		}
		clean[j++] = str[i++];
	}
	return (j);
}

void clean_quotes(t_struct *token)
{
    char *clean;
    int clean_len;
    size_t original_len;

    if (!token || !token->str)
        return;

    original_len = ft_strlen(token->str);
    clean = malloc(original_len + 1);
    if (!clean)
        return;

    clean_len = process_quote_chars(token->str, clean);
    clean[clean_len] = '\0';
    
    // Only replace if the string actually changed
    if (clean_len != (int)original_len || ft_strcmp(token->str, clean) != 0)
    {
        free(token->str);
        token->str = clean;
    }
    else
    {
        // No change needed, free the temporary buffer
        free(clean);
    }
}

void	echo_fusion(t_struct *data)
{
	t_struct	*current;
	int fused;

	if (!data)
		return ;
	fused = 1;
	while (fused)
	{
		fused = 0;
		current = data;
		while (current && current->next)
		{
			if (current->type == SPACES)
			{
				current = current->next;
				continue;
			}
			if (current->next->type == SPACES)
			{
				current = current->next;
				continue;
			}
			if (join_quoted_tokens(current))
			{
				fused = 1;
				continue ;
			}
			current = current->next;
		}
	}
	current = data;
	while (current)
	{
		// Skip the main data structure, only process actual tokens
		if (current->type != NONE && (current->type == WORD || current->type == WORD_D_QUOTES || current->type == WORD_S_QUOTES))
			clean_quotes(current);
		current = current->next;
	}
}
