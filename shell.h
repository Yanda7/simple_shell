#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_q;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_q *env;
	list_q *history;
	list_q *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory management */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_r;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flags
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_r *);
} builtin_table;


/* to_shloop.c */
int hsh(info_t *, char **);
int find_builtin(info_r *);
void find_cmd(info_r *);
void fork_cmd(info_r *);

/* to_parser.c */
int is_cmd(info_r *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_r *, char *, char *);

/* loophsh.c */
int loophsh(char **);

/* to_errors.c */
void _Cputs(char *);
int _Cputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* to_string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* to_string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* to_exits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* toem_tokenizer.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* to_realloc.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* to_memory.c */
int bfree(void **);

/* to_atoi.c */
int interactive(info_r *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* to_errors1.c */
int _erratoi(char *);
void print_error(info_r *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* to_builtin.c */
int _pExit(info_r *);
int _Pcd(info_r *);
int _Phelp(info_r *);

/* to_builtin1.c */
int _Phistory(info_r *);
int _Palias(info_r *);

/*to_getline.c */
size_j get_input(info_r *);
int _getline(info_r *, char **, size_j *);
void sigintHandler(int);

/* to_getinfo.c */
void clear_info(info_r *);
void set_info(info_r *, char **);
void free_info(info_r *, int);

/* to_environ.c */
char *_getenv(info_r *, const char *);
int _Penv(info_r *);
int _Psetenv(info_r *);
int _Punsetenv(info_r *);
int populate_env_list(info_r *);

/* to_getenv.c */
char **get_environ(info_r *);
int _unsetenv(info_r *, char *);
int _setenv(info_r *, char *, char *);

/* to_history.c */
char *get_history_file(info_r *info);
int write_history(info_r *info);
int read_history(info_r *info);
int build_history_list(info_r *info, char *buf, int linecount);
int renumber_history(info_r *info);

/* to_lists.c */
list_q *add_node(list_q **, const char *, int);
list_q *add_node_end(list_q **, const char *, int);
size_q print_list_str(const list_q *);
int delete_node_at_index(list_q **, unsigned int);
void free_list(list_q **);

/* to_lists1.c */
size_j list_len(const list_q *);
char **list_to_strings(list_q *);
size_j print_list(const list_q *);
list_q *node_starts_with(list_q *, char *, char);
ssize_j get_node_index(list_q *, list_q *);

/* to_vars.c */
int is_chain(info_r *, char *, size_j *);
void check_chain(info_r *, char *, size_j *, size_j, size_j);
int replace_alias(info_r *);
int replace_vars(info_r *);
int replace_string(char **, char *);

#endif
