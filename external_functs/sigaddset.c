#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum) {
    printf("Signal %d reçu !\n", signum);
}

int main() {
    // Créer un ensemble de signaux
    sigset_t set;

    // Initialiser l'ensemble de signaux
    sigemptyset(&set);

    // Ajouter le signal SIGINT à l'ensemble
    sigaddset(&set, SIGINT);

    // Installer un gestionnaire pour SIGINT
    signal(SIGINT, handler);

    // Bloquer le signal SIGINT
    sigprocmask(SIG_BLOCK, &set, NULL);

    printf("Le signal SIGINT est bloqué. Appuyez sur Ctrl+C pour essayer de l'envoyer.\n");
    
    // Attendre une durée (ex. 10 secondes)
    sleep(10);

    // Débloquer SIGINT
    sigprocmask(SIG_UNBLOCK, &set, NULL);
    printf("Le signal SIGINT est maintenant débloqué.\n");

    // Attendre encore
    sleep(10);

    return 0;
}
