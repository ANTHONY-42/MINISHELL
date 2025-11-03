#include <stdio.h>
#include <termcap.h>

int main() {
    char buf[2048];
    int result = tgetent(buf, "xterm");
    if (result <= 0) {
        printf("Could not access termcap database.\n");
        return 1;
    }
    printf("Termcap entry for 'xterm' loaded successfully.\n");
    return 0;
}
