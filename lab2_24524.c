#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main() {

    int fd = open("output.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
    if (fd < 0) {
        perror("File open failed");
        exit(1);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        char child_msg[] = "Child process writing to file\n";
        write(fd, child_msg, strlen(child_msg));
        close(fd);
        exit(0);
    } else {
        wait(NULL);
        char parent_msg[] = "Parent process writing to file\n";
        write(fd, parent_msg, strlen(parent_msg));
        close(fd);
    }

    return 0;
}