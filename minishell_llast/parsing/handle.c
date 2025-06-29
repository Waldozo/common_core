/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:57:06 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/06/29 12:59:16 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_space_token(char *s, int *i, t_struct **cur)
{
	append_and_advance(cur, create_token(" ", 1, SPACES, *cur));
	if (s[*i])
		(*i)++;
}

void	handle_word_token(char *s, int *i, t_struct **cur)
{
	int		start;
	int		temp_i;
	char	*word_content;
	int		content_len;
	int		j;

	start = *i;
	if (s[*i] == '=')
	{
		(*i)++;
		append_and_advance(cur, create_token(s + start, 1, WORD, *cur));
		return;
	}
	temp_i = *i;
	content_len = 0;
	while (s[temp_i] && s[temp_i] != ' ' && s[temp_i] != '<' && s[temp_i] != '>' && s[temp_i] != '|'
		&& s[temp_i] != '(' && s[temp_i] != ')')
	{
		if (s[temp_i] == '\"' || s[temp_i] == '\'')
		{
			char quote_char = s[temp_i];
			temp_i++; // Skip opening quote
			if (s[temp_i] == quote_char)
			{
				temp_i++; // Skip closing quote
				continue;
			}
			else
				break;
		}
		else if (s[temp_i] == '=')
			break;
		else
		{
			content_len++;
			temp_i++;
		}
	}
	if (content_len == 0)
		return;
	word_content = malloc(content_len + 1);
	if (!word_content)
		return;
	j = 0;
	while (s[*i] && s[*i] != ' ' && s[*i] != '<' && s[*i] != '>' && s[*i] != '|'
		&& s[*i] != '(' && s[*i] != ')')
	{
		if (s[*i] == '\"' || s[*i] == '\'')
		{
			char quote_char = s[*i];
			(*i)++; // Skip opening quote
			if (s[*i] == quote_char)
			{
				(*i)++; // Skip closing quote
				continue;
			}
			else
			{
				(*i)--; // Back up to let quote handler deal with it
				break;
			}
		}
		else if (s[*i] == '=')
			break;
		else
		{
			word_content[j++] = s[*i];
			(*i)++;
		}
	}
	
	word_content[j] = '\0';
	append_and_advance(cur, create_token(word_content, content_len, WORD, *cur));
	free(word_content);
}

void	handle_special_tokens(char *s, int *i, t_struct **cur)
{
	if (s[*i] == '|')
	{
		append_and_advance(cur, create_token("|", 1, PIPE, *cur));
		(*i)++;
	}
	else if (s[*i] == '(')
	{
		append_and_advance(cur, create_token("(", 1, PARENTHESIS, *cur));
		(*i)++;
	}
	else if (s[*i] == ')')
	{
		append_and_advance(cur, create_token(")", 1, PARENTHESIS, *cur));
		(*i)++;
	}
	else if (s[*i] == '\'')
	{
		append_and_advance(cur, create_token("'", 1, S_QUOTE, *cur));
		(*i)++;
	}
	else if (s[*i] == '\"')
	{
		append_and_advance(cur, create_token("\"", 1, D_QUOTE, *cur));
		(*i)++;
	}
}

void	handle_redir_token(char *s, int *i, t_struct **cur)
{
	if (s[*i] == '>' && s[*i + 1] == '>')
	{
		append_and_advance(cur, create_token(">>", 2, APPEND, *cur));
		*i += 2;
	}
	else if (s[*i] == '<' && s[*i + 1] == '<')
	{
		append_and_advance(cur, create_token("<<", 2, HEREDOC, *cur));
		*i += 2;
	}
	else if (s[*i] == '>')
	{
		append_and_advance(cur, create_token(">", 1, REDIR_OUT, *cur));
		(*i)++;
	}
	else if (s[*i] == '<')
	{
		append_and_advance(cur, create_token("<", 1, REDIR_IN, *cur));
		(*i)++;
	}
}

void	append_and_advance(t_struct **cur, t_struct *new)
{
	if(!new)
		return;
	(*cur)->next = new;
	*cur = new;
}