#include<stdio.h>
#include <unistd.h>
int main()
{
	int a[]={1,2,3,4,5};
	int pid=fork();
	int sum=0;
	if(pid==0)
	{
		for(int i=0;i<5;i++)
		{
			if(a[i]%2==0)
			{
				sum+=a[i];
			}
		}
		printf("Child Part\n");
		printf("Even Sum is: %d and Child Parent ID is: %d\n",sum,getpid());
		printf("Parent Process ID:%d\n",getppid());
	}
	else
	{
		for(int i=0;i<5;i++)
		{
			if(a[i]%2!=0)
			{
				sum+=a[i];
			}
		}
		sleep(1);
		printf("Parent Part\n");
		printf("Odd Sum is: %d and Parent Process ID is: %d\n",sum,getpid());
	}
	return 0;
		
}
