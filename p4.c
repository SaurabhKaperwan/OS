//Zombie process
#include<stdio.h>
#include <unistd.h>
int main()
{
	int pid=fork();
	if(pid==0)
	{
		printf("Child Part\n");
		printf("Child Process ID is: %d\n",getpid());
		printf("Parent Process ID:%d\n",getppid());
	}
	else
	{
		sleep(5);
		printf("Parent Part\n");
		printf("Parent Process ID is: %d\n",getpid());
	}
	return 0;
		
}
