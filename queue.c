#include<stdio.h>
int q[100],element,size,front=-1,rear=-1,choice=1;
void enqueue();
void dequeue();
void display();
void main()
{
printf("\n queue with array:");
printf("\n enter the size of the stack(max 100):");
scanf("%d",&size);
do
{
printf("\n 1.enqueue \n 2.dequeue \n 3.display \n 4.exit");
printf("\n enter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
enqueue();
break;
case 2:
dequeue();
break;
case 3:
display();
break;
default:
printf("exit");
}
}while(choice<4);
}



void enqueue()
{
int item;

if(rear==size-1)
{
printf("queue is full");
}
else
{
printf("enter the elements to be inserted: \n");
scanf("%d",&item);
if((front==-1) && (rear==-1))
{
front=0;
}
rear=rear+1;
q[rear]=item;
}
}



void dequeue()
{
int item;
if(front==-1)
{
printf("queue is empty");
}
else
{

item=q[front];
if(rear==front)
{
rear=-1;
front=-1;
}
else
{
front=front+1;
printf("value deleted");
}
display();
}
}
void display()
{
if(front<=rear)
{
int j;
if((front==-1) && (rear==-1))
{
printf("queue is empty");
}
else
{
printf("\n the queue is \n");
for(j=front;j<=rear;j++)
{
printf(" \t %d",q[j]);
}
}
}
}
