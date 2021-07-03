#include<stdio.h>
#define INF 9999
#define MAX 10
void dijkstra(int g[MAX][MAX],int n,int start)
{
    int cost[MAX][MAX];int dist[MAX];int visited[MAX];
    int count;int minvalue;int nextnode;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(g[i][j]==0)
            cost[i][j]=INF;
            else
                cost[i][j]=g[i][j];
        }
    }
    for(int i=0;i<n;i++){
    dist[i]=cost[start][i];
    visited[i]=0;
    }
    dist[start]=0;
    visited[start]=1;
    count=1;
    while(count<n-1)
    {
        minvalue=INF;
        for(int i=0;i<n;i++)
        {
            if(dist[i]<minvalue&&!visited[i])
            {
                minvalue=dist[i];
                nextnode=i;
            }
        }
        visited[nextnode]=1;
        for(int i=0;i<n;i++)
        {

            if(minvalue+cost[nextnode][i]<dist[i]&&!visited[i])
            {
                dist[i]=minvalue+cost[nextnode][i];

            }
        }
        count++;
    }
     // Printing the distance
  for (int i = 0; i < n; i++)
    if (i != start) {
      printf("\nDistance from source to %d: %d", i, dist[i]);
    }
}
int main() {
  int Graph[MAX][MAX], i, j, n, u;
  n = 7;

  Graph[0][0] = 0;
  Graph[0][1] = 0;
  Graph[0][2] = 1;
  Graph[0][3] = 2;
  Graph[0][4] = 0;
  Graph[0][5] = 0;
  Graph[0][6] = 0;

  Graph[1][0] = 0;
  Graph[1][1] = 0;
  Graph[1][2] = 2;
  Graph[1][3] = 0;
  Graph[1][4] = 0;
  Graph[1][5] = 3;
  Graph[1][6] = 0;

  Graph[2][0] = 1;
  Graph[2][1] = 2;
  Graph[2][2] = 0;
  Graph[2][3] = 1;
  Graph[2][4] = 3;
  Graph[2][5] = 0;
  Graph[2][6] = 0;

  Graph[3][0] = 2;
  Graph[3][1] = 0;
  Graph[3][2] = 1;
  Graph[3][3] = 0;
  Graph[3][4] = 0;
  Graph[3][5] = 0;
  Graph[3][6] = 1;

  Graph[4][0] = 0;
  Graph[4][1] = 0;
  Graph[4][2] = 3;
  Graph[4][3] = 0;
  Graph[4][4] = 0;
  Graph[4][5] = 2;
  Graph[4][6] = 0;

  Graph[5][0] = 0;
  Graph[5][1] = 3;
  Graph[5][2] = 0;
  Graph[5][3] = 0;
  Graph[5][4] = 2;
  Graph[5][5] = 0;
  Graph[5][6] = 1;

  Graph[6][0] = 0;
  Graph[6][1] = 0;
  Graph[6][2] = 0;
  Graph[6][3] = 1;
  Graph[6][4] = 0;
  Graph[6][5] = 1;
  Graph[6][6] = 0;

  u = 0;
  dijkstra(Graph, n, u);

  return 0;

}
