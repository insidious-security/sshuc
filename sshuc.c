#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    char command[256];
    const char *username = "<username>";
    if (argc != 2) {
        fprintf(stderr, "usage: %s <hostname>\n", argv[0]);
        return 1;
    }
    snprintf(command, sizeof(command), "ssh %s@%s", username, argv[1]);
    printf("Executing command: %s\n", command);
    int result = system(command);
    if (result == -1) {
        perror("system");
        return 1;
    }
    return 0;
}
