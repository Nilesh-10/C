#include<stdlib.h>
#include<stdio.h>
struct atree
{
    int data;
    struct atree*left,*right;
    int height;
};
int max(int a,int b)
{
    return a>b?a:b;
}
int height(struct atree* t1)
{
    if(t1==NULL)
        return 0;
    return(t1->height);
}
struct atree* leftrotation(struct atree* t1)
{
    struct atree*x,*y;
    x=t1->right;
    y=x->left;
    x->left=t1;
    t1->right=y;
    x->height=max(height(x->left),height(x->right))+1;
    t1->height=max(height(t1->left),height(t1->right));
    return x;
}
struct atree* rightrotation(struct atree* t1)
{
    struct atree* a,*b;
    a=t1->left;
    b=a->right;
    a->right=t1;
    t1->left=b;
    a->height=max(height(a->left),height(a->right));
    t1->height=max(height(t1->left),height(t1->right));
    return a;

};
struct atree* newnode(int data)
{
    struct atree* t2;
    t2=(struct atree*)malloc(sizeof(struct atree));
    t2->data=data;
    t2->left=NULL;
    t2->right=NULL;
    t2->height=1;
    return t2;
};
int balance(struct atree* t1)
{
    if (t1==NULL)
        return 0;
    return (height(t1->left)-height(t1->right));
}
struct atree* insert(struct atree* t,int data)
{
    int a;
    if(t==NULL)
        return(newnode(data));
        else if(data<t->data)
        {
            t->left=insert(t->left,data);
        }
        else if(data>t->data)
        {
            t->right=insert(t->right,data);
        }
        else
            return t;
        t->height=max(height(t->left),height(t->right))+1;
        a=balance(t);
        if(a>1&&data<t->left->data)
            return(rightrotation(t));
        if(a<-1&&data>t->right->data)
            return(leftrotation(t));
        if(a>1&&data>t->left->data){
            t->left=leftrotation(t->left);
        return(rightrotation(t));
        }
        if(a<-1&&data<t->right->data)
        {
            t->right=leftrotation(t->right);
            return(leftrotation(t));
        }
        return(t);
};
void PreOrder(struct atree* s)
{
    if(s)
    {
        printf(" %d",s->data);
        PreOrder(s->left);
        PreOrder(s->right);

    }
}
int main()
{

struct atree* t=NULL;
t=insert(t,15);
t=insert(t,20);
t=insert(t,25);
t=insert(t,10);
PreOrder(t);
    printf(" hello");
    return 1;
}
