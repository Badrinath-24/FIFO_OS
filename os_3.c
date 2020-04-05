#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x[20],burst_time[20], su[20], wait_time[20],ta_time[20],i, k, n, temp;
	float waitavg, total_around_timeavg;
	printf("Enter the number of PROCESS  in the queue : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		x[i] = i;
		printf("Enter the Burst Time for process  %d : ", i);
		scanf("%d",&burst_time[i]);
		printf("teacher/student process (0/1) ? : ");
		scanf("%d", &su[i]);
	}
	
	for(i=0;i<n;i++)
	{
		for(k=i+1;k<n;k++)
		{
			if(su[i] > su[k])
			{
				temp=x[i];
				x[i]=x[k];
				x[k]=temp;
				
				temp=burst_time[i];
				burst_time[i]=burst_time[k];
				burst_time[k]=temp;
				
				temp=su[i];
				su[i]=su[k];
				su[k]=temp;
			}
		}
	}
	waitavg = wait_time[0] = 0;
	total_around_timeavg = ta_time[0] = burst_time[0];
	for(i=1;i<n;i++)
	{
		wait_time[i] = wait_time[i-1] + burst_time[i-1];
		ta_time[i] = ta_time[i-1] + burst_time[i];
		waitavg = waitavg + wait_time[i];
		total_around_timeavg = total_around_timeavg + ta_time[i];
	}
	printf("\nPROCESS\t\t TEACHER/STUDENT PROCESS  \tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
	
	for(i=0;i<n;i++)
	{
		printf("\n%d \t\t %d \t\t %d \t\t %d \t\t\t %d ",x[i],su[i],burst_time[i],wait_time[i],ta_time[i]);
	}

	printf("\nAverage Waiting Time is --- %f",waitavg/n);
	printf("\nAverage Turnaround Time is --- %f",total_around_timeavg/n);

	return 0;
}

