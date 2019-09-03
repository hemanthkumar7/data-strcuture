#include<stdio.h>
#define size 10
void insert(int q[], int *r,int *f, int item)
{
   if((*f == *r+1)||(*f == 0 && *r ==  size-1))
   {
      printf("Queue is full\n");
      return;
   }
   if(*f == -1)
   *f = 0;
   *r = (*r+1)%size;
   q[*r] = item;
}
int delete(int q[], int *f, int *r)
{
   int item;
   if(*f == -1)
   {
      printf("Queue is empty\n");
      return -9999;
   }
   else
   {
      item = q[*f];
   }
   if(*f == *r)
   {
      *f = -1;
      *r = -1;
   }
   else
   *f = (*f+1)%size;
   return item;
}
void display(int q[], int *r, int *f)
{
   int i;
   if(*f == -1)
   printf("Queue is empty\n");
   else
   {
      printf("Queue elements are\n");
      for(i = *f;i!=*r;i=(i+1)%size)
	 printf("%d \n",q[i]);
      printf("%d \n",q[i]);
   }
}
int main()
{
   int q[size],j,r,f,i,n,k=1;
   printf("Enter the number of elements:");
   scanf("%d",&n);
   printf("\nEnter the elements of the queue\n");
   for(i = 0;i<n;i++)
   {
     scanf("%d",&q[i]);
   }
   f = 0;
   r = n-1;
   while(k!=0)
   {
     printf("\nEnter 0 to exit \nEnter 1 to insert \nEnter 2 to delete \nEnter 3 to display\n");
     scanf("%d",&k);
     switch(k)
     {
       case 0:printf("exit\n");
                break;      
       case 1: printf("Enter the number to be inserted \n");
	       scanf("%d",&j);
	       insert(q,&r,&f,j);
	       break;
       case 2: j = delete(q,&f,&r);
	       if(j != -9999)
	       printf("Deleted element is %d",j);
	       break;
       case 3: display(q,&r,&f);
	       break;
       default:printf("Invalid option\n");
     }
   }
   return 1;
}

