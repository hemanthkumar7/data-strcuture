#include<stdlib.h>
#include<stdio.h>
struct node
{
int data;
struct node *next;
};
typedef struct node *NODE;
NODE getnode()
{
NODE p;
p=(NODE)malloc(sizeof(struct node));
if(p!=NULL)
return p;
else
{
printf("Memory could not be allocated\n");
exit(0);
}
}
NODE insertfront (int item,NODE head)
{
NODE p = getnode();
p->data=item;
p->next=head;
head =p;
return head;
}

void insertend(NODE head,int item)
{
NODE p,q;
q = getnode();
q->data = item;
p = head;
while(p->next!=NULL)
{
p = p->next;
}
p->next = q;
q->next = NULL;
}

NODE insertpos(NODE head,int item,int pos)
{
NODE curr,prev = NULL,newn;
int count =1;
newn =getnode();
newn->data= item;
newn->next=NULL;
if(head==NULL)
{
    if(pos==1)
    return newn;
    else
    {
    printf("INVALID POSITION\n");
    return head;
    }
}
else if(pos ==1)
{
    newn->next = head;
    head =newn;
return head;
}
else
{
    curr = head;
    while(curr!=NULL && count!=pos)
        {
            prev= curr;
            curr = curr->next;
            count++;
        }
    if(count==pos)
        {
            prev->next = newn;
            newn->next = curr;
            return head;
        }
    else
    {
    printf("INVALID POSITION\n");
    return head;
    }
}
}
NODE delete_front(NODE head)
{
   NODE  p = head;
   if(head == NULL)
   {
      printf("List is empty\n");
      return head;
   }
head = p->next;
   printf("Deleted element is %d" , p->data);
   free(p);
   return head;
}
NODE delete(NODE head, int pos)
{
   NODE q, p = head;
   int c = 1;
   if(head == NULL)
   {
      printf("List is empty\n");
      return head;
   }
   if(pos == 1)
   {
      printf("Deleted element:%d\n",p->data);
      head = p->next;
      free(p);
      return head;
   }
   else
   {
   while(p!=NULL && c!=pos)
   {
      q = p;
      p = p->next;
      c++;
   }
   if(c == pos)
   {
      q->next = p->next;
   printf("Deleted element:%d",p->data);
      free(p);
      return head;
   }
}
}         
NODE delete_end(NODE head)
{
   NODE p = head;
   NODE q;
   if(head == NULL)
   {
     printf("List is empty\n");
     return head;
     }
   while(p->next!=NULL)
   {
      q = p;
      p = p->next;
   }
   printf("Deleted element: %d",p->data);
   free(p);
   q->next = NULL; 
   return head;
}
void display(NODE head)
{
NODE p;
if(head == NULL)
{
printf("List is Empty\n");
return;
}
printf("Linked List Contents are: \n");
p = head;
while(p!=NULL)
{
printf("%d\n",p->data);
p=p->next;
}
return;

}
int main()
{
int c,item,pos;
NODE head = (NODE)malloc(sizeof(struct node));
printf("Enter value of first element:\n");
scanf("%d",& item);
head->data = item;
c=1;
while(c!=0)
{
printf("\nEnter 0 to EXIT\nENTER 1 TO INSERT AT FRONT\nENTER 2 TO INSERT AT END\nENTER 3 TO INSERT AT A POSITION\nENTER 4 TO DISPLAY\n");
printf("Enter 5 to DELETE AT FRONT\nEnter 6 to DELETE AT END\nEnter 7 to DELETE AT SPECIFIC POSITION\n");
scanf("%d",&c);
switch(c)
{
case 0:break;
case 1: printf("Enter the item:\n");
        scanf("%d",&item);
 head = insertfront(item,head);
        break;
case 2: printf("Enter the item:\n");
        scanf("%d",&item);
        insertend(head,item);
        break;
case 3: printf("Enter the position:\n");
        scanf("%d",&pos);
        printf("Enter the item:\n");
        scanf("%d",&item);
        head = insertpos(head,item,pos);
        break;
case 4: display(head);
        break;
case 5: head = delete_front(head);
        break;
case 6: head = delete_end(head);
        break;
case 7: printf("Enter the position\n");
        scanf("%d",&pos);
        head = delete(head, pos);
        break;  
default: printf("Invalid Entry\n");
}
}
}
