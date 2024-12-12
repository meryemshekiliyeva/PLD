#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#define BUFFER_SIZE 512
int main(int argc, char *argv[]) {
       if (argc != 3) {
        fprintf(stderr, "Usage: %s <source file> <destination file>\n", argv[0]);
        return 1;
    }
    char *source_file = argv[1];
    char *destination_file = argv[2];
    int source_fd = open(source_file, O_RDONLY);
    if (source_fd == -1) {
        perror("Error: Could not open source file");
        return 1;
    }
    int destination_fd = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (destination_fd == -1) {
        perror("Error: Could not open destination file");
        close(source_fd);
        return 1;
    }
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;
    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(destination_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Error: Could not write data to destination file");
            close(source_fd);
            close(destination_fd);
            return 1;
        }
    }
    if (bytes_read == -1) {
        perror("Error: Could not read from source file");
        close(source_fd);
        close(destination_fd);
        return 1;
    }
    close(source_fd);
    close(destination_fd);
    printf("File copied successfully from %s to %s.\n", source_file, destination_file);
    return 0;
}
