#include<stdlib.h>
#include<stdio.h>
struct listnode{
int vertexno;
struct listnode* next;
};
struct graph{
int v;
int e;
struct listnode* adj;
};
struct graph* adjlist(){
int x,y,i;
struct listnode* temp,*t;
struct graph* g;
g=(struct graph*)malloc(sizeof(struct graph));
printf("Enter no. of vertex and edges");
scanf("%d %d",&g->v,&g->e);
g->adj=(struct listnode*)malloc(sizeof(struct listnode)*g->v);
for(i=0;i<g->v;i++)
{
    g->adj[i].vertexno=i;
    g->adj[i].next=g->adj+i;
}
for(i=0;i<g->e;i++)
{
    printf("Enter src and dest node.\n");
    scanf("%d %d",&x,&y);
    temp=(struct listnode*)malloc(sizeof(struct listnode));
    temp->vertexno=y;
    temp->next=g->adj+x;
    t=g->adj+x;
    while(t->next!=g->adj+x)
        t=t->next;
    t->next=temp;
}
return g;
};
int main()
{
    struct graph* g1;
    g1=adjlist();
    return 1;
}
