#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    
    if (pid == 0) {
        // Processus enfant
        printf("Enfant (PID: %d) dormant...\n", getpid());
        sleep(5);
        exit(0);
    } else {
        // Processus parent
        printf("Envoyant SIGKILL au processus enfant...\n");
        kill(pid, SIGKILL); // Envoie le signal SIGKILL à l'enfant
        wait(NULL); // Attendre que l'enfant se termine
    }
    
    return 0;
}
