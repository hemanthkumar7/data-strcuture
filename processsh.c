#include<stdio.h>
int main()
{
   int q[100], bt[100], tt[100],n,i;
   printf("Enter the number of processes\n");
   scanf("%d",&n);
   printf("Enter the burst times of each process\n");
   for(i = 0;i < n;i++)
   {
      
      scanf("%d",&bt[i]);
   }
   tt[0]=0;
   for(i=1;i<n;i++)
   {
      tt[i] = tt[i-1]+bt[i-1];
   }
   printf("Process\t\tBurst time\ttest time\n");
   for(i=0;i<n;i++)
   {
      printf("P%d\t\t%d\t\t%d\n",i,bt[i],tt[i]);
   }
   return 1;
}

