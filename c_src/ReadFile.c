#include <unistd.h> // For read() and write() syscalls
#include <fcntl.h>  // For open() syscall
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024 // Define BUFFER_SIZE with your desired size

int main() {
    int fd; // File descriptor
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    // Open the file in read-only mode using the open() syscall
    fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read data from the file using the read() syscall
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        // Write the data read from the file to stdout
        if (write(STDOUT_FILENO, buffer, bytes_read) != bytes_read) {
            perror("Error writing to stdout");
            close(fd);
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read == -1) {
        perror("Error reading from file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Close the file descriptor
    close(fd);

    return 0;
}
