//Orphan process
#include<stdio.h>
#include <unistd.h>
int main()
{
	int pid=fork();
	if(pid==0)
	{
		sleep(5);
		printf("Child Part\n");
		printf("Child Process ID is: %d\n",getpid());
		printf("Parent Process ID:%d\n",getppid());
	}
	else
	{
		printf("Parent Part\n");		
		printf("Parent Process ID is: %d\n",getpid());
	}
	return 0;
		
}
