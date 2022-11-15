#include "get_next_line.h"


//get_next_line
//read_line
//copy
//vec_init_or_grow -> ft_bzero
//ft_strlcat

int		vec_init_or_grow(t_vec *stash, size_t new_size)
{
	if (stash->used == 0)
	{
		stash->str = malloc(sizeof(char) * (new_size + 1) ); //need + 1?
		if (!stash->str)
			return (-1);
		stash->str[new_size] = '\0';
		ft_bzero(stash->str, new_size);
		return (0);
	}
	else   // maybe only need this ?
	{
		char *tmp;
		tmp = malloc (sizeof(char) * new_size + 1); // need + 1?
		if (!tmp)
			return (-1);
		tmp[new_size] = '\0';
		strncpy(tmp, stash->str, stash->used);
		free(stash->str);
		stash->str = tmp;
	}
	return (0);
}

char	*copy(char *buff, int read_rtn)
{
	static t_vec stash =(t_vec){NULL, 0, 0};
	char	*rtn;

	rtn = NULL;
	if (vec_init_or_grow(&stash, stash.used + read_rtn) < 0)
		return (NULL);
	stash.used = stash.used + read_rtn;
	ft_strlcat(stash.str, buff, stash.used + 1);
	while (stash.index < stash.used)
	{
		if (stash.str[stash.index] == '\n')
			return (ft_strndup(stash.str, stash.index + 1)); //if return, then its the newline return string.
		stash.index++;
	}
	return (rtn);
}

char	*read_line(int fd)
{
	char	*buff;
	int		read_rtn;

	buff = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buff)
		return (NULL);
	buff[BUFF_SIZE] = '\0';
	read_rtn = read(fd, buff, BUFF_SIZE);
	return (copy(buff, read_rtn));
}


char *get_next_line(int fd)
{

	if(fd < 0)
		return (NULL);
	return (read_line(fd));
}



int main()
{
	int fd;
	fd = open("text.txt", O_RDONLY);
	for (int i = 0; i < 3; i++)
	{
		printf("%s", get_next_line(fd));
	}
		return (0);
}