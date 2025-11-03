#include <unistd.h>

0 | STDIN	| entre standard
1 | STDOU	| sortie standard
2 | STDERR	| sortie error
3 | FD_1	| fichier ouvert

int main()
{
	int fd;

	fd = open("copy_fd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("open");
		return (1)
	}


}

