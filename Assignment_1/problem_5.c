#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

// Opens the file and returns the fd on success and -1 on failure
int open_file(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if(fd >= 0)
    {
        printf("File opened successfully\n");
        return fd;
    }
    else
    {
        printf("Error opening file: %s\n", strerror(errno));
        return -1;  // Return -1 instead of exit() for better main() handling
    }
}

// Reads up to N bytes from file and prints them (N passed as parameter)
ssize_t read_file(int fd, char buf[], size_t nbytes)
{
    ssize_t bytes_read = read(fd, buf, nbytes);  // Read up to nbytes

    if(bytes_read > 0)
    {
        buf[bytes_read] = '\0';  // Null-terminate for safe printing
        printf("Read %zd bytes: %s\n", bytes_read, buf);
        return bytes_read;
    }
    else if(bytes_read == 0)
    {
        printf("Reached end of file\n");
        return 0;
    }
    else
    {
        printf("Read error: %s\n", strerror(errno));
        return -1;
    }
}

int main()
{
    int fd = -1;
    ssize_t bytes_read = 0;
    int bytes;
    char filename[256];
    char buf[100];  // Fixed-size buffer

    printf("Enter the filename: ");
    scanf("%255s", filename);  // Safe scanf with limit

    printf("Number of bytes to read: ");
    scanf("%d", &bytes);

    if(bytes > sizeof(buf)) {
        printf("Error: Requested bytes (%d) exceed buffer size (%zu)\n", bytes, sizeof(buf));
        return 1;
    }

    fd = open_file(filename);
    if(fd >= 0) {
        bytes_read = read_file(fd, buf, (size_t)bytes);  // Pass exact N bytes
        close(fd);
    }

    return (bytes_read < 0) ? 1 : 0;
}

