#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "../get_next_line.h"


//void test_len_line(int cases, int fd);

int main()
{
	int fd;
	char *result;

	fd = open("readme.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("bad file");
		return (0);
	}
	
	//result = get_next_line(fd);
	for(int i = 0; i < 2; ++i )
	{
		result = get_next_line(fd);
		printf("\n**************");
		printf("\n<<<<%s>>>>\n",result);
		printf("-------------------------------------\n");
		free(result);
	}
	
	//free(result);
	
	close(fd);
	//printf("\nClosing the porgram....\n");
	return (0);
}

// void test_len_line(int cases, int fd)
// {
	
// 	for(int i = 0; i < cases; i++)
// 	{

// 		result = get_next_line(fd);
// 		//printf("%s", result);
// 		free(result);
// 	}
// }