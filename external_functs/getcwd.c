#include <stdio.h>
#include <unistd.h>

int main() {
    char cwd[1024];
    
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Répertoire courant : %s\n", cwd);
    } else {
        perror("getcwd() erreur");
    }
    
    return 0;
}
