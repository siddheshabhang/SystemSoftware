#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    int fd;
    char *fifo = "atm_fifo";
    char buffer[100];

    // Open FIFO for reading
    fd = open(fifo, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    read(fd, buffer, sizeof(buffer));
    printf("User received: %s\n", buffer);

    close(fd);
    return 0;
}
