#include <stdio.h>
#include <unistd.h>
#include <termios.h>

int main() {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);  // Get current terminal attributes
    newt = oldt;
    newt.c_lflag &= ~ICANON;         // Set non-canonical mode
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    printf("Terminal set to non-canonical mode.\n");
    // Rétablir les paramètres d'origine
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return 0;
}
