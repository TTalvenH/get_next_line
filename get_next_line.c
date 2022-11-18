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


char	*stash_cut(t_vec *stash)
{
	char *tmp;
	char *rtn;

	rtn = ft_strndup(stash->str, stash->index + 1);
	tmp = malloc (sizeof(char) * (stash->used - stash->index));
	if (!tmp)
		return (NULL);
	tmp[stash->used - (stash->index + 1)] = '\0';
	ft_strlcpy(tmp, &stash->str[stash->index + 1], stash->used - stash->index + 1);
	stash->used = stash->used - (stash->index + 1);
	stash->index = 0;
	//free (stash->str);
	stash->str = tmp;
	return (rtn);
}

char	*copy(char *buff, int read_rtn)
{
	static t_vec stash =(t_vec){NULL, 0, 0};

	//if (stash.used > 0 && stash.used != (stash.index + 1) )
	//{
	//	if (stash_cut(&stash) < 0)
	//		return (NULL);
	//}
	if (read_rtn)
	{
		if (vec_init_or_grow(&stash, stash.used + read_rtn) < 0)
			return (NULL);
		stash.used = stash.used + read_rtn;
		ft_strlcat(stash.str, buff, stash.used + 1);
		//free (buff);
	}
	if (stash.index + 1 == stash.used && !read_rtn)
		return (NULL);
	while ((stash.index) != stash.used)
	{
		if (stash.str[stash.index] == '\n' || (stash.index + 1 == stash.used && !read_rtn))
			return (stash_cut(&stash)); //if return, then its the newline return string.
		stash.index++;
	}
	return (NULL);
}

char *get_next_line(int fd)
{
	char	*buff;
	char	*rtn;
	int		read_rtn;

	read_rtn = 1;
	rtn = NULL;
	buff = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buff)
		return (NULL);
	buff[BUFF_SIZE] = '\0';
	while (!rtn && read_rtn)
	{
		read_rtn = read(fd, buff, BUFF_SIZE);
		rtn = copy(buff, read_rtn);
	}
	return (rtn);
}	

int main()
{
	int fd;
	char	*str;
	fd = open("text.txt", O_RDONLY);
		for (int i = 0; i < 7; i++)
	{
		str = get_next_line(fd);
		printf("%s", str);
		//free (str);
	}
	system("export MallocStackLogging=1");
    system("leaks get_next_line");
	return (0);
}