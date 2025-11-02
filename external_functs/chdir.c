#include <stdio.h>
#include <unistd.h>

int main() {
    if (chdir("/tmp") == 0) {
        printf("Répertoire de travail changé avec succès à /tmp.\n");
    } else {
        perror("Erreur lors du changement de répertoire");
    }
    
    return 0;
}
