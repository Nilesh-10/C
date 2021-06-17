/*
 Stack is a linear data structure which follows a particular order in which the operations are performed.
 The order may be LIFO(Last In First Out) or FILO(First In Last Out).

 We are performing following operations on the stack-
 1. Push - Inserting data into stack.
 2. Pop - Removing data from stack.
 3. Peek - Viewing top element of data.
 4. Traverse - Viewing elements of the stack.
*/


#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int data;
    struct stack* next;
};
struct stack* start=NULL;

void peek()
{
    struct stack* s1;
    s1=start;
    if(start==NULL)
    {
        printf("\n""stack is empty.""\n");
    }
    else
    {
        printf("\n""Data:"" %d ",s1->data);
    }
}
void push()
{
    struct stack* s1;
    s1=(struct stack*)malloc(sizeof(struct stack));
    s1->next=start;
    printf("\n""Enter data=""\n");
    scanf("%d",&s1->data);
    start=s1;


}
void pop()
{
    struct stack* s1;
    s1=start;
    if(s1==NULL)
    {
        printf("\nStack is Empty\n");
        return;
    }
    start=s1->next;
    printf("\n""Deleted data="" %d ",s1->data);
    free(s1);

}
void traverse()
{
struct stack* t;
t=start;
if(t==NULL)
{
    printf("\nStack is Empty\n");
    return;
}
while(t!=NULL)
{
    printf(" %d",t->data);
    t=t->next;
}

}



int main()
{
    int a;
    while(1)
    {
        printf("\n");
        printf("1.peek your stack.\n");
        printf("2.push items to your stack.\n");
        printf("3.pop item from stack.""\n");
        printf("4.Traverse.\n");
        printf("5.Exit.\n");
        printf("Please Enter your choice.\n");
        scanf("%d",&a);
        switch(a)
        {
        case 1:
            peek();
            break;
        case 2:
            push();
            break;
        case 3:
            pop();
            break;
        case 4:
            traverse();
            break;
        case 5:
            exit(1);
        default:
            printf("\nWrong input\n");
        }
    }
    return 0;
}
