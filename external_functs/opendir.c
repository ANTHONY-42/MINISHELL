#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *dir = opendir("/tmp");
    
    if (dir) {
        printf("Répertoire ouvert avec succès.\n");
        closedir(dir); // Ne pas oublier de fermer le répertoire
    } else {
        perror("Erreur lors de l'ouverture du répertoire");
    }
    
    return 0;
}
