#include <stdio.h>
#include <unistd.h>

int main() {
    char *tty = ttyname(STDIN_FILENO); // Obtenir le nom du terminal
    
    if (tty) {
        printf("Nom du terminal : %s\n", tty);
    } else {
        perror("Erreur lors de l'obtention du nom du terminal");
    }
    
    return 0;
}
