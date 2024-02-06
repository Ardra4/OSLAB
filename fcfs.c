#include <stdio.h>
int main()
{

    int pid[15];
    int bt[15];
    int at[15];
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter process id of all the processes: ");
    for(int i=0;i<n;i++)
    {
	scanf("%d",&pid[i]);
    }
    printf("Enter arrival time opf all the processes: ");

    for(int i=0;i<n;i++)
    {

        scanf("%d",&at[i]);

    }
    printf("Enter burst time of all the processes: ");

    for(int i=0;i<n;i++)
    {

        scanf("%d",&bt[i]);

    }
   int i,ct[15];
   ct[0]=bt[0];
   for(i=1; i<n; i++)
   {
	
	ct[i]=ct[i-1]+bt[i];
    }

    printf("Proces	AT	 BT	CT	TAT	WT\n");

    float twt=0.0;
    int wt[n];
    float tat= 0.0;
    for(i=0; i<n; i++)
    {

        printf("%d\t", pid[i]);
	printf("%d\t", at[i]);
	printf("%d\t", bt[i]);
	printf("%d\t", ct[i]);
	printf("%d\t", ct[i]-at[i]);
	 printf("%d\t",wt[i]= ct[i]-at[i]-bt[i]);
        printf("\n");
	twt += wt[i];
	tat =wt[i]-bt[i];
	
    }
    float att,awt;
    awt = twt/n;

    att = tat/n;

    printf("Avg. waiting time= %f\n",awt);

    printf("Avg. turnaround time= %f",att);

}
