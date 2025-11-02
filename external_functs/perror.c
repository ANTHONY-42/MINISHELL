#include <stdio.h>
#include <errno.h>

int main() {
    FILE *file = fopen("fichier_inexistant.txt", "r");

    if (!file) {
        perror("Erreur lors de l'ouverture du fichier");
    }
    
    return 0;
}
