#ifndef _GNU_SOURCE
#define _GNU_SOURCE

#include <stddef.h>
#include <stdio.h>

/* Get ssize_t.  */
# include <sys/types.h>

ssize_t getline (char **_lineptr, size_t *_linesize, FILE *_stream);


#endif /* not _GNU_SOURCE */
