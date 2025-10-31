#include "minishell.h"

void	test_access()
{
    //F_OK : Vérifie si le fichier existe.
    //R_OK : Vérifie si le fichier est lisible.
    //W_OK : Vérifie si le fichier est modifiable.
    //X_OK : Vérifie si le fichier est exécutable.
    if (access("./minishell", X_OK) == 0)
	    ft_printf("Exists\n");
    else
	    ft_printf("Do not exists\n");
}

void	test_fork()
{
	pid_t pid = fork();

	if (pid < 0) {
		// Erreur lors de la création du processus
		perror("Erreur de fork");
	} else if (pid == 0) {
		// Code exécuté par le processus enfant
		printf("Je suis le processus enfant avec PID %d.\n", getpid());
	} else {
	        // Code exécuté par le processus parent
		printf("Je suis le processus parent avec PID %d. Mon enfant a PID %d.\n", getpid(), pid);
	}
	return 0;
}

void	test_wait()
{
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork(); // Crée un enfant dans chaque itération

        if (pid < 0) {
            perror("Erreur de fork"); // Gestion d'erreur
            return 1;
        } else if (pid == 0) {
            // Code exécuté par le processus enfant
            printf("Enfant %d : Je travaille \n", i + 1);
            sleep(1); // Simule un travail
            printf("Enfant %d : Je termine.\n", i + 1);
            return ;//i + 1; // Retourne le numéro de l'enfant comme code de sortie
        }
    }

    // Code exécuté par le processus parent
    for (int i = 0; i < 3; i++) {
        int status;
        wait(&status); // Attend la terminaison de chaque enfant
        if (WIFEXITED(status)) { // Vérifie si l'enfant s'est terminé normalement
            printf("Parent : Un enfant a terminé avec le statut %d.\n", WEXITSTATUS(status)); // Affiche le code de sortie
        }
    }
}

void	test_waitpid()
{
	pid_t pid = fork(); // Crée un processus enfant

    if (pid < 0) {
        perror("Erreur de fork"); // Gestion d'erreur
        return 1;
    } else if (pid == 0) {
        // Code exécuté par le processus enfant
        printf("Enfant : Je fais mon travail.\n");
        sleep(2); // Simule un travail
        return ;//42; // Retourne un code de sortie personnalisé
    } else {
        // Code exécuté par le processus parent
        int status;
        waitpid(pid, &status, 0); // Attend la terminaison de cet enfant spécifique

        // Vérifie si l'enfant s'est terminé normalement
        if (WIFEXITED(status)) {
            printf("Parent : Mon enfant a terminé avec le code %d.\n", WEXITSTATUS(status)); // Affiche le code de sortie
        }
    }
}
