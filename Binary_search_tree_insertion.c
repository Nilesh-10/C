#include<stdio.h>
#include<stdlib.h>
struct tree
{
    int data;
    struct tree*left,* right;
};

struct tree* insert(struct tree* root,int data)
{
    struct tree* t1,*t2;
    t2=(struct tree*)malloc(sizeof(struct tree));
    t2->left=t2->right=NULL;
    t2->data=data;
    if(root==NULL)
    {
        root=t2;
        return root;

    }

    else
    {
        t1=root;
        while(t1!=NULL)
        {
            if(t1->data>data)
            {
                if(t1->left==NULL)

                {


                    t1->left=t2;
                    break;
                }

                t1=t1->left;
            }
            else if(t1->data<data)
            {
                if(t1->right==NULL)

                {
                    t1->right=t2;
                    break;
                }
                t1=t1->right;
            }
        }
    }

}
void PreOrder(struct tree* s)
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
    struct tree* t=NULL;
    t=insert(t,15);
    insert(t,20);
    insert(t,6);
    insert(t,30);
    PreOrder(t);
    return 0;
}
