/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:57:35 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/06/28 19:19:21 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	word_d_quotes(char *s, int *i, t_struct **cur)
{
	int	start;
	int	len;

	start = *i;
	while (s[*i] && s[*i] != '\"' && s[*i] != '\'')
		(*i)++;
	len = *i - start;
	append_and_advance(cur, create_token(s + start, len, WORD_D_QUOTES, *cur));
}

void	word_s_quotes(char *s, int *i, t_struct **cur)
{
	int	start;
	int	len;

	start = *i;
	while (s[*i] && s[*i] != '\'')
		(*i)++;
	len = *i - start;
	append_and_advance(cur, create_token(s + start, len, WORD_S_QUOTES, *cur));
}

void	handle_d_quotes(char *s, int *i, t_struct **cur)
{
	int	start;
	int	len;

	start = *i;
	(*i)++;
	while (s[*i] && s[*i] != '\"')
		(*i)++;
	if (s[*i] == '\"')
		(*i)++;
	len = *i - start;
	
	// Check if quotes are empty ("")
	if (len == 2 && s[start] == '\"' && s[start + 1] == '\"')
	{
		// Don't create any token for empty quotes - this will make adjacent tokens truly adjacent
		return;
	}
	else
	{
		append_and_advance(cur, create_token(s + start, len, WORD_D_QUOTES, *cur));
	}
}

void	handle_s_quotes(char *s, int *i, t_struct **cur)
{
	int	start;
	int	len;

	start = *i;
	(*i)++;
	while (s[*i] && s[*i] != '\'')
		(*i)++;
	if (s[*i] == '\'')
		(*i)++;
	len = *i - start;
	
	// Check if quotes are empty ('')
	if (len == 2 && s[start] == '\'' && s[start + 1] == '\'')
	{
		// Don't create any token for empty quotes
		return;
	}
	else
		append_and_advance(cur, create_token(s + start, len, WORD_S_QUOTES, *cur));
}

void	handle_quotes(char *s, int *i, t_struct **cur)
{
	if (s[*i] == '\"')
		handle_d_quotes(s, i, cur);
	else if (s[*i] == '\'')
		handle_s_quotes(s, i, cur);
}
