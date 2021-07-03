#include<stdio.h>
#include<stdlib.h>
struct Edge{
int src;
int dest;
int w;
};
struct graph{
int v;
int e;
struct Edge* edge;
};
struct subset{
int parent;
int rank;
};
struct graph* create_graph(int v,int e)
{

    struct graph* g=(struct graph*)malloc(sizeof(struct graph));
    g->v=v;
    g->e=e;
    g->edge=(struct Edge*)malloc(sizeof(struct Edge)*g->e);
    return g;
};
int find(struct subset s[],int i)
{
    if(s[i].parent!=i)
        s[i].parent=find(s,s[i].parent);
    return s[i].parent;
}
void sort(struct graph* g)
{
    struct Edge temp;
    for(int i=1;i<g->e;i++)
    {
        for(int j=0;j<(g->e)-i;j++)
            if(g->edge[j].w>g->edge[j+1].w)
        {
            temp=g->edge[j];
            g->edge[j]=g->edge[j+1];
            g->edge[j+1]=temp;
        }
    }
}
void Union(struct subset s[],int x,int y)
{
    int xroot=find(s,x);
    int yroot=find(s,y);
    if(s[xroot].rank>s[yroot].rank)
        s[yroot].parent=xroot;
    else if(s[yroot].rank>s[xroot].rank)
        s[xroot].parent=yroot;
    else{
        s[yroot].parent=xroot;
        s[xroot].rank++;
    }
}
void kruskal(struct graph* g)
{
    int v=g->v;
    struct Edge result[v];
    int e=0;
    int i=0;
    sort(g);
    struct subset* s1=(struct subset*)malloc(sizeof(struct subset)*v);
    for(int i=0;i<v;++i)
    {
        s1[i].parent=i;
        s1[i].rank=0;
    }
    while(e<v-1&&i<g->e)
    {
        struct Edge next_edge=g->edge[i++];
        int x=find(s1,next_edge.src);
        int y=find(s1,next_edge.dest);
        if(x!=y){
            result[e++]=next_edge;
        Union(s1,x,y);
    }
}
printf("Following are the edges in the constructed MST\n");
    int minimumCost = 0;
    for (i = 0; i < e; ++i)
    {
        printf("%d -- %d == %d\n", result[i].src,
            result[i].dest, result[i].w);
        minimumCost += result[i].w;
    }
    printf("Minimum Cost Spanning tree : %d",minimumCost);
    return;
}
int main()
{
    int V = 4; // Number of vertices in graph
    int E = 5; // Number of edges in graph
    struct graph* graph = create_graph(V, E);

    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].w = 10;

    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].w = 6;

    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].w = 5;

    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].w = 15;

    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].w = 4;

    kruskal(graph);

    return 0;
}

