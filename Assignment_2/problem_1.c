/**
 * Author: Aaditya Jagtap
 * Problem Statement: Accept and print full content of file on console
 * and show total read bytes
 * Input : Filename
 * Output: Number of bytes read and file content on console
 */

/* Header files */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * print_and_count_bytes - prints the file content and total number of bytes
 * on the console
 *
 * @filename: stores the filename 
 *
 * This function opens the file in read mode (O_RDONLY) and reads the raw bytes from 
 * the file and then it prints it onto the console along with the total number of bytes
 * that were read from the file
 *
 * Return:
 * void (file content + total number of bytes)
 */
void print_and_count_bytes(char filename[])
{
	int  fd = 0, iRet = 0;
	char buf[1024];

	fd = open(filename, O_RDONLY);
	if(fd < 0) perror("Failed to open the file\n");
	else       printf("Succesfully opened the file\n");

	iRet = read(fd, buf, sizeof(buf));
	if(iRet < 0) 
		perror("Failed to read the file\n");
	else         
		printf("File content: %s\n", buf);
		printf("Total bytes read: %d\n", iRet);

	close(fd);
}

/* Entry point function */
int main(void)
{
	char filename[256];

	printf("Enter filename:\n");
	scanf("%s", filename);
	
	print_and_count_bytes(filename);

	return 0;
}
