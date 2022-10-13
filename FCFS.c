#include <stdio.h>
#include<stdlib.h>
struct  process_struct
{
	int pid;
	int at;
	int bt;
	int ct,wt,tat,rt,st;
}ps[100];

int cmpId(const void * a,const void *b)
{
	int x=((struct process_struct*) a)->pid;
	int y=((struct process_struct*) b)->pid;
	if(x<y)
		return -1;
	else if(x>=y)
		return 1;

}

int cmp(const void * a,const void * b)
{
	int x=((struct process_struct *)a)->at;
	int y=((struct process_struct *)b)->at;

	if(x<y)
		return -1;
	else if(x>=y)
		return 1;
}

int findMax(int a,int b)
{
	return a>b ? a:b;
}

int main()
{
	int n;
	printf("Enter no of process:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Enter Process %d Arrival Time:\n",i);
		scanf("%d",&ps[i].at);

		printf("Enter Process %d Burst Time:\n",i);
		scanf("%d",&ps[i].bt);

		ps[i].pid=i;	
	}

	qsort((void*)ps,n,sizeof(ps[0]),cmp);

	float sum_tat=0,sum_wt=0,sum_rt=0,total_idle_time=0;

	for (int i = 0; i < n; ++i)
	{
		if(i==0)
			ps[i].st=ps[i].at;
		else
			ps[i].st=findMax(ps[i].at,ps[i-1].ct);

		ps[i].ct=ps[i].st+ps[i].bt;
		ps[i].tat=ps[i].ct-ps[i].at;
		ps[i].wt=ps[i].tat-ps[i].bt;
		ps[i].rt=ps[i].wt;

		sum_rt+=ps[i].rt;
		sum_wt+=ps[i].wt;
		sum_tat+=ps[i].tat;
		total_idle_time += (i==0)? 0 : (ps[i].st-ps[i-1].ct);
	}

	int length_cycle=ps[n-1].ct-ps[0].st;
	float cpu_utilization;

	qsort((void*)ps,n,sizeof(ps[0]),cmpId);

	printf("\nProcess No.\tAT\tCPU Burst Time\tC\tTAT\tWT\tRT\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%d\t\t%d\t%d\t\t%d\t%d\t%d\t%d\n",ps[i].pid,ps[i].at,ps[i].bt,ps[i].ct,ps[i].tat,ps[i].wt,ps[i].rt);

	}
	cpu_utilization=(float)(length_cycle-total_idle_time)/length_cycle;	
	printf("\nAverage Turn Around time= %f ",sum_tat/n);
    printf("\nAverage Waiting Time= %f ",sum_wt/n);
    printf("\nAverage Response Time= %f ",sum_rt/n);
    printf("\nThroughput= %f",n/(float)length_cycle);    
    printf("\nCPU Utilization(Percentage)= %f",cpu_utilization*100);

	return 0;
}
