#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    const char *username = "<username>";   // Replace with actual username
    int port = 22;                         // SSH port

    if (argc != 2) {
        fprintf(stderr, "usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    //-[Calculate required buffer size]-// 
    int len = snprintf(NULL, 0, "ssh -p %d %s@%s", port, username, argv[1]) + 1;
    char *command = malloc(len);

    if (command == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    //-[Construct command string]-//
    snprintf(command, len, "ssh -p %d %s@%s", port, username, argv[1]);
    printf("[+]Executing command: %s\n", command);

    //-[Execute SSH command]-//
    int result = system(command);
    if (result == -1) {
        perror("system");
        free(command);
        return 1;
    }

    //-[Clean up and free mem]-//
    free(command);
    return 0;
}

