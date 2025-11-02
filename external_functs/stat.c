#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat info;

    if (stat("exemple.txt", &info) == 0) {
        printf("Taille du fichier : %ld octets\n", info.st_size);
    } else {
        perror("Erreur lors de l'obtention des informations sur le fichier");
    }
    
    return 0;
}
