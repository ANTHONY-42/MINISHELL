#include <stdio.h>
#include <unistd.h>

int main() {
    if (unlink("exemple.txt") == 0) {
        printf("Fichier supprimé avec succès.\n");
    } else {
        perror("Erreur lors de la suppression du fichier");
    }
    
    return 0;
}
