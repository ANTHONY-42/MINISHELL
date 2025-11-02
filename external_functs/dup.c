#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = 1; // Descripteur pour stdout
    int new_fd = dup(fd); // Dupliquer stdout
    
    if (new_fd == -1) {
        perror("Erreur de duplication");
    } else {
        printf("Duplication réussie : nouveau fd = %d\n", new_fd);
    }
    
    return 0;
}
