/**
 * Author: Aaditya Jagtap
 * Problem Statement: Write the user input string to user specified file
 * Input : Filename, string
 * Output: Bytes written to the file
 */

/* Header files */
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

/**
 * write_to_file - writes user input buffer to the user specified file
 *
 * @filename: stores the filename
 * @buf     : local buffer
 *
 * This function opens the file in *write + append* mode and writes the 
 * user input content for eg. "Hello, World!" to the user specified file
 * eg. Demo.txt 
 *
 * Return:
 * void (content written to the file)
 */
void write_to_file(char filename[], char buf[])
{
	int fd = 0, iRet = 0;
	
	/* Open the file */
	fd = open(filename, O_WRONLY | O_APPEND);
	if(fd < 0) perror("Failed to open the file\n");
	else       printf("File opened succesfully\n");

	/* Write to the file */
	iRet = write(fd, buf, strlen(buf));
	if(iRet < 0) perror("Failed to write to file\n");
	else         printf("Succesfully wrote to the file\n");

	close(fd);

}

/* Entry point function */
int main(void)
{
	char filename[256];
	char buffer[1024];

	printf("Enter the filename:\n");
	scanf("%s", filename);

	printf("Enter the string:\n");
	scanf("%s", buffer);

	write_to_file(filename, buffer);

	return 0;
}
