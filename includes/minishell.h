/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:25:27 by rdragan           #+#    #+#             */
/*   Updated: 2023/09/27 03:50:10 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include <stdbool.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <termios.h>
# include <fcntl.h>

typedef struct s_env
{
	char	*key;
	char	*value;
}	t_env;

typedef struct s_cmd
{
	int		type;
	char	**cmd;
}	t_cmd;

typedef struct s_pipe
{
	int		type;
}	t_pipe;

typedef struct s_redir
{
	int		type;
	int		redir_type;
	char	*file;
}	t_redir;

typedef struct s_traverser
{
	int		*fd;
	char	**cmd;
	t_list	*pipe;
}	t_traverser;

typedef struct s_fd
{
	int	*fd;
	int	total_fd;
}	t_fd;

typedef struct s_minishell
{
	char	**cmd;
	char	**envp;
	char	*input;
	t_list	*env_lst;
	t_list	*tokens;
	int		exit_status;
}	t_minishell;

/* init_main */
t_minishell	*init_minishell(void);
char		**add_path_to_env(void);
void		init_envp(t_minishell *mish, char **envp);
int			init_lst(t_minishell *mish);

/* Tokens */
char		**mini_split(char *s);
char		**check_error(char **split_input);
char		**sort_split(char **s);

/* List */
t_list		*create_lst(char **str);
void		*node_data(char **str, int *i);
t_redir		*create_redir(char **s, int *i);
t_pipe		*create_pipe(int *i);
t_cmd		*create_cmd(char **s, int *i);

t_list		*del_lst(t_list *root);
void		delete_lst_node_content(void *content);

/* Expander */
void		expander(t_list *tokens, t_list *env, int exit_status);
char		*conv_to_env_var(char *s, t_list *env, int exit_status, int i);
char		*env_var(t_list *env, char *s);
void		rm_quotes(t_list *tokens);

/* Expander utils */
int			count_exit_status_tokens(char *string);
int			exit_status_length(int exit_status);
char		*expand_env_variables(t_list *env, char *string);

/* env utils */
t_list		*copy_env(char **env);
t_env		*parse_env_variable(char *s);
t_list		*free_env(t_list *env);
t_list		*search_variable(t_list *env, char *key);
char		**get_tmp_envp(t_list *env_lst);
/* Execution */
int			executer(t_minishell *minishell);
void		handle_redir(t_traverser *tmp);
void		cmd_unknown(char *cmd, char *error);
int			execute_cmd_from_default_path(t_traverser *tmp, char **envp);
int			execute_not_default_bin(t_traverser *tmp, char **envp);
int			execute_cmd(t_minishell *mish, t_traverser *tmp);

/* Execution utils */
void		free_tmp(t_traverser *tmp);
int			exec_builtin(t_minishell *mish, t_traverser *tmp);
int			is_builtin(char **cmd);
t_traverser	*traverse_files(t_list *cmd);
void		open_pipes(int total_fd, int *fd);
void		close_pipes(int total_fd, int *fd);
void		close_parent_pipes(int total_fd, int *fd);
char		**get_paths(char **envp);
char		*join_paths(char *path1, char *path2);
char		*get_bin(char **envp, char *cmd);
int			is_default_path(char *cmd, char **envp);
int			is_directory(char *path);
int			get_split_len(char **split);
int			count_total_pipes(t_list *start);

/* Builtins */
void		exit_mish(t_minishell *mish);
int			cd(t_list *env, char **input);
int			print_env(t_list *env);
void		modify_env_variable(t_list *env, t_env *env_var);
int			export(char **input, t_list *env);
int			echo(char **input);
int			pwd(void);
int			exit_builtin(char **input, int exit_status);
int			unset(t_list **env, char **input);

/* Signal handling */
void		handle_sigquit(int signal);
void		handle_signals(void);

/* Redirection */
int			here_doc(char **cmd);
void		set_fds(int *fd, int failed_input);

#endif