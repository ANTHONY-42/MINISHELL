#include <stdio.h>
#include <termcap.h>

int main() {
    char *clear_cmd = tgetstr("cl", NULL);
    if (clear_cmd) {
        printf("Clear screen command: %s\n", clear_cmd);
    } else {
        printf("Can't find clear screen command.\n");
    }
    return 0;
}
