#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 16
 
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //*** POISTA **********************
#include <fcntl.h> //*** POISTA *********************
#include <string.h>//*** POISTA *********************
typedef struct s_vec
{
	char	*str;
	size_t	used;
	size_t	index;
}t_vec;

char *get_next_line(int fd);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strndup(const char *s1, size_t n);


#endif