#include <stdio.h>
void implementWorstFit(int blockSize[], int blocks, int processSize[], int processes) {
 int allocation[processes];
 int occupied[blocks];
 for(int i = 0; i < processes; i++) {
 allocation[i] = -1;
 }
 
 for(int i = 0; i < blocks; i++) {
 occupied[i] = 0;
 }
 for (int i = 0; i < processes; i++) {
 int indexPlaced = -1;
 for(int j = 0; j < blocks; j++) {
 if(blockSize[j] >= processSize[i] && !occupied[j]) {
 if (indexPlaced == -1)
 indexPlaced = j;
 else if (blockSize[indexPlaced] < blockSize[j])
 indexPlaced = j;
 }
 }
 if (indexPlaced != -1) {
 allocation[i] = indexPlaced;
 occupied[indexPlaced] = 1;
blockSize[indexPlaced] -= processSize[i];
}
 }
 printf("\nProcess No.\tProcess Size\tBlock no.\tFragmentation\n");
 for (int i = 0; i < processes; i++) {
 printf("%d\t\t\t%d\t\t\t", i + 1, processSize[i]);
 if (allocation[i] != -1)
 printf("%d\t\t%d\n", allocation[i] + 1,blockSize[i]);
 else
 printf("Not Allocated\n");
 }
}
int main() {
 int m, n;
 printf("Enter the number of blocks: ");
 scanf("%d", &m);
 int blockSize[m];
 printf("Enter the block sizes: ");
 for (int i = 0; i < m; i++) {
 scanf("%d", &blockSize[i]);
 }
 printf("Enter the number of processes: ");
 scanf("%d", &n);
 int processSize[n];
 printf("Enter the process sizes: ");
 for (int i = 0; i < n; i++) {
 scanf("%d", &processSize[i]);
 }implementWorstFit(blockSize,m,processSize,n);
 return 0;
}
