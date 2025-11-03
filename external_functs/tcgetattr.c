#include <stdio.h>
#include <unistd.h>
#include <termios.h>

int main() {
    struct termios attr;
    tcgetattr(STDIN_FILENO, &attr);
    printf("Terminal attributes fetched successfully.\n");
    return 0;
}
