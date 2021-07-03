#include<stdlib.h>
struct graph{
int v;
int e;
int** adj;
};

struct graph* adjgraph()
{
    int p,q,i;
    struct graph *g=(struct graph*)malloc(sizeof(struct graph));
    if(g==NULL)
    {
        printf("Error");
        return;
    }
    printf("Enter no.of vertices and no. of edges");
    scanf("%d %d",&g->v,&g->e);
    g->adj=malloc(sizeof(int)*(g->v));
    for(int i=0;i<g->v;i++)
        g->adj[i]=malloc(sizeof(int)*g->v);
    for(p=0;p<g->v;p++)
        for(q=0;q<g->v;q++){
        g->adj[p][q]=0;
        }
    printf("Enter node no. in pair that connects the edge");
    for(i=0;i<g->e;i++)
    {
        scanf("%d %d",&p,&q);
        g->adj[p][q]=1;
        g->adj[q][p]=1;
    }
    return g;
};
int main()
{
    struct graph*g1;
    g1=adjgraph();
    return 1;
}
