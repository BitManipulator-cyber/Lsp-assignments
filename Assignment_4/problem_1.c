/**
 * Author : Aaditya Jagtap
 * Problem statement: Write a program that copies the contents of one file to another 
 * Input : Source filename and destination filename
 * Output: Destination file containing exact copy of source file
 */

/* Header files */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * handle_fd() - handles the error for file descriptor
 *
 * @fd : accepts the file descriptor
 *  
 * handle_fd() checks the value of file descriptor and prints the message on 
 * STD_OUT for it's current value
 *
 * Return:
 * Sucess  - prints success message
 * Failure - prints error message using perror()
 */
void handle_fd(int fd)
{
	if(fd < 0)
	{
		perror("Error opening file\n");
	}
	else
	{
		printf("File opened succesfully\n");
	}
}

/**
 * copy_file_content() - copies the content of one file to another
 *
 * @source_fname: stores source filename
 * @dest_fname  : stores destination filename
 *
 * copy_file_content() function open source file then reads the raw bytes from the source file
 * and then stores these bytes into local buffer. 
 *
 * Then it opens the destination file in *read and append* and *creates* the file if file not present already
 * with suitable permission eg.(0664). Then it calculates the length of buffer array and writes exactly the 
 * required bytes into the destination file
 *
 * Return:
 * Copied content from source file to destination file
 */
void copy_file_content(char source_fname[], char dest_fname[])
{
	int  fd1 = 0, fd2 = 0, iRet = 0;
	char buf[1024];
	int  buf_size = 0;

	fd1 = open(source_fname, O_RDONLY);
	handle_fd(fd1);

	iRet = read(fd1, buf, sizeof(buf));
	if(iRet < 0) perror("Failed to read\n");
	else 	     printf("Read successful\n");

	fd2 = open(dest_fname, O_WRONLY | O_APPEND | O_CREAT, 0644);
	handle_fd(fd2);
	buf_size = strlen(buf);
	
	write(fd2, buf, buf_size);
	if(iRet < 0) perror("Failed to read\n");
	else 	     printf("Write successful\n");

	close(fd1);
	close(fd2);
}

/* Entry point function */
int main(void)
{
	char source_fname[256];
	char dest_fname[256];

	printf("Enter filename: ");
	scanf("%255s", source_fname);

	printf("Enter destination filename: ");
	scanf("%255s", dest_fname);

	copy_file_content(source_fname, dest_fname);

	return 0;
}
