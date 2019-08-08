#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "libft/libft.h"

//---------------------Read 1 File------------------------------------

int	main(int argc, char **argv)
{
	int		fd;
	int		fd1;
	char	*line;
	int		ret;

//	line = NULL;
	fd = open(argv[1], O_RDONLY);
//	fd1 = open(argv[2], O_RDONLY);
	if (argc >= 2)
	{
		while ((ret = get_next_line(42, &line))) //|| get_next_line(fd1, &line))
		{
			ft_putendl(line);
			free(line);
			printf("%d\n",ret);
			return(0);
		}
	}
	close(fd);
//	close(fd1);
	return (0);
}

//-----------------------Take Input-------------------------------------

/*int        main()
{
	int        fd;
	char    *str;

 while(get_next_line(0, &str))
 {
	 ft_putendl(str);
 }
 return (0);
}

//--------------------------Read A Single Line-----------------------------

int        main(void)
{
    int        fd;
    char    *str;

    fd = open("bible.txt", O_RDONLY);
    get_next_line(fd, &str);
	ft_putendl(str);
    free(str);
	ft_putchar('\n');
    return (0);
}*/
