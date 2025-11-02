#include <stdio.h>
#include <unistd.h>

int main() {
    if (isatty(STDIN_FILENO)) {
        printf("L'entrée standard est un terminal.\n");
    } else {
        printf("L'entrée standard n'est pas un terminal.\n");
    }
    
    return 0;
}
