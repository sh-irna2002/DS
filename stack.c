#include<stdio.h>
int s[100],element,size,top=-1,choice,i;
void push();
void pop();
void display();
int main()
{
int choice=1;
printf("\n stack with array:");
printf("\n enter the size of the stack(max 100):");
scanf("%d",&size);
while(choice<=4 && choice!=0)
{
printf("\n 1.push \n 2.pop \n 3.display \n 4.exit");
printf("\n enter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
push();
break;
case 2:
pop();
break;
case 3:
display();
break;
case 4:
 break;
default:
printf("invalid choice");
break;
}
}
}
void push()
{
if(top==size-1)
{
printf("\n stack is overflow");
}
else
{
printf("enter the element to push:");
scanf("%d",&element);
top++;
s[top]=element;
printf("\n inserted %d",element);
}
}
void pop()
{
if(top==-1)
{
printf(" \n stack is underflow");
}
else
{
printf("deleted %d",s[top]);
top--;
}
}
void display()
{
if(top>=0)
{
printf("\n stack elemets are given below:");
for(i=top;i>=0;i--)
{
printf("\n %d",s[i]);
}
}
else
{
printf("\n stack is empty");
}
}
