/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:54:23 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/06/29 16:06:06 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>

extern volatile sig_atomic_t	g_signal_status;

// Forward declarations
typedef struct s_token_pool	t_token_pool;

typedef enum e_token
{
	NONE = -1,
	S_QUOTE,
	D_QUOTE,
	PIPE,
	WORD,
	REDIR_IN,
	REDIR_OUT,
	APPEND,
	HEREDOC,
	PARENTHESIS,
	SPACES,
	WORD_D_QUOTES,
	WORD_S_QUOTES,
	EMPTY_QUOTES,
}								t_token;

typedef struct s_redir
{
	char						*filename;
	int							append;
	struct s_redir				*next;
}								t_redir;

typedef struct s_cmd
{
	char **argv;   // liste des arguments (avec la commande)
	char *infile;  // nom du fichier en entrée
	char *outfile; // nom du fichier en sortie
	int append;    // 1 si >>, 0 si >
	t_redir						*outfiles;
	int heredoc; // 1 si "<<"
	char						*heredoc_delim;
	int							heredoc_fd;
	// pour stocker le delimeut du heredoc (EOF par exemple)
	// int **pipes;
	struct s_cmd				*next;
}								t_cmd;

typedef struct s_exec
{
	int							pids;
	int (*pipes)[2];
	int nb_cmds; // Je vais l'utiliser pour creer le nombre de pipe necessaire
	char						*path;
	int							last_status;
	t_cmd						*cmds;
}								t_exec;

typedef struct s_struct
{
	t_token						type;
	char						*str;
	// int				prev;
	char						**env;
	t_exec						*exec;
	struct s_struct				*next;
	t_token_pool				*token_pool; // Pointeur vers le pool de tokens
	// struct s_struct				*new;
}								t_struct;

/*-------------------- GARBAGE -----------------*/

typedef struct s_gc_node
{
	void						*ptr;
	struct s_gc_node			*next;
}								t_gc_node;

typedef struct s_garbage
{
	t_cmd						*cmd;
	t_struct					*data;
	t_exec						*exec;
	// t_gc_node					*allocations;
}								t_garbage;

void							*gc_malloc(size_t size, t_garbage *gc);
void							*gc_calloc(size_t nmemb, size_t *size,
									t_garbage *gc);
char							*gc_strdup(const char *s, t_garbage *gc);
void							free_garbage(t_garbage *gc);
void							init_garbage(t_garbage *gc);

/*-------------------- EXPAND_HEREDOC -----------------*/
typedef struct s_expand_data
{
	char						*result;
	int							result_len;
	int							j;
}								t_expand_data;

char							*expand_variables_heredoc(t_struct **data,
									char *line);
char							*get_env_value_3(char *var_name);
char							*init_result_buffer(int line_len);
int								resize_buffer_if_needed(t_expand_data *data);

/*-------------------- SIGNAL-----------------*/
void							handle_sigint(int sig);
void							handle_sigint_exec(int sig);

/*-------------------- EXPAND -----------------*/

int								expand_variable(t_struct **cur, char *str,
									char **envp);
char							*replace_variable(char *str, int dollar_pos,
									char *var_name, char *var_value);
char							*extract_var_name(char *str, int start);
char							*get_env_value_2(char *var_name, char **envp);

/*-------------------- EXECUTION -----------------*/
int								execution(t_cmd *cmd, t_exec *exec,
									t_struct **data);
int								open_all_heredocs(t_exec *exec, t_struct **data,
									t_cmd *cmd);
int								execute_single_builtin(t_exec *exec, t_cmd *cmd,
									t_struct **data);
void							setup_redirections(t_cmd *cmd);
void							setup_pipe_redirections(t_exec *exec, int index,
									t_cmd *cmd);
void							run_command(t_struct **data, t_exec *exec,
									t_cmd *cmd);
void							complete_cleanup_and_exit(t_struct **data,
									t_exec *exec, t_cmd *cmd, int exit_code);
void							child_cleanup_and_exit(int exit_code);
void							close_pipes_and_wait(t_exec *exec);
int								fork_and_execute_commands(t_struct **data,
									t_exec *exec, t_cmd *cmd);
void							handle_cmd_error(char *cmd);

void							free_all_cmd(t_cmd *cmd);
void							free_tokens(t_struct *tokens);
void							free_all_shell_parent(t_struct **data, 
									t_exec *exec, t_cmd *cmd);
