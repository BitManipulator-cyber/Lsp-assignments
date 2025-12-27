// Question 1
// Accept filename from user and open using open()
// Print: Success message + returned file descriptor
// Handle errors using perror()

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// Opens file and returns its file descriptor.
// Caller is responsible for error handling.
int open_file(const char *filename)
{
    return open(filename, O_CREAT | O_RDONLY, 0644);
}

int main(void)
{
    char filename[256];

    printf("Enter file name: ");
    scanf("%255s", filename);

    int fd = open_file(filename);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    printf("File opened successfully with fd: %d\n", fd);
    close(fd);
}
