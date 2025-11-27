
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct  s_stack
{
    int             number;
    struct s_stack  prev;
    struct s_stack  next;
}                   t_stack;

#endif