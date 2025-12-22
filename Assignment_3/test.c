#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

int main()
{
	DIR *dp = NULL;
	struct dirent *ptr = NULL;
	int count = 0;

	dp = opendir("Test");

	while(ptr = readdir(dp))
	{
		printf("Files %hu\n", ptr -> d_reclen);
		count ++;
	}
	printf("Count: %d\n", count);

	closedir(dp);
	return 0;
}
