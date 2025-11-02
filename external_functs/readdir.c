#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *dir = opendir("/tmp");
    struct dirent *entry;

    if (dir) {
        while ((entry = readdir(dir)) != NULL) {
            printf("Entrée : %s\n", entry->d_name);
        }
        closedir(dir);
    } else {
        perror("Erreur lors de l'ouverture du répertoire");
    }
    
    return 0;
}
