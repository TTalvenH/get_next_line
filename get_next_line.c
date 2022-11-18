#include "get_next_line.h"

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
		ft_strlcpy(tmp, stash->str, stash->used + 1);
		free(stash->str);
		stash->str = tmp;
	}
	return (0);
}


int		stash_cut(t_vec *stash)
{
	char *tmp;
	tmp = malloc (sizeof(char) * (stash->used - stash->index));
	if (!tmp)
		return (-1);
	tmp[stash->used - stash->index] = '\0';
	ft_strlcpy(tmp, &stash->str[stash->index + 1], stash->used - stash->index + 1);
	stash->used = stash->used - (stash->index + 1);
	stash->index = 0;
	free (stash->str);
	stash->str = tmp;

	return (0);
}
char	*copy(char *buff, int read_rtn)
{
	static t_vec stash =(t_vec){NULL, 0, 0};

	if (stash.used > 0 && stash.used != (stash.index + 1) )
	{
		if (stash_cut(&stash) < 0)
			return (NULL);
	}
	if (read_rtn)
	{
		if (vec_init_or_grow(&stash, stash.used + read_rtn) < 0)
			return (NULL);
		stash.used = stash.used + read_rtn;
		ft_strlcat(stash.str, buff, stash.used + 1);
	}
	while (stash.index < stash.used)
	{
		if (stash.str[stash.index] == '\n'|| (stash.index + 1) == stash.used)
			return (ft_strndup(stash.str, stash.index + 1)); //if return, then its the newline return string.
		stash.index++;
	}
	return (NULL);

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
		for (int i = 0; i < 7; i++)
	{
		printf("%s", get_next_line(fd));
	}
		return (0);
}