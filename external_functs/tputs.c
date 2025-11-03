#include <stdio.h>
#include <termcap.h>
#include <unistd.h>

int main() {
    char *clear_cmd = tgetstr("cl", NULL);
    tputs(clear_cmd, 1, putchar);
    printf("Screen cleared using tputs.\n");
    return 0;
}
