#include <stdio.h>
#include <termcap.h>

int main() {
    char *position_cmd = tgoto(tgetstr("cm", NULL), 10, 10);
    printf("Move cursor command: %s\n", position_cmd);
    return 0;
}
