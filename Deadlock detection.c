#include <stdio.h>

int deadlock_detect(int no_r, int no_p, int alloc[no_p][no_r], int req[no_p][no_r], int avail[no_r])
{
    int finish[no_p];
    for (int i = 0; i < no_p; i++)finish[i]=0;
    
    for (int i = 0; i < no_p; i++)
    {
        
        for (int j = 0; j < no_p; j++)
        {
            int flag = 0;
            if (finish[j] == 0)
            {
                for (int k = 0; k < no_r; k++)
                {
                    if(req[j][k]>avail[k])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    for(int y=0;y<no_r;y++)
                    {
                        avail[y]+=alloc[j][y];
                    }
                    finish[j]=1;
                    
                }
            }
        }
    }

    for(int i=0;i<no_p;i++)
    {
         
        if(finish[i]==0)
        {
            return 0;
        }
    }
    return 1;
}

void main()
{
    int r,p,i,j,k,y;
    printf("ENTER THE NUMBER OF PROCESSES:");
    scanf("%d",&p);
    printf("ENTER THE NUMBER OF RESOURSES:");
    scanf("%d",&r);

    int alloc[p][r],req[p][r],avail[r];

    printf("ENTER THE ALLOCATION MATRIX:");
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }

    printf("ENTER THE REQEUST MATRIX:");
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            scanf("%d",&req[i][j]);
        }
    }

    printf("ENTER THE AVAILABLE MATRIX:");
     
        for(j=0;j<r;j++)
        {
            scanf("%d",&avail[j]);
        }

        if(deadlock_detect(r,p,alloc,req,avail))
        {
            printf("SAFE STATE!");
        }
        else{
            printf("DEADLOCK DETECTED!");
        }
}
