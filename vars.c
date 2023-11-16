#include "shell.h"

typedef enum e_chain_type
{
    CMD_CHAIN,
    CMD_AND,
    CMD_OR
} chain_type_t;

chain_type_t chain_type_from_char(char c)
{
    if (c == ';')
        return (CMD_CHAIN);
    else if (c == '&')
        return (CMD_AND);
    else if (c == '|')
        return (CMD_OR);
    return (CMD_CHAIN);
}

void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
    size_t j = *p;

    if (info->cmd_buf_type == CMD_AND)
    {
        if (info->status)
        {
            buf[i] = 0;
            j = len;
        }
    }
    if (info->cmd_buf_type == CMD_OR)
    {
        if (!info->status)
        {
            buf[i] = 0;
            j = len;
        }
    }

    *p = j;
}

void replace_string(char **old, char *new)
{
    free(*old);
    *old = new;
}
