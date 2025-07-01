/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_cmd_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:54:00 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/07/01 17:34:12 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/minishell.h"

int	handle_append_redirection(t_struct **cur, t_cmd *cmd)
{
	t_redir	*new_redir;

	if (!(*cur)->next)
		return (1);
	while (*cur && (*cur)->next && (*cur)->next->type == SPACES)
		*cur = (*cur)->next;
	if (!(*cur)->next)
		return (-1);
	new_redir = create_redir_node((*cur)->next->str, 1);
	if (!new_redir)
		return (-1);
	add_outfile_to_list(cmd, new_redir, (*cur)->next->str);
	cmd->append = 1;
	if (!cmd->outfile)
		return (-1);
	if ((*cur)->next)
		*cur = (*cur)->next;
	return (1);
}
