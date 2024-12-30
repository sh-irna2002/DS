#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*next;
};
struct node*front=NULL;
struct node*rear=NULL;
void enqueue(int value)
{
struct node*ptr;
ptr=(struct node*)malloc(sizeof(struct node));
ptr->data=value;
ptr->next=NULL;
if((front==NULL)&&(rear==NULL))
{
front=rear=ptr;
}
else
{
rear->next=ptr;
rear=ptr;
};
printf("Element is Inserted..");
}

int dequeue()
{
if(front==NULL)
{
printf("Queue is empty\n");
return -1;
}
else
{
struct node*temp=front;
int temp_data=front->data;
front=front->next;
free(temp);
return temp_data;
}
}
void display()
{
struct node*temp;
if((front==NULL)&&(rear==NULL))
{
printf("Queue is empty..\n");
}
else
{
printf("queue is...");
temp=front;
while(temp)
{
printf("%d\t",temp->data);
temp=temp->next;
}
printf("NULL...");
}
}  
int main()
{
int choice,value;
while(choice!=4)
{
printf("\n....Queue Operations.....\n");
printf("1.Enqueue\n");
printf("2.Dequeue\n");
printf("3.Display\n");
printf("4.Exit\n");
printf("\nEnter your choice...\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("Enter the values to enqueue...");
scanf("%d",&value);
enqueue(value);
break;
case 2:
printf("Dequeued Element:%d\n",dequeue());
break;
case 3:
display();
break;
case 4:
printf("Exit\n");
break;
default:
printf("Invalid choice...");
}
}
return 0;
}
