#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Fonction de gestion du signal
void handle_signal(int signal) {
    printf("\nSignal %d reçu, arrêt du programme...\n", signal);
    exit(0);  // Quitter le programme
}

int main() {
    // Configuration du gestionnaire de signal pour SIGINT
    if (signal(SIGINT, handle_signal) == SIG_ERR) {
        printf("Erreur lors de la configuration du gestionnaire de signal.\n");
        return 1;
    }

    printf("Appuyez sur Ctrl+C pour envoyer un signal SIGINT...\n");

    // Boucle infinie, attendant le signal
    while (1) {
        // Pause pour réduire l'utilisation de la CPU
        sleep(1);
    }

    return 0;
}
