#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    if (argc < 1) {
        perror("fatal: No arguments provided.");
        return 1;
    }
    printf("Just use which until this program builds itself!")
    return 0;
}
