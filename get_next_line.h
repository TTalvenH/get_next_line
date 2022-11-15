#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //*** POISTA **********************
#include <fcntl.h> //*** POISTA *********************

char *get_next_line(int fd);

#endif