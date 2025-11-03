#include <stdio.h>
#include <stdlib.h>

int main() {
    char *term = getenv("TERM");
    if (term) {
        printf("TERM variable: %s\n", term);
    } else {
        printf("TERM variable is not set.\n");
    }
    return 0;
}
