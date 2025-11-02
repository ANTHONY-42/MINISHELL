#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat info;

    if (lstat("lien_symbolique", &info) == 0) {
        printf("Taille du lien symbolique : %ld octets\n", info.st_size);
    } else {
        perror("Erreur lors de l'obtention des informations sur le lien symbolique");
    }
    
    return 0;
}
