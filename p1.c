#include<stdio.h>
#include <unistd.h>
int main()
{
	fork();
	printf("ID is :%d ",getpid());
}
