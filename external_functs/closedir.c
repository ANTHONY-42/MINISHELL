#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *dir = opendir("/tmp");

    if (dir) {
        printf("Répertoire ouvert.\n");
        closedir(dir); // Fermer le répertoire
        printf("Répertoire fermé avec succès.\n");
    } else {
        perror("Erreur lors de l'ouverture du répertoire");
    }
    
    return 0;
}
