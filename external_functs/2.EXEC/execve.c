#include <unistd.h>

//	Execve(av[1], &av[1], envp) tue et remplace le program actuel par un autre;
//	Parametre de fonction :
//	1 	=	chemin du program a executer (/bin/ls)
//	2	=	tableau des arguments passé au program (./a.out "bin/ls" "-l" "NULL")
//	3	=	environnement systeme (PATH, HOME, etc...)

int main(int ac, char **av, char **envp)
{
	if (ac < 2)
		return (perror("Error: arg"), 1);

	execve(av[1], &av[1], envp);
	perror("Error: execve");
	return (1);
}
