#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int fd = open("exemple.txt", O_RDONLY); // Ouvrir le fichier en lecture
    struct stat info;

    if (fstat(fd, &info) == 0) {
        printf("Taille du fichier via fstat : %ld octets\n", info.st_size);
    } else {
        perror("Erreur lors de l'obtention des informations avec fstat");
    }

    close(fd); // Fermer le descripteur de fichier
    return 0;
}
