#include <stdio.h>
#include <termcap.h>

int main() {
    int has_color = tgetflag("Co");
    printf("Supports colors: %d\n", has_color);
    return 0;
}