void							close_unused_pipes(t_exec *data, int index);
int								command_loc(t_struct *data, t_exec *exec,
									char *cmd);
t_cmd							*create_cmd_from_tokens(t_struct **cur,
									char **env, t_exec *exec);
int								heredoc_input(t_struct **data, char *delimiter);
int								caculate_nb_cmd(t_exec *data, t_cmd *cmd);
int								create_pipe(t_exec *data);
int								handle_out_and_in(t_struct **cur, t_cmd *cmd);
int								handle_word_and_append(t_struct **cur, t_cmd *cmd, 
									int *i, char **envp);

/*--------------------utils-----------------*/
// int					ft_strlen(char *str);
// int					ft_strcmp(const char *s1, const char *s2);
// char				**ft_split(const char *s, char c);
// char				*ft_strchr(char *str, int n);
// char				*ft_strdup(char *src);
// size_t				ft_strcpy(char *dst, char *src);
size_t							ft_strcat(char *dst, char *src);
// size_t				ft_strlcpy char *dst, char *src, size_t size);

/*------------------parsing-----------------*/

int								parsing(t_struct *data);
void							is_token(t_struct *data);
int								identify_special_token(t_struct *data, int i);
int								identify_redirection(t_struct *data, int i);

/*--------------parsing pipe----------------*/

int								utils_parse_pipe(t_struct *data, int i,
									int *found_pipe);
int								parse_error_pipe(t_struct *data);

/*--------------parsing redir----------------*/

int								parse_redir(t_struct *data);
int								utils_parse_redir(t_struct *data, int i,
									int *found_redir);
int								handle_redir(t_struct *data, int i,
									int *found_redir);
int								get_error_type(t_struct *data);
int								handle_output_redir(t_struct *data, int i,
									int *found_redir);
int								handle_input_redir(t_struct *data, int i,
									int *found_redir);
int								handle_token_chars(t_struct *data, int i,
									int *found_redir);
int								process_char(t_struct *data, int i,
									int *found_redir);

/*---------------parsing quote---------------*/

int								parsing_quote(t_struct *data);

/*--------------------path------------------*/

char							*find_path(char *cmd, char **paths);
void							free_paths(char **paths);

/*---------------special tokens-------------*/

void							free_token_list(t_struct *start);
t_struct						*create_token(const char *str, int len,
									t_token type, t_struct *new);
int								token_init(t_struct *data);
void							tokenize_string(t_struct *data, int i);
void							token_append(t_struct *data);

/*-----------------handle------------------*/

void							handle_space_token(char *s, int *i,
									t_struct **cur);
void							handle_word_token(char *s, int *i,
									t_struct **cur);
void							handle_special_tokens(char *s, int *i,
									t_struct **cur);
void							append_and_advance(t_struct **cur,
									t_struct *new);
void							handle_redir_token(char *s, int *i,
									t_struct **cur);
void							handle_quotes(char *s, int *i, t_struct **cur);
/*-----------------word quote------------------*/

void							word_quote(t_struct *data, int *i,
									t_struct **cur);
void							handle_word_d_quotes(t_struct *data, int *i,
									t_struct **cur);
void							handle_word_s_quotes(t_struct *data, int *i,
									t_struct **cur);

/*-----------------fusion token------------------*/

void							echo_fusion(t_struct *data);

# include "../builtins/builtins.h"

/*--------------multiple redirections----------------*/

int								handle_multiple_outfiles(t_cmd *cmd);
void							free_outfiles(t_redir *outfiles);
t_redir							*create_redir_node(char *filename, int append);

/*--------------parsing redir----------------*/

// Structure pour gérer le pool de tokens (allocation dynamique)
typedef struct s_token_pool
{
	t_struct				*tokens;     // Array de tokens alloué dynamiquement
	int						index;       // Index actuel dans le pool
	int						capacity;    // Capacité actuelle du pool
}							t_token_pool;

/*--------------token pool functions----------------*/
t_token_pool					*init_token_pool(int initial_capacity);
t_struct					*get_token_from_pool(t_token_pool *pool);
void						reset_token_pool(t_token_pool *pool);
void						free_token_strings_only(t_token_pool *pool);
void						free_token_pool(t_token_pool *pool);

#endif