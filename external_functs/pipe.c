#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd); // Créer un tube

    if (fork() == 0) {
        // Processus enfant
        close(fd[1]); // Fermer le descripteur d'écriture
        char buffer[100];
        read(fd[0], buffer, sizeof(buffer)); // Lire depuis le tube
        printf("Enfant a reçu : %s\n", buffer);
        close(fd[0]);
    } else {
        // Processus parent
        close(fd[0]); // Fermer le descripteur de lecture
        write(fd[1], "Bonjour, enfant !", 17); // Écrire dans le tube
        close(fd[1]);
    }
    
    return 0;
}
