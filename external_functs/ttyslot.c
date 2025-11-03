#include <stdio.h>
#include <unistd.h>

int main() {
    int slot = ttyslot();
    printf("Session TTY Slot: %d\n", slot);
    return 0;
}
