#include <stdio.h>
#include <string.h>

int main() {
    int errnum = ENOENT; // Exemple d'erreur : fichier non trouvé
    printf("Message d'erreur : %s\n", strerror(errnum));
    
    return 0;
}
