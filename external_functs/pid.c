#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

// Ce programme montre comment fork() gere les PID lors de la creation d'un nouveau processus.
//
// PARENT	-> PID = 1234	|	pid (= fork) = 4321 (PID enfant);
// ENFANT	-> PID = 4321	|	pid (= fork) = 0
// FORK		: renvoie 0 a l'enfant pour qu'on sache qui est l’enfant dans le code.

int	main()
{
	pid_t	pid;
	
	printf("APRES FORK\n");
	pid = fork();

	if (pid == -1)
	{
		perror("Error : fork");
		return (1);
	}
	if (pid == 0)
	{
		printf("ENFANT : | PID = %d | pid (= fork) = %d |\n", getpid(), pid);
	}
	else
	{
		printf("PARENT : | PID = %d | pid (= fork) = %d |\n", getpid(), pid);
		wait(NULL);
	}
	return (0);
}
