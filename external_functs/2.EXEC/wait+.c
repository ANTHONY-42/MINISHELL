#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

//	Ces fonctions servent a attendre la fin d'un processus enfant :
//
//	wait()					: attend n'importe quel enfant;
//	waitpid(pid, &status, 0)		: attend un enfant précis;
//	------------------------------------------------------------------------------------
//	wait3(&status, flags, &usage)		: attend n'importe quel enfant	+ statistique;
//	wait4(pid, &status, flags, &usage)	: attend un enfant precit	+ statistique;
//
//	statistique (usage)	=	infos system de l'enfant (temps CPU, memoire consommée...);
//	status			=	recupere les valeur retourner par wait...();
//	WEXITSTATUS(status))	=	recupere la valeur de retour (exit) dans status;
//	flags			=	change le comportement de wait;
//			- 0 		attend que l'enfant meure;
//			- WNOHANG	continue meme si l'enfant n'est pas mort;

int main()
{
	pid_t	pid;
	int	status;
	struct rusage usage;


	//	WAIT()
	pid = fork();
	if (pid == 0)
		exit(1);
	wait(&status);
	printf("wait(status)		= %d\n", WEXITSTATUS(status));

	//	WAITPID()
	pid = fork();
	if (pid == 0)
		exit (2);
	waitpid(pid, &status, 0);
	printf("waitpid(status)		= %d\n", WEXITSTATUS(status));

	//	WAIT3
	pid = fork();
	if (pid == 0)
		exit (3);
	wait3(&status, 0, &usage);
	printf("wait3(status)		= %d\n", WEXITSTATUS(status));

	//	WAIT4
	pid = fork();
	if (pid == 0)
		exit (4);
	wait4(pid, &status, 0, &usage);
	printf("wait4(status)		= %d\n", WEXITSTATUS(status));

	return (0);
}
