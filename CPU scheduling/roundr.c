
#include <stdio.h>

int q[100];
int f = -1, r = -1;

void insert(int process)
{
    if (f == -1)
        f = 0;
    r++;
    q[r] = process;
}

int delete()
{
    int process;
    process = q[f];
f++;
    return process;
}

void main()
{
    int no_p, time = 0,total_tat=0,total_wt=0;
    printf("ENTER THE NUMBER OF PROCESSES:");
    scanf("%d", &no_p);
    int a[no_p][6], t_q, exist[no_p],bt[no_p];
     

    for (int i = 0; i < no_p; i++)
    {
        a[i][0] = i;
    
        printf("ENTER THE ARRIVAL TIME OF PROCESS %d:", i);
        scanf("%d", &a[i][1]);
        printf("ENTER THE BURST TIME OF PROCESS %d:", i);
        scanf("%d", &a[i][2]);
        bt[i]=a[i][2];
        exist[i]=0;
    }
    printf("ENTER THE TIME QUANTUM:");
    scanf("%d", &t_q);

    insert(0);
    exist[0] = 1;

    while (f <= r)
    {
        int p = delete ();

        if (a[p][2] >= t_q)
        {
            a[p][2] -= t_q;
            time += t_q;
        }
        else
        {
            time += a[p][2];
            a[p][2] = 0;
        }

        for (int i = 1; i < no_p; i++)
        {
            if (exist[i] == 0 && a[i][1] <= time)
            {
                insert(i);
                exist[i] = 1;
            }
        }
        if (a[p][2] == 0)
        {
            a[p][3] = time;
            a[p][4] = time - a[p][1];
            a[p][5] = a[p][4] - bt[p];
            total_tat+=a[p][4];
            total_wt+=a[p][5];
        }
        else{
            insert(p);
        }
    } 

    printf("P_NO\tAT\tBT\tCT\tTAT\tWT\n");

    for(int i=0;i<no_p;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",a[i][0],a[i][1],bt[i],a[i][3],a[i][4],a[i][5]);
    }
    printf("AVERAGE TURN AROUND TIME=%f\n",(float)total_tat/no_p);
    printf("AVERAGE WAITING TIME=%f",(float)total_wt/no_p);
}
