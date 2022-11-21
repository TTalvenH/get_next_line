#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 42
 
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //*** POISTA **********************
#include <fcntl.h> //*** POISTA *********************
typedef struct s_vec
{
	char	*str;
	size_t	used;
	size_t	index;
}t_vec;

char 	*get_next_line(int fd);
void	ft_strlcat(char *dst, const char *src, size_t dstsize, size_t dst_len);
void	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strndup(const char *s1, size_t n);


#endif