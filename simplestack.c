#include<stdio.h>
#include<stdlib.h>
#define max_size 5
int stack[100],top=-1;
void push();
void pop();
void display();
void main()
{
 int c;
 while(1)
 {
 printf("1.Push\n2.pop\n3.Display\n4.Exit\n");
 printf("Enter the choice:\n ");
 scanf("%d",&c);
 switch(c)
 {
  case 1:push();
         break;
case 2:pop();
         break;
case 3:display();
         break;
  case 4:exit(0);
default:printf("invalid choice");
}
}
}
void push()
{ int ele;
   if(top==max_size-1)
   {printf("Stack is overflow");}
   else
   {printf("Enter the value");
   scanf("%d",&ele);
   top=top+1;
   stack[top]=ele;}
}
void pop()
{
  if(top==-1)
  {printf("Stack is underflow");}
  else
  {printf("Deleted element =%d\n",stack[top]);
  top=top-1;}
  }
 void display()
 {int i;
 if(top==-1)
 {printf("stack is underflow");}
 else
 for(i=top;i>=0;i--)
 {printf("%d\n",stack[i]);}
}

