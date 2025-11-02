#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

// Fonction de gestion du signal
void handle_signal(int signal) {
    printf("\nSignal %d reçu, arrêt du programme...\n", signal);
    exit(0);  // Quitter le programme
}

int main() {
    struct sigaction sa;

    // Initialiser la structure sigaction
    memset(&sa, 0, sizeof(sa));  // Assurez-vous que la structure est vide
    sa.sa_handler = handle_signal;  // Définir le gestionnaire de signal
    sigemptyset(&sa.sa_mask);  // Aucune interruption de signaux pendant l'exécution
    sa.sa_flags = 0;  // Aucune option spéciale

    // Configurer sigaction pour SIGINT
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("Erreur lors de la configuration de sigaction");
        return 1;
    }

    printf("Appuyez sur Ctrl+C pour envoyer un signal SIGINT...\n");

    // Boucle infinie, attendant le signal
    while (1) {
        sleep(1);  // Pause pour réduire l'utilisation de la CPU
    }

    return 0;
}
