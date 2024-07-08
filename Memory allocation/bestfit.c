#include <stdio.h>
void implimentBestFit(int blockSize[], int blocks, int processSize[], int proccesses)
{
int allocation[proccesses];
int occupied[blocks];
int frag[proccesses];
for(int i = 0; i < proccesses; i++)
{
allocation[i] = -1;
}
for(int i = 0; i < blocks; i++)
{
occupied[i] = 0;
}
for (int i = 0; i < proccesses; i++)
{
int indexPlaced = -1;
for (int j = 0; j < blocks; j++) 
{ 
if (blockSize[j] >= processSize[i] && !occupied[j])
{
if (indexPlaced == -1)
indexPlaced = j;
else if (blockSize[j] < blockSize[indexPlaced])
indexPlaced = j;
}
frag[i]=blockSize[indexPlaced]-processSize[i];
}
if (indexPlaced != -1)
{
allocation[i] = indexPlaced;
occupied[indexPlaced] = 1;
}
}
printf("\nProcess No.\tProcess Size\t\tBlock no.\t\tFragment\n");
for (int i = 0; i < proccesses; i++)
{
printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
if (allocation[i] != -1)
printf("%d \t\t\t %d\n",allocation[i] + 1,frag[i]);
else
printf("Not Allocated\tNot Allocated\n");
}
}
int main()
{
int bno,pno,i;
 printf("Enter no. of blocks: ");
 scanf("%d",&bno);
 printf("\nEnter no. of processes: ");
 scanf("%d",&pno);
 int bsize[bno],psize[pno];
 printf("\nEnter size of each block: ");
 for(i=0;i<bno;i++)
 scanf("%d",&bsize[i]);
 printf("Enter size of each process: ");
 for(i=0;i<pno;i++)
 scanf("%d",&psize[i]);
implimentBestFit(bsize, bno, psize, pno);
return 0 ;
}
