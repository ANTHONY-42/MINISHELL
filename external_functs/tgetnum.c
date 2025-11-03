#include <stdio.h>
#include <termcap.h>

int main() {
    int num_colors = tgetnum("colors");
    printf("Number of colors supported: %d\n", num_colors);
    return 0;
}
