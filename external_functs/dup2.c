#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = open("fichier.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    int new_fd = dup2(fd, 2); // Rediriger stderr vers fichier.txt

    if (new_fd == -1) {
        perror("Erreur de duplication");
    } else {
        fprintf(stderr, "Ceci est une erreur redirigée vers fichier.txt\n");
    }

    close(fd); // Fermer le descripteur de fichier
    return 0;
}
