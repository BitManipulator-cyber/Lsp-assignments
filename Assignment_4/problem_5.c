/**
 * Author: Aaditya Jagtap
 * Problem Statement: Display the contents of file in reverse order
 * Input: Filename
 * Output: File content printed in reverse
 */

/* Header files */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * reverse_file_content() - reverse the content of file and displays on STD_OUT
 *
 * @filename: stores filename
 *
 * This function opens the file and reads the bytes from the file and returns the 
 * bytes of the file but in reversed order
 * 
 * Example:
 * 	Hello World! ----> !dlorW olleH
 *
 * Return:
 * File content but in reveresed order
 */
void reverse_file_content(char filename[])
{
	int  fd = 0, iRet = 0;
	char buf[1024];

	fd = open(filename, O_RDONLY);
	if(fd < 0) perror("Failed to open file\n");
	else       printf("Succesfully opened the file\n");

	iRet = read(fd, buf, sizeof(buf));
	if(iRet < 0) perror("Failed to read from the file\n");
	else         printf("Read succesful\n");
	
	/* Printing the characters in reverse order */
	for(int i = strlen(buf); i >= 0; i--)
	{
		printf("%c", buf[i]);
	}

	close(fd);
}

/* Entry point function */
int main(void)
{
	char filename[256];

	printf("Enter filename to reverse: \n");
	scanf ("%255s", filename);

	reverse_file_content(filename);

	return 0;
}
