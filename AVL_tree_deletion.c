#include<stdlib.h>
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
int height(struct atree* t)
{
    if(t==NULL)
        return 0;
    return(t->height);
}
struct atree* create(int data)
{
    struct atree* t1;
    t1=(struct atree*)malloc(sizeof(struct atree));
    t1->data=data;
    t1->left=t1->right=NULL;
    t1->height=1;
    return t1;
};
struct atree* leftrotation(struct atree* t)
{
    struct atree*x,*y;
    x=t->right;
    y=x->left;
    x->left=t;
    t->right=y;
    x->height=max(height(x->left),height(x->right))+1;
    t->height=max(height(t->left),height(t->right));
    return x;
};
struct atree* rightrotation(struct atree* t)
{
    struct atree* x,*y;
    x=t->left;
    y=x->right;
    x->right=t;
    t->left=y;
    x->height=max(height(x->left),height(x->right));
    t->height=max(height(t->left),height(t->right));
    return x;
};
int balance(struct atree* t)
{
    if(t==NULL)
        return 0;
    return(height(t->left)-height(t->right));
}
struct atree* insert(struct atree* t,int data)
{
    if(t==NULL)
        return(create(data));
    else if(data<t->data)
    {
        t->left=insert(t->left,data);

    }
    else if(data>t->data)
    {
        t->right=insert(t->right,data);

    }
    else
    {
        return(t);
    }
    t->height=max(height(t->left),height(t->right))+1;
    int a=balance(t);
    if(a>1&&data<t->left->data)
        return(rightrotation(t));
    if(a<-1&&data>t->right->data)
        return(leftrotation(t));
    if(a>1&&data>t->left->data)
    {
        t->left=leftrotation(t->left);
        return(rightrotation(t));
    }
    if(a<-1&&data<t->right->data)
    {
        t->right=rightrotation(t->right);
        return(leftrotation(t));
    }
    return(t);
};
struct atree* minvaluenode(struct atree* n)
{
    struct atree* t;
    t=n;
    while(t->left!=NULL)
        t=t->left;
    return t;
};
struct atree* deleten(struct atree* t,int data)
{
    if(t==NULL)
        return t;
    if(data<t->data)
        t->left=deleten(t->left,data);
    else if(data>t->data)
        t->right=deleten(t->right,data);
    else
    {
        if(t->left==NULL||t->right==NULL)
        {
            struct atree* temp=t->left?t->left:t->right;
            if(temp==NULL)
            {
                temp=t;
                t=NULL;
            }
            else
            {
                *t=*temp;
                free(temp);
            }
        }
        else
        {
            struct atree* temp=minvaluenode(t->right);
            t->data=temp->data;
            t->right=deleten(t->right,temp->data);
        }
    }
    if(t==NULL)
        return t;
    t->height=max(height(t->left),height(t->right))+1;
    int a=balance(t);
    if(a>1&&balance(t->left)>=0)
    {
        return(rightrotation(t));
    }
    if(a>1&&balance(t->left)<0)
    {

        t->left=leftrotation(t->left);
        return(rightrotation(t));
    }
    if(a<-1&&balance(t->right)<=0)
    {
        return(leftrotation(t));
    }
    if(a<-1&&balance(t->right)>0)
    {
        t->right=rightrotation(t->right);
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
    t=deleten(t,20);
    PreOrder(t);
    printf(" hello");
    return 1;
}
